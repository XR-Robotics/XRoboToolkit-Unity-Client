package com.example.androidplugin;

import android.util.Log;

public class PluginInstance {
    private static final String TAG = "UnityAndroidPlugin";

    public static String getMessage() {
        Log.d(TAG, "getMessage called from Unity");
        return "Hello from Android Plugin!";
    }

    public static int add(int a, int b) {
        Log.d(TAG, "add called from Unity: " + a + " + " + b);
        return a + b;
    }
}
