package com.xrobotoolkit.enterprise;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.nio.ByteBuffer;

/**
 * Adapts the optional ToB EyeTrackingManager without changing the bundled SDK.
 * The existing Unity enterprise service binding owns the connection.
 */
public final class EnterpriseEyeFrameBridge {
    public static final int WAITING = 0;
    public static final int READY = 1;
    public static final int CAPTURING = 2;
    public static final int STOPPED = 3;
    public static final int UNAVAILABLE = 4;
    public static final int ERROR = 5;

    private static final String HELPER_CLASS = "com.pvr.tobservice.ToBServiceHelper";
    private static final int FIRST_CAMERA_ID = 15;
    private static final int CAMERA_COUNT = 4;
    private static final int MAX_FRAME_BYTES = 1024 * 1024;
    private static final int OUTPUT_FPS = 30;
    private static final long PREVIEW_INTERVAL_NS = 1000000000L / 15L;

    private final Object frameLock = new Object();
    private final Channel[] channels = new Channel[CAMERA_COUNT];
    private volatile int state = WAITING;
    private volatile String status = "Waiting for the enterprise service.";
    private boolean capturing;
    private long generation;
    private boolean stopPending;
    private boolean captureRequested;
    private boolean listenerAttached;
    private Object manager;
    private Object listener;
    private Method setListener;
    private Method startMethod;
    private Method stopMethod;
    private Method configMethod;
    private Class<?> configClass;
    private Class<?> listenerClass;
    private Accessor dataAccessor;
    private Accessor idAccessor;
    private Accessor widthAccessor;
    private Accessor heightAccessor;
    private Accessor timestampAccessor;

    public EnterpriseEyeFrameBridge() {
        for (int i = 0; i < channels.length; i++) {
            channels[i] = new Channel(this);
        }
    }

    public synchronized boolean prepare() {
        if (manager != null) {
            return state == READY || state == STOPPED;
        }
        try {
            Class<?> helperClass = Class.forName(HELPER_CLASS);
            Object helper = helperClass.getMethod("getInstance").invoke(null);
            Object candidate = new Accessor(helperClass, "eyeTrackingManager").get(helper);
            if (candidate == null) {
                throw new IllegalStateException("EyeTrackingManager is null after service binding.");
            }
            Class<?> managerClass = candidate.getClass();
            Method candidateStart = managerClass.getMethod("startCapture");
            // Do not open a camera unless this client can also close it.
            Method candidateStop = managerClass.getMethod("stopCapture");
            Method candidateConfig = null;
            Method candidateListener = null;
            for (Method method : managerClass.getMethods()) {
                if (method.getName().equals("setConfig") && method.getParameterTypes().length == 1) {
                    candidateConfig = method;
                }
                if (method.getName().equals("setListener") && method.getParameterTypes().length == 1
                        && method.getParameterTypes()[0].isInterface()) {
                    candidateListener = method;
                }
            }
            if (candidateListener == null) {
                throw new NoSuchMethodException("setListener(EyeTrackingListener interface)");
            }
            if (candidateConfig == null) {
                throw new NoSuchMethodException("setConfig(EyeOutputConfig)");
            }
            Class<?> outputConfigClass = candidateConfig.getParameterTypes()[0];
            outputConfigClass.getConstructor();
            if (outputConfigClass.getField("targetFps").getType() != int.class) {
                throw new IllegalStateException("EyeOutputConfig.targetFps must be int.");
            }
            Class<?> callbackClass = candidateListener.getParameterTypes()[0];
            Class<?> frameClass = null;
            boolean hasError = false;
            for (Method method : callbackClass.getMethods()) {
                if (method.getName().equals("onFrameAvailable") && method.getParameterTypes().length == 1
                        && method.getReturnType() == void.class) {
                    frameClass = method.getParameterTypes()[0];
                } else if (method.getName().equals("onError")
                        && method.getParameterTypes().length == 1
                        && method.getParameterTypes()[0] == int.class
                        && method.getReturnType() == void.class) {
                    hasError = true;
                }
            }
            if (frameClass == null || !hasError) {
                throw new NoSuchMethodException("onFrameAvailable(EyeFrame) / onError(int)");
            }
            dataAccessor = new Accessor(frameClass, "data");
            Class<?> dataType = dataAccessor.getType();
            if (dataType != byte[].class && !ByteBuffer.class.isAssignableFrom(dataType)) {
                throw new IllegalStateException("Unsupported EyeFrame.data type: " + dataType.getName()
                        + ". A native pointer requires an SDK copy API.");
            }
            idAccessor = new Accessor(frameClass, "id");
            widthAccessor = new Accessor(frameClass, "width");
            heightAccessor = new Accessor(frameClass, "height");
            timestampAccessor = new Accessor(frameClass, "timestamp");
            listenerClass = callbackClass;
            setListener = candidateListener;
            startMethod = candidateStart;
            stopMethod = candidateStop;
            configMethod = candidateConfig;
            configClass = outputConfigClass;
            manager = candidate;
            state = READY;
            status = "EyeFrame API available. Output=30 Hz; preview<=15 Hz; packed Gray8 only.";
            return true;
        } catch (Throwable error) {
            manager = null;
            state = UNAVAILABLE;
            status = "EyeFrame API unavailable in the bundled ToB client: " + describe(error)
                    + ". Request a compatible AAR and the frame format/stop signature from the SDK owner.";
            return false;
        }
    }

    public synchronized boolean startCapture() {
        refresh();
        if (captureRequested || listenerAttached) {
            status = "Previous EyeFrame capture needs a successful Stop before restarting.";
            state = ERROR;
            return false;
        }
        if (manager == null && !prepare()) {
            return false;
        }
        final long session;
        synchronized (frameLock) {
            clearFrames();
            session = ++generation;
            capturing = true;
            stopPending = false;
            state = CAPTURING;
            status = "Capturing; waiting for the first EyeFrame.";
        }
        try {
            Object config = configClass.getConstructor().newInstance();
            configClass.getField("targetFps").setInt(config, OUTPUT_FPS);
            Object configured = configMethod.invoke(manager, config);
            if (!succeeded(configured)) {
                fail(session, "setConfig(targetFps=" + OUTPUT_FPS + ") returned " + configured
                        + "; verify the enterprise service supports EyeFrame configuration.");
                refresh();
                return false;
            }
            listener = Proxy.newProxyInstance(listenerClass.getClassLoader(),
                    new Class<?>[] {listenerClass}, (proxy, method, args) -> {
                        if (method.getDeclaringClass() == Object.class) {
                            if (method.getName().equals("hashCode")) {
                                return System.identityHashCode(proxy);
                            }
                            if (method.getName().equals("equals")) {
                                return args != null && args.length == 1 && proxy == args[0];
                            }
                            return "XRoboToolkit EyeTrackingListener";
                        }
                        if (method.getName().equals("onFrameAvailable") && args != null && args.length == 1) {
                            receiveFrame(session, args[0]);
                        } else if (method.getName().equals("onError") && args != null && args.length == 1) {
                            fail(session, "EyeTrackingListener.onError: " + args[0]);
                        }
                        return null;
                    });
            // Mark attempts before invocation so partial SDK failures are cleaned up.
            listenerAttached = true;
            Object registration = setListener.invoke(manager, listener);
            if (!succeeded(registration)) {
                fail(session, "setListener returned " + registration);
            }
            boolean active;
            synchronized (frameLock) {
                active = capturing && session == generation;
            }
            if (!active) {
                refresh();
                return false;
            }
            captureRequested = true;
            Object result = startMethod.invoke(manager);
            if (!succeeded(result)) {
                String reason = "startCapture returned " + result;
                if (result instanceof Number && ((Number) result).intValue() == -1) {
                    reason += "; check service readiness, device support and enterprise enableET authorization.";
                }
                fail(session, reason);
            }
        } catch (Throwable error) {
            fail(session, "startCapture failed: " + describe(error));
        }
        refresh();
        return state == CAPTURING;
    }

    /** Runs SDK cleanup on Unity's polling thread, never inside a native callback. */
    public synchronized void refresh() {
        boolean pending;
        synchronized (frameLock) {
            pending = stopPending;
            stopPending = false;
        }
        if (pending) {
            cleanup();
        }
    }

    public synchronized void stopCapture(String reason) {
        synchronized (frameLock) {
            capturing = false;
            ++generation;
            stopPending = false;
            clearFrames();
        }
        if (cleanup()) {
            state = manager == null ? WAITING : STOPPED;
            status = "EyeFrame capture stopped: " + reason;
        }
    }

    public synchronized void serviceDisconnected() {
        stopCapture("enterprise service disconnected");
        // Retain the manager if cleanup failed, so the next explicit Stop can retry.
        if (!captureRequested && !listenerAttached) {
            manager = null;
            state = WAITING;
            status = "Waiting for the enterprise service.";
        }
    }

    public synchronized void dispose() {
        stopCapture("disposed");
        synchronized (frameLock) {
            for (Channel channel : channels) {
                for (Frame frame : channel.pool) {
                    if (!frame.leased) {
                        frame.data = null;
                    }
                }
            }
        }
    }

    public int getState() {
        return state;
    }

    public String getStatus() {
        return status;
    }

    /** The caller must release this lease after copying its data across JNI. */
    public Frame acquireFrame(int cameraId) {
        int index = cameraId - FIRST_CAMERA_ID;
        synchronized (frameLock) {
            if (!capturing || index < 0 || index >= channels.length) {
                return null;
            }
            Channel channel = channels[index];
            Frame frame = channel.latest;
            if (frame != null) {
                channel.latest = null;
                frame.leased = true;
            }
            return frame;
        }
    }

    private void receiveFrame(long session, Object source) {
        synchronized (frameLock) {
            if (!capturing || session != generation) {
                return;
            }
        }
        try {
            int id = ((Number) idAccessor.get(source)).intValue();
            int width = ((Number) widthAccessor.get(source)).intValue();
            int height = ((Number) heightAccessor.get(source)).intValue();
            long timestamp = ((Number) timestampAccessor.get(source)).longValue();
            int index = id - FIRST_CAMERA_ID;
            if (index < 0 || index >= channels.length) {
                fail(session, "Unsupported EyeFrame camera id: " + id + " (expected 15..18).");
                return;
            }
            long size = (long) width * height;
            if (width <= 0 || height <= 0 || width > 2048 || height > 2048
                    || size > MAX_FRAME_BYTES || timestamp <= 0) {
                fail(session, "Invalid EyeFrame dimensions/timestamp: " + width + "x" + height
                        + ", timestamp=" + timestamp);
                return;
            }
            synchronized (frameLock) {
                if (!capturing || session != generation) {
                    return;
                }
                Channel channel = channels[index];
                long now = System.nanoTime();
                if (timestamp <= channel.lastTimestamp || now < channel.nextCopyNs) {
                    return;
                }
                if (channel.width != 0 && (channel.width != width || channel.height != height)) {
                    fail(session, "EyeFrame dimensions changed during capture. Stop and start a new session.");
                    return;
                }
                Object data = dataAccessor.get(source);
                ByteBuffer bytes = data instanceof ByteBuffer ? ((ByteBuffer) data).duplicate() : null;
                int length = data instanceof byte[] ? ((byte[]) data).length
                        : bytes != null ? bytes.remaining() : -1;
                if (length != (int) size) {
                    fail(session, "EyeFrame data is not packed Gray8: " + width + "x" + height
                            + ", bytes=" + length + ". Confirm format and row stride with the SDK owner.");
                    return;
                }
                Frame target = null;
                for (Frame frame : channel.pool) {
                    if (!frame.leased && frame != channel.latest) {
                        target = frame;
                        break;
                    }
                }
                if (target == null) {
                    return;
                }
                if (target.data == null || target.data.capacity() != length) {
                    target.data = ByteBuffer.allocateDirect(length);
                }
                // SDK storage is valid only during the callback. Own the copy before returning.
                target.data.clear();
                if (bytes != null) {
                    target.data.put(bytes);
                } else {
                    target.data.put((byte[]) data);
                }
                target.data.flip();
                target.id = id;
                target.width = width;
                target.height = height;
                target.timestamp = timestamp;
                channel.latest = target;
                channel.lastTimestamp = timestamp;
                channel.nextCopyNs = now + PREVIEW_INTERVAL_NS;
                channel.width = width;
                channel.height = height;
            }
        } catch (Throwable error) {
            fail(session, "Invalid EyeFrame callback: " + describe(error));
        }
    }

    private void fail(long session, String message) {
        synchronized (frameLock) {
            if (session != generation || !capturing) {
                return;
            }
            capturing = false;
            ++generation;
            clearFrames();
            state = ERROR;
            status = message;
            stopPending = true;
        }
    }

    private boolean cleanup() {
        String errors = "";
        if (manager != null && captureRequested) {
            try {
                Object result = stopMethod.invoke(manager);
                if (!succeeded(result)) {
                    throw new IllegalStateException("stopCapture returned " + result);
                }
                captureRequested = false;
            } catch (Throwable error) {
                errors = "stopCapture failed: " + describe(error);
            }
        }
        if (manager != null && listenerAttached) {
            try {
                setListener.invoke(manager, new Object[] {null});
                listenerAttached = false;
                listener = null;
            } catch (Throwable error) {
                errors += (errors.isEmpty() ? "" : "; ") + "listener removal failed: " + describe(error);
            }
        }
        if (!errors.isEmpty()) {
            state = ERROR;
            status += "; " + errors;
            return false;
        }
        return true;
    }

    private void clearFrames() {
        for (Channel channel : channels) {
            channel.latest = null;
            channel.lastTimestamp = 0;
            channel.nextCopyNs = 0;
            channel.width = 0;
            channel.height = 0;
        }
    }

    private static boolean succeeded(Object result) {
        return result == null || Boolean.TRUE.equals(result)
                || result instanceof Number && ((Number) result).longValue() == 0;
    }

    private static String describe(Throwable error) {
        while (error instanceof InvocationTargetException && error.getCause() != null) {
            error = error.getCause();
        }
        return error.getClass().getSimpleName() + ": " + error.getMessage();
    }

    private static final class Accessor {
        private final Field field;
        private final Method getter;

        Accessor(Class<?> type, String name) throws ReflectiveOperationException {
            Field candidate = null;
            Method method = null;
            try {
                candidate = type.getField(name);
            } catch (NoSuchFieldException missingField) {
                method = type.getMethod("get" + Character.toUpperCase(name.charAt(0)) + name.substring(1));
            }
            field = candidate;
            getter = method;
        }

        Object get(Object target) throws ReflectiveOperationException {
            return field != null ? field.get(target) : getter.invoke(target);
        }

        Class<?> getType() {
            return field != null ? field.getType() : getter.getReturnType();
        }
    }

    private static final class Channel {
        final Frame[] pool;
        Frame latest;
        long lastTimestamp;
        long nextCopyNs;
        int width;
        int height;

        Channel(EnterpriseEyeFrameBridge owner) {
            pool = new Frame[] {new Frame(owner), new Frame(owner), new Frame(owner)};
        }
    }

    public static final class Frame {
        private final EnterpriseEyeFrameBridge owner;
        private ByteBuffer data;
        private int id;
        private int width;
        private int height;
        private long timestamp;
        private boolean leased;

        private Frame(EnterpriseEyeFrameBridge owner) {
            this.owner = owner;
        }

        public ByteBuffer getBuffer() { return data; }
        public int getId() { return id; }
        public int getWidth() { return width; }
        public int getHeight() { return height; }
        public long getTimestamp() { return timestamp; }

        public void release() {
            synchronized (owner.frameLock) {
                leased = false;
            }
        }
    }
}
