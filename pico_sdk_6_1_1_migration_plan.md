# XRoboToolkit 迁移到 PICO Unity SDK 6.1.1

日期：2026-11-05。状态：用户已批准并执行迁移；当前基线为 PICO Unity SDK 6.1.1。
执行结果与兼容差异见 `pico_sdk_6_1_1_migration_report.md`。下文保留方案制定时的核对依据和实施条件。

| 项目 | 定位 |
| --- | --- |
| 文档类型 | SDK 迁移方案 |
| 读者与协作关系 | 项目开发者、审核者；共同审核实施范围 |
| 目标 | 使用 PICO Unity SDK 6.1.1 的 PICO XR 模式运行现有工程 |
| 范围 | SDK 依赖、接口适配、企业客户端兼容、资源引用和编辑器验证 |
| 实施负责人 | 当前开发协作会话，用户审核后执行 |

## 迁移选择

保留 Unity 2022.3.16f1，选择 PICO XR 模式。官方 6.1.x 文档要求该模式使用 Unity 2022.3.15f1 或以上，当前编辑器满足版本门槛。[Research-backed]

保留现有企业客户端 `tobservicelib-0.6.0-alpha.0.aar`，核对并适配新版企业封装。升级 SDK、将全部采集改走企业接口是不同的改动；本次先完成 SDK 兼容迁移，不同时扩展手部、IMU 或眼动传输协议。[Expert judgment]

采用固定的 6.1.1 发行包作为本地依赖。官方示例使用 Git URL 的 `#main`，该引用没有固定到 6.1.1，不能直接作为此次版本锁定依据。[Research-backed]

审核本方案后，可执行 SDK 获取、依赖替换、接口适配、Unity 资源导入和 Editor/Android C# 编译验证。APK 构建、设备安装、系统设置调整、模拟器启动以及新增工具链下载需要另外授权。该范围沿用项目 `AGENTS.md`。[Data-backed]

## 已核对的依据

| 事实 | 核对结果 |
| --- | --- |
| 当前编辑器 | `ProjectSettings/ProjectVersion.txt` 为 `2022.3.16f1`。[Data-backed] |
| 当前 XR 包 | `com.unity.xr.picoxr` 指向 `file:../PICO Unity Integration SDK`，其 `package.json` 版本为 `3.1.2`。[Data-backed] |
| 目标发行版本 | 官网下载列表为 `6.1.1`，发布时间 `2026-09-04`；页面元数据列出的文件为 `sdk/2026-09-04/PICO-Unity-SDK-6.1.1-20260903.zip`，大小 `136844857` 字节。[Research-backed] |
| XR 命名空间 | 官方对照表将 `Unity.XR.PXR` 映射到 `ByteDance.PICO.XR`。[Research-backed] |
| 企业命名空间 | 官方对照表将 `Unity.XR.PICO.TOBSupport` 映射到 `ByteDance.PICO.Enterprise`。[Research-backed] |
| 新 SDK 宏 | 官方迁移说明使用 `ENABLE_PICO_XR_SDK`。[Research-backed] |
| 融合眼动接口 | 本地 6.1 官方知识文档仍列出 `GetCombinedEyePoseStatus`、`GetCombineEyeGazePoint`、`GetCombineEyeGazeVector`；需再次对照实际 6.1.1 源码。[Research-backed] |
| 项目直接引用 | `Assets/Scripts` 和 `Assets/Editor` 中共有 12 个 C# 文件直接使用旧命名空间或 `PXR_` API。[Data-backed] |
| 企业客户端 | 当前 AAR SHA-256 为 `53d1cee59fb116c98eefa4cdd05d68656f525858b423013c87f48da2f35e2882`。[Data-backed] |
| 当前 Android XR 提供者 | `Assets/XR/XRGeneralSettings.asset` 引用项目的 `PXR Loader`。[Data-backed] |
| 本地工具 | 只读环境检查通过；Unity CLI 为 `1.0.0-beta.13`，PICO CLI 为 `0.6.0`。当前 Unity 2022 环境不能据此使用官方 Unity 6 Pipeline/MCP。[Data-backed] |

官方依据：

- [6.1.x 环境要求](https://developer-cn.picoxr.com/document/pico-unity-quickstart/software-and-hardware-requirements/)
- [旧项目导入和迁移步骤](https://developer-cn.picoxr.com/document/pico-unity-quickstart/import-the-sdk-and-select-a-rendering-mode/)
- [官方版本下载列表](https://developer-cn.picoxr.com/resources/?platform=unity)
- 命名空间依据为本机官方知识文档 `C:/Users/Admin/AppData/Local/PICO/sdk/6.1/agent-vault/unity/documentation/unity-getting-started_namespace-mappings.md`；官网迁移页面所链接的命名空间地址当前返回文档不存在。[Data-backed]

## 执行前验证条件

目前尚未获取并检查完整的 6.1.1 发行包。新版实际 UPM 包名、程序集名、Enterprise 模块布局、随包 AAR 和原生库，以及 SDK 脚本 GUID 都属于待验证项。[Data-backed]

执行时先从官网下载流程取得上述版本化 ZIP，记录可访问的下载地址、发行包哈希和内部 `package.json`。仅当相关包确认为目标 6.1.1 发行内容时，才开始修改工程依赖。若只有浮动的 `main` 可获取，或包内容版本不符，保留当前基线并报告结果。[Expert judgment]

官网的相对下载路径不能直接推断成旧 `sdk.picovr.com/developer-platform/` 下载地址；本次对此地址的 HEAD 请求返回 404。当前也未找到可用的 GitHub CLI，因此尚未核验 Git 标签或固定提交。[Data-backed]

当前官方 Unity API 知识目录未找到对应的企业 API 参考文件。企业模块是否包含原有类和方法，以发行包实际声明为准，不根据命名空间对照表推断方法兼容。[Data-backed]

## 执行顺序与通过条件

### 1 保存现有工作状态

前提：用户审核本方案。

1. 记录当前分支、工作树差异和已有未跟踪文件。
2. 备份旧 SDK 的完整目录及导入器元数据，备份将修改的 Packages、XR 设置、脚本、场景和预制体。
3. 保存企业 AAR、Java 桥接及其哈希，并记录现有 XR 提供者、SDK 设置、输入绑定和协议字段。
4. 将备份放在 Unity 不导入的位置；本次已有 UI、眼动、设备模拟以及 SDK 回调修改均纳入备份。

通过条件：备份包含实际工作树内容，能够恢复迁移前的未提交修改。不得用提交、清空工作树或删除采集数据来代替备份。[Expert judgment]

### 2 核验新版依赖并替换 XR 包

前提：发行包版本和来源验证通过，备份完成。

1. 检查发行包的 XR、Enterprise、Platform、音频及预览模块布局，列出工程所需模块。
2. 根据真实 `package.json` 确定本地 UPM 包名和路径，修改 `Packages/manifest.json`。
3. 移除旧 XR 包的活动引用，使新旧 XR Runtime 不同时导入；备份中的旧包保持可恢复。
4. 按实际新程序集名修正引用和版本宏，并让 Unity 重新解析锁文件。
5. 核对必要依赖与现有 XRI 3.0.3、XR Hands 1.4.1、OpenXR 1.14.3 的约束。若必须改变这些版本，先列出具体冲突再决定最小适配范围。

通过条件：目标 XR 包来自固定 6.1.1 发行内容，所有依赖可解析，项目没有同时启用两套 PICO XR 提供者。[Expert judgment]

本步骤涉及项目旧本地 SDK 路径约定的调整。迁移验证通过后，同步更新 `AGENTS.md`、项目规则、相关技能及环境说明中的版本和依赖路径；不预先把未完成的迁移写成已生效基线。[Expert judgment]

### 3 适配代码与企业客户端

前提：已检查实际 6.1.1 类型、程序集及原生声明。

1. 逐文件迁移命名空间与 API 调用，保留现有数值类型、坐标转换和协议字段。
2. 适配项目自定义程序集，保留 `PICO_XR` 对原生访问的保护，同时按新版包和宏机制定义其适用条件。
3. 将项目定制的企业兼容逻辑与新版实现逐项比较，保留所需行为并避免在 `PXR_EnterprisePlugin` 中加入新的采集策略。
4. 保留 `EnterprisePoseBridge.java` 和 `EnterpriseEyeFrameBridge.java`，核对服务绑定、回调 ABI、反射字段及捕获启停。
5. 保留当前 alpha ToB 客户端，仅关闭或移除新版发行包中与它重复的同类客户端导入。分别检查 Java 类重名及同 ABI 下同名原生库，不盲目删除其他企业依赖。
6. 验证当前 Runtime 优先的手柄回退路径是否仍可工作；本次不把它悄然改成纯 ToB 来源。

通过条件：Editor 与 Android 配置下的 C# 均可编译；企业客户端没有重复类；SDK 方法、回调及原生符号都与实际声明一致。[Expert judgment]

### 4 修正资源引用与运行设置

前提：脚本可编译。

1. 对照新旧脚本 `.meta`，核对 `PXR_Manager`、`PXR_ProjectSetting`、Loader 及其他 SDK 组件的 GUID 和序列化字段。
2. 保留项目业务资源 GUID、场景对象 fileID 和用户布局；仅按目标 SDK 的实际类型修正必要引用。
3. 保持 Android 为 PICO XR 模式，核验新 Loader、手势、眼动、人体追踪与 VST 设置。
4. 检查输入绑定和编辑器设备模拟配置，确认头部、左右手柄及鼠标眼动模拟仍可独立操作。
5. 逐项查看新版 Project Validation 提示；每项修改说明其必要性，不直接执行批量修复来改写未知设置。

通过条件：场景、预制体和 XR 设置没有 Missing Script 或失效 SDK 引用；当前业务布局与输入绑定可以加载。[Expert judgment]

### 5 更新验证脚本并完成编辑器验证

前提：新版资源导入及依赖解析完成。

1. 更新 `tools/ai/dev_environment.py`，使它读取生效的新 SDK 包名、位置和版本。
2. 更新 `tools/ai/validate_eye_gaze.py` 的程序集引用、宏和资源验证规则。
3. 重新生成新版 Unity 编译引用，运行 Editor 与 Android C# 编译检查，不能继续引用旧 `Unity.XR.PICO.ref.dll` 来宣称新版编译通过。
4. 执行现有眼动验证入口，检查坐标转换、无效数据清理、物理/UI 求交及资源加载。
5. 在编辑器验证主界面、EyeFrame 面板的启停状态、眼动模拟和控制器模拟；编辑器模拟结果只验证逻辑，不代表设备返回了眼动或 EyeFrame。
6. 比较迁移前后采集序列化结果的字段名、类型和有效性处理，确认此次 SDK 迁移没有改变已有协议。

通过条件：验证使用的是 6.1.1 对应程序集，编译通过，资源引用正常，已有编辑器逻辑验证通过。硬件接口、真机图像与立体渲染仍列为待设备验证项。[Expert judgment]

## 重点适配文件

| 范围 | 文件 |
| --- | --- |
| 基础追踪及网络 | `Assets/Scripts/TrackingData.cs`、`Assets/Scripts/Network/TcpHandler.cs`、`Assets/Scripts/EnterpriseCollection/EnterpriseCollectionRecorder.cs` |
| 眼动 | `Assets/Scripts/EyeGaze/PicoEyeGazeSource.cs`、`Assets/Scripts/EyeGaze/XRoboToolkit.EyeGaze.asmdef` |
| EyeFrame | `Assets/Scripts/EnterpriseEyeFrames/XRoboToolkit.EnterpriseEyeFrames.asmdef`、`Assets/Plugins/Android/src/main/java/com/xrobotoolkit/enterprise/EnterpriseEyeFrameBridge.java` |
| 企业位姿桥接 | `Assets/Plugins/Android/src/main/java/com/xrobotoolkit/enterprise/EnterprisePoseBridge.java`、旧 SDK 企业 Plugin 及 `IntCallback` / `StringCallback` |
| 其他直接 SDK 调用 | `Assets/Scripts/Main.cs`、`Assets/Scripts/Utils.cs`、`Assets/Scripts/ExtraDev/ExtDevTracking.cs`、`Assets/Scripts/ExtraDev/UIExtraDevPanel.cs` |
| UI 与相机调用 | `Assets/Scripts/UI/RecordDialog.cs`、`Assets/Scripts/UI/UICameraCtrl.cs`、`Assets/Scripts/UI/UICameraCtrlPC.cs`、`Assets/Scripts/UI/UIOperate.cs` |
| 设置及序列化引用 | `Packages/manifest.json`、`Packages/packages-lock.json`、`Assets/XR`、`Assets/Resources/PXR_ProjectSetting.asset`、XR Rig 预制体及 `Assets/Main.unity` |
| 验证与说明 | `tools/ai/dev_environment.py`、`tools/ai/validate_eye_gaze.py`、`Assets/Editor/EyeGazeValidation.cs`、工程基线说明 |

文件范围来自本次静态引用扫描和已读代码，实际发行包导入后可能暴露额外类型或资源适配点。[Data-backed]

## 采集行为的验证边界

手柄 latest 预测模式、位姿有效性过滤、当前输入设备检查，以及 TCP 协议的显式数值类型属于现有工程约束。迁移时按原有约定保留，并对实际代码与约定之间的差异单独记录。[Data-backed]

当前 `enterprise_direct` TCP 路径只组装头部、手柄和应用状态，未合并 Hand、Body、Motion；EyeFrame 和融合眼动目前主要用于预览/可视化。这些是迁移前已存在的行为，本次不把 SDK 升级验收写成这些数据流已经补齐。[Data-backed]

新版本不能仅凭包版本证明 Swan 固件支持更多眼动结果。高级眼动、企业手部与 IMU 数据能力需要独立读取接口返回码、有效性和样本时间戳后确认。[Expert judgment]

## 回退方式

若目标包版本不符、企业 ABI 冲突无法解决、必要 API 缺失、C# 编译无法通过，或关键资源引用不能恢复，停止扩大修改范围。[Expert judgment]

回退时先保存本次迁移差异，再从迁移前备份恢复旧 SDK、Packages、相关脚本及资源引用。恢复以文件范围为单位，不执行 `git reset --hard`、`git clean` 或全工作树恢复；保留用户随后产生的修改和采集数据。恢复后重复环境、编译和资源检查。[Expert judgment]

本方案已获用户授权，按 PICO XR 模式、Unity 2022.3.16f1 和当前 alpha ToB 客户端执行。真机构建、安装和设备设置操作仍需另行授权。
