# Enterprise Tracking Pipeline Design

## 背景

当前工作区相对 `origin/main` 引入了一条新的 Enterprise tracking 管线，目标是绕过 Unity `Update()` 频率限制，将 PICO 企业级 SDK / Runtime 获取到的高频 Head 和 Controller 数据直接写入本地文件，并通过 TCP 发送到 PC。

历史问题主要有三类：

- Legacy tracking 由 Unity `Update()` 入队，实际 TCP 发送频率约 80-90Hz。
- Enterprise Head 底层源数据可达到约 1024Hz，但之前没有稳定进入 TCP 高频发送链路。
- Controller 数据原先通过 ToBService Java 接口获取，存在路径长、频率受限、左手未连接仍写 `hasPose=true` 等问题。

## 总体目标

- Enterprise Head 和 Controller 在独立线程中采集，不受 Unity 主线程帧率限制。
- Direct TCP 发送线程直接消费 Enterprise 最新样本，尽量贴近采样频率。
- 采集频率和 TCP 发送频率同时输出到 `LogWindow` 和 `Debug.Log`，可通过 `adb logcat` 闭环验证。
- 本地落盘数据保留 `meta.json`、序号、时间戳、预测时间模式，便于后续离线分析。
- Controller 未连接或无效时明确输出 `hasPose=false`，避免上层误判零位姿为有效数据。

## 模块变更

### EnterpriseCollectionRecorder

新增 `Assets/Scripts/EnterpriseCollection/EnterpriseCollectionRecorder.cs`，负责 Enterprise 采集线程、Unity 对照采样、最新样本缓存和频率统计。

核心职责：

- 通过 `EnsureCreated()` 创建全局常驻采集器。
- 等待 Enterprise service bind 后自动开始采集。
- 在后台线程 `EnterpriseLoop()` 中按 `enterpriseSampleHz` 采集 Head / Controller。
- 使用 `maxRecordSeconds` 仅控制文件写入时长，不停止采样线程。
- 维护 latest Head / Controller cache，供 TCP direct 线程读取。
- 每秒输出 `Enterprise sample rate: head=... controller=... target=...`。

Head 获取路径：

- 调用 `PXR_EnterprisePlugin.Pxr_GetPredictedMainSensorState2(...)`。
- 默认 `predictTimeMode=sample_interval`，预测时间取上一次 Head 采样到本次采样的实际间隔。
- 可选 `useDynamicPredictedDisplayTimeForEnterpriseHead=true` 时使用 `PXR_Enterprise.GetPredictedDisplayTime()`。

Controller 获取路径：

- 调用 `PXR_Enterprise.GetControllerPose(predictTimeMs)`。
- `predictTimeMs` 为上一次 Controller 采样到本次采样的实际间隔。
- 首帧无上一帧，传 `0`。

有效性规则：

- Controller pose 为 `null` 时无效。
- `timestamp == 0` 且 pose 为 `0,0,0,0,0,0,1` 时无效。
- 无效 Controller 在存盘和 TCP 中均输出 `hasPose=false`。

### EnterpriseCollectionFileWriter

新增 `Assets/Scripts/EnterpriseCollection/EnterpriseCollectionFileWriter.cs`，负责异步写 JSONL。

输出目录：

```text
/storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/yyyyMMdd_HHmmss/
```

文件：

- `meta.json`
- `enterprise_head.jsonl`
- `enterprise_controller_pose.jsonl`
- `unity_head.jsonl`
- `unity_controller_pose.jsonl` 当前 Unity Controller 对照采样未启用，文件可能不存在。

`meta.json` 记录关键参数：

- `enterpriseSampleHz`
- `unitySampleHz`
- `maxRecordSeconds`
- `enterpriseHeadPredictTimeMode`
- `enterpriseControllerPredictTimeMode`
- `enterpriseControllerPoseOrder`

### TcpHandler

`Assets/Scripts/Network/TcpHandler.cs` 从 legacy `Update()` 发送扩展为 direct 发送链路。

关键变化：

- `_sendDatas` 从普通 `Queue` 改为 `ConcurrentQueue`。
- 新增后台线程 `OnTrackingThread()`。
- 新增 `EnterpriseDirectTrackingEnabled`，当前默认 `true`，direct 是否启用不再依赖 Head/Controller/Hand/Body 的组合判断。
- Direct 线程读取 `EnterpriseCollectionRecorder.TryGetLatestEnterpriseHeadForTcp(...)`。
- 如果 `TrackingData.ControllerOn == true`，同时读取 latest Enterprise Controller 并写入 `Tracking.value.Controller`。
- 使用 Head `sampleSeq` 判断是否有新样本，不再按 pose/status 内容去重。
- 使用 `_pendingDirectTrackingPackets` 做轻量背压，避免 TCP 队列堆积。
- 每秒输出 `TCP tracking send rate: ... mode=enterprise_direct pending=...`。

Direct TCP 数据结构保持原 `Tracking` 协议：

```json
{
  "functionName": "Tracking",
  "value": "{\"Head\":...,\"Controller\":...,\"timeStampNs\":...,\"appState\":...,\"Input\":...}"
}
```

Controller 字段示例：

```json
{
  "Controller": {
    "left": {
      "axisX": 0,
      "axisY": 0,
      "axisClick": false,
      "grip": 0,
      "trigger": 0,
      "primaryButton": false,
      "secondaryButton": false,
      "menuButton": false,
      "hasPose": false
    },
    "right": {
      "axisX": 0,
      "axisY": 0,
      "axisClick": false,
      "grip": 0,
      "trigger": 0,
      "primaryButton": false,
      "secondaryButton": false,
      "menuButton": false,
      "hasPose": true,
      "pose": "x,y,z,rx,ry,rz,rw",
      "status": 1,
      "timeStampNs": 123,
      "type": 1,
      "poseError": 0
    }
  }
}
```

注意：Enterprise pose API 不提供按键、摇杆、trigger 等输入数据，当前这些字段填默认值以保持协议兼容。

### TrackingData

`Assets/Scripts/TrackingData.cs` 保留 legacy 路径，并优先使用 latest Enterprise Head：

- Legacy 模式仍由 `Update()` 采集并入队。
- 当 direct 关闭或不可用时，仍可回退到 legacy。
- Head 会优先从 Enterprise latest cache 取，取不到再走 `PXR_System.GetPredictedMainSensorStateNew(...)`。

### PXR_EnterprisePlugin / PXR_Enterprise

`PXR_EnterprisePlugin` 扩展了 Head / Controller 的获取能力。

Head：

- 增加对 `PICO_GetPredictedMainSensorState2` / `Pxr_GetPredictedMainSensorState2` 的封装。
- 采集器直接调用该 native 接口获取更高频 Head。

Controller：

- 新增 `PXR_Enterprise.GetControllerPose(double predictTime)`。
- `PXR_EnterprisePlugin.GetControllerPose(double predictTime)` 优先走 runtime native：

```csharp
PXR_Plugin.Controller.UPxr_GetControllerTrackingState(...)
```

- Runtime native 失败后回退到 `EnterprisePoseBridge.getControllerPoseJson(...)`。
- Bridge 失败后再回退到 ToBService `getControllerPose(...)`。

新增 `PoseInfo` 模型统一承载 Java / JSON / Runtime native 返回数据：

- `timestamp`
- `x/y/z`
- `rw/rx/ry/rz`
- `type`
- `confidence`
- `poseError`

### EnterprisePoseBridge

新增 Android Java bridge：

```text
Assets/Plugins/Android/src/main/java/com/xrobotoolkit/enterprise/EnterprisePoseBridge.java
```

用途：

- 通过反射适配不同 ToBService 实现。
- 支持 direct Java 方法和 `pbsCommonMessageLocked` fallback。
- 输出 JSON，降低 Unity C# 侧直接处理复杂 Java 返回类型的风险。
- 输出 profiling 日志，用于定位 binder / direct / common message / JSON 序列化耗时。

### LogWindow

`LogWindow` 改为线程安全：

- 非主线程调用时先进入 `ConcurrentQueue`。
- 主线程 `Update()` 中 flush。

这是 Enterprise 采集线程和 TCP 发送线程可以安全调用 `LogWindow.Info/Warn/Error` 的前提。

### UI 和场景

新增 `EnterpriseSampleRateUI`：

- 支持通过 UI 增减 `enterpriseSampleHz`。
- 默认 step 为 50。
- 显示当前 Enterprise 采样目标频率。

`Assets/Main.unity` 有对应 UI 元素和脚本挂载改动。

`Main.Awake()` 中调用：

```csharp
EnterpriseCollectionRecorder.EnsureCreated();
```

`UIOperate.OnBindEnterpriseService(...)` 中通知采集器 service bind 状态。

`InteractionModeManager` 增加输入设备切换日志，便于定位手柄/手势状态变化导致的数据源切换。

## 运行链路

### 采集链路

```text
Enterprise service bind
  -> UIOperate.NotifyEnterpriseServiceBound
  -> EnterpriseCollectionRecorder.TryAutoStart
  -> EnterpriseLoop
  -> Pxr_GetPredictedMainSensorState2 / GetControllerPose
  -> JSONL file writer
  -> latest Head / Controller cache
```

### TCP direct 链路

```text
TCP connected + ConnectInit completed
  -> OnTrackingThread
  -> TryGetLatestEnterpriseHeadForTcp
  -> optional TryGetLatestEnterpriseControllerForTcp
  -> Pack Tracking JSON
  -> _sendDatas ConcurrentQueue
  -> OnSendThread Socket.Send
  -> TCP tracking send rate log
```

### Legacy fallback 链路

```text
EnterpriseDirectTrackingEnabled=false
  -> Update()
  -> TrackingData.Get(...)
  -> _sendTrackingMsg
  -> OnSendThread
  -> mode=legacy
```

## 关键设计决策

### Direct 开关不再依赖 Tracking 组合状态

早期 direct 只在“只发 Head”时启用：

```text
HeadOn && !ControllerOn && !HandTrackingOn && TrackingType=None
```

这导致 Controller 开启后 TCP 退回 legacy，发送频率回到 80-90Hz。

当前改为：

```text
SendTrackingData && EnterpriseDirectTrackingEnabled
```

后续可以把 `EnterpriseDirectTrackingEnabled` 接到 UI 开关。

### 不再按 pose/status 内容去重

早期 direct 发送曾按 Head pose/status 内容去重，导致采样有新帧但 pose 字符串相同时不发送。

当前使用采样序号 `sampleSeq`：

- Enterprise Head 每成功采样一次递增。
- TCP direct 只要看到新的 `sampleSeq` 就发包。

这样 TCP 发送频率更接近采样频率。

### maxRecordSeconds 只控制落盘

`maxRecordSeconds` 不再停止采样线程。

原因：

- 文件记录可以有时间上限。
- TCP 发送和 latest cache 需要持续更新。

到达时间上限后仅停止 `EnterpriseCollectionFileWriter`。

### predictTime 使用 sample interval

Head 和 Controller 默认均使用上一次采样到本次采样的实际间隔作为 predictTime。

原因：

- 固定 `0` 或显示预测时间不等价于采样间隔。
- Controller 在高频轮询时容易出现重复值，需要明确控制预测时间来源。

## 验证方法

### logcat 关键字

```powershell
adb logcat | findstr /i "Enterprise sample rate TCP tracking send rate enterprise direct gate controller state"
```

重点看：

- `Enterprise sample rate: head=... controller=... target=...`
- `TCP tracking send rate: ... mode=enterprise_direct pending=...`
- `TCP enterprise direct gate changed: ready=True ...`
- `controller state source=enterprise side=... hasPose=...`

### 本地拉取数据

保存目录：

```text
/storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/
```

拉取最新目录可参考：

```text
Docs/enterprise_collection_data_guide.md
```

### 已观察到的现象

- Enterprise Head 目标 1000Hz 时，实际采样常见约 900Hz 以上。
- TCP direct 生效后，发送模式应持续为 `enterprise_direct`。
- Controller 实际有效 pose 更新频率可能低于采样频率，高频轮询会出现重复 pose。
- 未连接左手柄时，native 可能返回零位姿；当前会被标记为 `hasPose=false`。

## 风险和待处理项

- `PXR_EnterprisePlugin.cs` 文件头存在 BOM/编码噪音，提交前建议单独检查，避免无关 diff。
- `ProjectSettings.asset` 中包含版本号和 keystore 配置变化，需确认是否应纳入本次提交。
- `Assets/Main.unity` 改动较大，主要是 UI 挂载和场景对象变化，建议提交前用 Unity 打开确认引用完整。
- `PulledData/` 是本地调试数据，不应提交。
- Controller direct TCP 当前只发送 pose，按键/摇杆字段为默认值。如果 PC 端需要真实输入，需要继续从 Unity Input 或其它企业接口补齐。
- Direct 发送包体加入 Controller 后包更大，需要持续观察 `pending` 是否升高以及 `TCP tracking send rate` 是否下降。
- Runtime native controller timestamp 曾观察到重复和倒退，发送去重不应依赖 controller timestamp。

## 建议提交拆分

建议整理为以下提交：

1. Enterprise service / bridge / PoseInfo 基础能力。
2. EnterpriseCollectionRecorder 和 FileWriter 落盘采集能力。
3. TCP direct 高频发送链路。
4. Controller runtime native 接入和 TCP Controller 扩展。
5. UI、LogWindow 线程安全和诊断日志。
6. 场景与 ProjectSettings 配置变更，单独确认后提交。
