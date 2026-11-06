# UI 改造与远端业务行为对比

日期：2026-11-06。结论：**原有 UI 控件绑定与业务生命周期保持，但当前全部差异不满足“仅影响 UI、不影响业务”的要求；发现 3 项 P1 业务问题。**

## 对比范围

已执行 `git fetch origin`，基准为 `origin/EnterpriseSDK`：
`93c6072912788277e1341c32a4020467e5a93830`。
本地 HEAD 为 `063d33426c8c9dfea12ee15bcc89201ae3bb8fa4`，领先远端两个提交。
对比包含已提交及当前工作区改动，相关未跟踪验证脚本作为上下文检查。

两个提交分别是 SDK 6.1.1 迁移（`cb4f3b1`）和 EyeTracking/EyeFrame 功能及 UI（`063d334`）。
应用和配置范围共 52 个变更文件、14,528 行增删，另核对相关 SDK 原生声明、事件解析和插件 importer。未对整个 SDK 导入做完整审计。

环境为 Unity 2022.3.16f1、PICO XR；活动包为 `com.bytedance.pico.xr`，路径 `file:../PICO Unity SDK`，版本 6.1.1。

## UI 改造保持的行为

| 检查项 | 远端与本地对比结果 |
| --- | --- |
| 原有场景对象 | 1,840 个原对象 ID 全部保留；新增 306 个，未删除原对象；内部悬空引用为 0 |
| 持久化事件 | 对比 429 个事件组件、17 条调用记录，变化为 0 |
| 原有按钮和开关 | 25 个 Button、19 个 Toggle 的启用、可交互及开关默认值保持 |
| 应用组件字段 | 42 个原应用组件中，33 个字段完全相同；7 个 CustomButton 仅增加外观字段；Main、UIOperate 增加字段 |
| 布局重挂父节点 | 27 处调整没有给原先启用的业务组件新增 inactive 祖先 |
| Toggle 射线背景 | 11 个换肤 Toggle 保留启用的射线命中背景 |
| EyeTracking 翻页 | 用 CanvasGroup 隐藏主页面，未停用 UIOperate、TCP、相机和数据源控制组件 |
| 双页眼动开关 | 共用一个数据源，通过不触发回调的赋值同步，未引入递归启停 |
| EyeFrame 侧板关闭 | 只停止 EyeFrame；未调用原有 TCP 或录制的停止入口 |
| 既有协议及采集防护 | TCP 协议和序列化文件无变化；手柄 Runtime-first、预测时间 0、位姿过滤和活动输入校验保留 |

代码证据：`EyeGazePageNavigation.cs:26-46`、`EyeGazeToggle.cs:14-51`、
`EnterpriseEyeFramePreview.cs:164-198`、`Main.unity:38755-38788`。
这些证明结构和控制路径保持，不等同于完成实际点击、遮挡或设备性能验证。

## 需要处理的业务问题

### 1. P1：VST 默认由关闭改为开启

置信度：10/10。位置：`Assets/Main.unity:26106`。

```yaml
enableVstCamera: 1
```

远端场景没有该字段，使用 `Main.cs:13` 的缺省 `false`。
本地新增的场景值由 `Main.cs:25` 的 Awake、`:42` 的 OnEnable 及 `:64` 的恢复路径消费，改变启动和恢复时的 VST 策略。该变化超出 UI 布局及 SDK API 适配。

建议：如需保持远端行为，将该值恢复为 `false`；如需默认开启，应明确作为业务变化记录。本次未证明新的 VST 内存泄漏。

### 2. P1：PC 相机参数请求仍依赖已禁用的原生库

置信度：9/10。变更位置：`PICO Unity SDK/Enterprise/android/CameraRenderingPlugin.aar.meta:18-19`。
业务入口：`Assets/Scripts/UI/UICameraCtrlPC.cs:80-86`。

```csharp
string cameraExtrinsics = Utils.GetCameraExtrinsicsStrE();
string cameraIntrinsics = Utils.GetCameraIntrinsicsStrE(width, height);
```

新 SDK 对应实现直接调用：

```csharp
[DllImport("CameraRenderingPlugin")]
public static extern bool getCameraExtrinsics(...);
```

Android importer 已禁用该库，但 GetCameraParam 请求仍经 Utils 调用 SDK 内外参接口，且没有原生失败后的明确回复路径，因此可能因库加载失败中断回包。预览和录制继续使用独立的应用相机链路，不能据此证明参数请求正常。

建议：把内外参获取适配到保留的应用相机实现，并对不支持或读取失败明确回包。保留 `capturelib-0.0.7.aar` 路径；不要直接重新启用与其存在 JNI ABI 冲突的 SDK 相机库。

### 3. P1：追踪器完成事件可能用截断 ID 覆盖缓存

置信度：9/10。位置：`Assets/Scripts/PicoMotionTrackerDevices.cs:40-43`。
依赖证据：`PICO Unity SDK/Runtime/Scripts/PXR_Loader.cs:808`。

```csharp
requestMotionTrackerCompleteEventData.trackerIds[i] =
    BitConverter.ToInt16(eventDB.data, 8 + 8 * i);
```

完成回调先清空缓存，再接收 SDK 解析出的 trackerIds；这里以 8 字节间隔读取 ID，却只读取有符号 16 位。相同 SDK 的连接事件读取完整 Int64。
合成验证显示 `40000` 会变成 `-25536`，从而污染后续设备查询和标识缓存。
真机是否分配超出该范围的 ID 尚未验证；问题在此类 ID 条件下触发。

建议：按完整 Int64 解析事件 ID，核对本地事件布局和返回码偏移；覆盖缓存前确认 ID 一致，保留协议中的字符串标识字段。

## 其他明确的非 UI 改动

- EyeTracking 新增原生眼动采集、服务生命周期、坐标转换及诊断；EyeFrame 新增相机采集，配置 30 Hz 采集、最高 15 Hz 预览。未将这些新数据接入原有 TCP 眼动协议或录制文件。
- Motion 和外设由旧硬件 SN 改为数值设备 ID 的十进制字符串。字段类型保持，但标识值语义变化，旧接收端和映射配置需适配。
- Body Tracking 改用新版关节集接口，原 LOW/HIGH 独立选择行为不再保留。
- USB 共享网络和 VST 改用新版 SDK 适配路径；这些属于原生调用变化。
- 输入配置调整 20 个既有绑定，新增 10 个模拟绑定，无既有绑定删除。手势射线改用 pointer/position、pointer/rotation，UI Press 改用 pointerActivated。
- 本地未提交的手势按钮修正把七个 BYTE 按钮写为 255/0，改变输入事件数值和点击识别。
- 包引用、宏、Android 签名开关、Manifest 及构建版本参数回退变化，属于运行/构建配置。

## 审查与验证限制

本次采用静态 diff、完整直接相关方法、场景对象与持久化事件比较、输入 JSON 稳定 ID 对比及 SDK 声明检查，覆盖逻辑、业务语义、安全、并发、健壮性、性能和质量，并完成跨组接口核对。除上述 3 项外，未确认额外的 P0-P2 回归。

未运行 Unity 场景、编译、APK 构建、安装或真机回归。实际指针遮挡、相机参数回包、较大追踪器 ID、设备帧格式与持续采集性能仍需运行验证。旧验证记录不作为本次已执行的验证。

本次未修改源代码、场景或项目配置，未提交或推送。审查结果支持“换肤保留原业务控件绑定和生命周期”；不能支持“当前整个分支与远端业务完全一致”。
