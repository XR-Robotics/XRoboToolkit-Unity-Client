# PICO SDK 0.10.0-Preview 升级修改汇总记录

**文档说明**：
本文档记录了从旧版 PICO SDK 升级至 `0.10.0-Preview` 期间，我们对 **SDK 内部源码** 以及 **项目业务层代码** 所做的所有修改、适配和底层 Bug 绕过（Workaround）方案。
便于后续排查问题、复盘以及在未来再次升级 SDK 时作为参考。

---

## 1. SDK 内部源码修改 (SDK Internal Modifications)
*说明：直接修改了 PICO SDK 提供的源码，后续更新 SDK 版本时需要**重点注意重新应用这些修改**。*

### 1.1 [高危/重构] 修复大空间 Loading 阶段图层被误杀导致的死循环黑屏 (Ultimate Fix 3.0)
* **文件路径**：`Packages/PICO-Unity-SDK-0.10.0-Preview/Runtime/Scripts/Features/PXR_CompositionLayer.cs`
* **根因**：大空间初次加载时 CPU 极度卡顿，底层 C++ 异步分配图层耗时可能长达数秒。而 SDK C# 层硬编码的 `60 帧` 超时阈值太短，导致图层在建好前被强制销毁并重新请求创建，陷入无限循环。
* **修改方案**：
  * 在 `CreateTexture()` 的失败判定中，引入了**状态记忆机制 (`hasSucceededBefore`)**。
  * 如果是从未被成功创建过的图层（初次 Loading），给予长达 **600 帧**（十几秒）的超长宽限期，保证底层一定能建出来。
  * 如果是曾经成功过但突然失效的图层（运行时被 Native 禁用回收），仅容忍 **5 帧**，然后迅速触发重建（`needsRecreate = true`）。
  * 将 `InitializeBuffer` 和 `UPxr_DestroyLayerByRender` 的调用推迟到 `Update()` 生命周期中执行，避开渲染阶段（`OnPreRender`）与 Native 层的跨线程时序冲突。

### 1.2 修复 Unity 2021 编译兼容性问题
* **文件路径**：`Packages/PICO-Unity-SDK-0.10.0-Preview/Runtime/Scripts/SensePack/PXR_EnvironmentDepthManager.cs`
* **修改方案**：将已废弃的 `GetRenderTexture` 方法替换为 `GetRenderTextureForRenderPass`。
* **文件路径**：`Packages/PICO-Unity-SDK-0.10.0-Preview/Runtime/Scripts/SensePack/PXR_LightEstimationManager.cs`
* **修改方案**：将已废弃的 `RenderSettings.customReflectionTexture` 属性替换为 `RenderSettings.customReflection`。

---

## 2. 项目核心逻辑适配 (Project Logic Adaptations)
*说明：为了适配新版 SDK 接口和修复运行时异常，对项目自身脚本的修改。*

### 2.1 修复大空间建图文件锁死导致的无限 Loading
* **文件路径**：`Assets/Scripts/Data Layer/DataController.cs`
* **问题描述**：底层 `Pxr_DeleteMap` 接口在特定情况下失效且不返回结果，导致 `CheckIsMapCleared` 协程陷入死循环（无限转菊花）。
* **修改方案**：
  1. **主动文件删除**：绕过 SDK，直接使用 C# `System.IO.File.Delete` 删除大空间地图文件 (`.finchz`)。
  2. **增加超时熔断机制**：在 `CheckIsMapCleared` 的 `while` 等待循环中加入 5 秒超时逻辑，超过 5 秒强制跳出，防止主线程死锁。

### 2.2 修复图层实例集合被修改导致的异常
* **文件路径**：`Assets/Scripts/UI/Others/Loading UI/LoadingUIController.cs`
* **问题描述**：在遍历 `PXR_CompositionLayer.Instances` 时，若有图层被动态添加/删除，会抛出 `InvalidOperationException` (Collection modified during enumeration)。
* **修改方案**：在 `foreach` 遍历时添加 `.ToArray()`，对集合的快照进行遍历。

### 2.3 解决 Editor 模式下找不到动态链接库的报错
* **文件路径**：`Assets/Tob XR Tools/PICO Interaction Toolkit/Scripts/HandDevice.cs`
* **问题描述**：在 Unity 编辑器中运行报错 `DllNotFoundException: PxrPlatform`。
* **修改方案**：将涉及到 PICO SDK 底层调用的方法包在 `#if !UNITY_EDITOR` 预编译指令内，避免在 PC 端强行调用安卓 Native 库。

---

## 3. 废弃接口与 Dll 替换清单 (API & Dll Migration)
*说明：新版 SDK 规范了命名和接口封装，项目中的老旧 P/Invoke 调用被重构。*

### 3.1 动态库名称变更
* **文件路径**：`Assets/Scripts/Bridge Layer/DllFunctionManager.Android.cs`
* **修改方案**：将 `PXR_API_DLL_NAME` 常量由旧版的 `"pxr_api"` 修改为新版的 `"PxrPlatform"`。修复了上机后大面积 `DllNotFoundException`。

### 3.2 命名空间冲突处理
* **文件路径**：`Assets/Scripts/Utility/Math/CoordinateConvertUtility.cs` 等
* **问题描述**：Unity 自带的 `UnityEngine.Pose` 与新 SDK 引入的 `ByteDance.PICO.Enterprise.Pose` 发生冲突 (`CS0104`)。
* **修改方案**：在文件头部显式声明 `using Pose = UnityEngine.Pose;`。

### 3.3 废弃 DllImport 替换为官方 Wrapper
* **文件路径**：`Assets/Scripts/Data Layer/DataController.cs`
  * **旧**：`[DllImport] Pxr_SetOriginOfLargeSpace` -> **新**：`PXR_Enterprise.SetOriginOfLargeSpaceQuickMode`
* **文件路径**：`Assets/Scripts/Utility/LargeSpaceStatusControl.cs`
  * **旧**：`[DllImport] UPxr_SwitchLargeSpaceScene` -> **新**：`PXR_Enterprise.SwitchLargeSpaceScene`
  * **补充**：为适配新接口签名，补充了缺失的 `ext: 0` 参数，并调整了相关的 Action 回调委托适配。

---

> **文档维护建议**：
> 未来如果更新到 `0.10.x` 的正式版或其他版本，请优先比对第 1 节（SDK 内部源码修改），确认官方是否已经修复了相关 Bug。如果官方已修复，则应移除我们的临时 Workaround。
