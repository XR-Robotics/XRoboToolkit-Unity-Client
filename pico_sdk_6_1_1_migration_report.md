# PICO Unity SDK 6.1.1 迁移结果

日期：2026-11-05。状态：已执行用户批准的迁移；Editor 与 Android C# 验证通过。

## 生效基线

| 项目 | 当前配置 |
| --- | --- |
| Unity | 2022.3.16f1，保持原版本 |
| PICO SDK | 官方 PICO Unity SDK 6.1.1，PICO XR 模式 |
| UPM 依赖 | `com.bytedance.pico.xr: file:../PICO Unity SDK` |
| XR Loader | `ByteDance.PICO.XR.PXR_Loader`，Android 仅启用这一提供者 |
| 企业客户端 | 保留 `tobservicelib-0.6.0-alpha.0.aar` |
| XRI / XR Hands / OpenXR | 保留 3.0.3 / 1.4.1 / 1.14.3 |
| 工具 | Unity CLI 1.0.0-beta.13；PICO CLI 0.6.0 |

发行包通过官网版本化下载流程取得，ZIP 大小为 136844857 字节，内部 XR `package.json` 确认为 6.1.1。仅导入 XR，未导入 SpatialAdapter，未升级 Unity，也未执行新项目初始化。

ZIP SHA-256：
`b1398e3387d94a8823ebc0df67b03dca022bd54f11b453f3c29a01dc341622a0`

企业 alpha AAR SHA-256：
`53d1cee59fb116c98eefa4cdd05d68656f525858b423013c87f48da2f35e2882`

## 已完成的适配

- 迁移业务和交互脚本至 `ByteDance.PICO.XR`、`ByteDance.PICO.Enterprise`，更新两份项目 asmdef、包版本宏和 XR 设置注册键。
- 保留项目 `PICO_XR` 保护，增加官方 `ENABLE_PICO_XR_SDK`。头部采样改用新版 `PXR_Plugin.Pxr_GetPredictedMainSensorState2`，原生访问排除 Editor。
- 将 Runtime 优先、Java 位姿桥接及 ToB 回退放入 `EnterpriseControllerPoseSource`。保持手柄 latest 预测时间 0、有效性过滤、当前输入设备判断及已有 TCP 字段类型。
- 将项目定制的 USB 静态 IP 直接调用和 `pbsCommonMessageLocked` 回退移到 `EnterpriseUsbNetworking`，保留失败返回和诊断日志。
- 使用新版追踪器连接事件、`GetMotionTrackerLocation`、外设枚举及透传接口替换已移除的轮询接口。人体采集使用新的状态查询和全身关节集接口。
- VST 启停改用新版 `PXR_Manager.EnableVideoSeeThrough`；保持默认关闭，移除已经返回固定 `false` 的旧 Enterprise RGB 相机启停调用。
- 更新环境检测、眼动验证脚本、工程规则、项目技能和相关说明。

`PXR_EnterprisePlugin` 保持新版官方实现。新版 `tob_api-release.aar` 保持启用，其字节码将 `com.picoxr` 回调适配到 alpha 客户端的 `com.pvr` Binder 接口；因此没有把旧版回调类直接覆盖到新版 SDK。

本地 SDK 的 9 份 asmdef 移除了工程未安装的 ARFoundation、URP、Composition Layers、Inference 及旧版程序集引用。对应功能宏未启用；没有为这些可选功能下载依赖。Unity 同时补全了部分发行包缺失或简略的 importer 元数据。

Android 导入选择：

| 文件 | Android 导入 | 原因 |
| --- | --- | --- |
| `tobservicelib-0.6.0-alpha.0.aar` | 启用 | 保留现有企业客户端及 EyeFrame 接口 |
| SDK `tob_api-release.aar` | 启用 | 新企业封装的 Java 适配层 |
| SDK `tobservicelib-release.aar` | 禁用 | 避免重复企业类 |
| 应用 `capturelib-0.0.7.aar` | 启用 | 保留 robotassistant 录制/预览依赖 |
| SDK `capturelib-release.aar`、`CameraRenderingPlugin.aar` | 禁用 | 两套 capture 库包含不同 JNI ABI 的同名原生库 |

SDK 的可选 RGB CameraRendering 路径因此不作为本工程的有效相机入口；现有应用相机路径保留。后续若要使用该新版 SDK 相机入口，需要单独迁移 robotassistant 相机依赖。

## 验证证据

| 验证 | 结果 |
| --- | --- |
| 实际 Unity Editor 导入及 C# 编译 | 通过，加载包版本 6.1.1，旧 PICO 程序集未加载 |
| Android C# 编译 | 通过，使用 `PlayerBuildInterface.CompilePlayerScripts` 生成新版程序集 |
| 迁移验证入口 | 30 项通过 |
| 眼动验证入口 | 15 项通过：坐标转换、无效输入、物理/UI 求交、遮挡和资源引用 |
| Main 场景及模拟器脚本引用 | 未发现 Missing Script；模拟器输入资源可加载 |
| EyeFrame UI | 开启后主界面可用；取消勾选或 Close 均收起面板并触发停止采集 |
| 眼动模拟 | 共享开启路径、有效样本发布、无效样本清理和关闭路径通过 |
| 手柄协议 | 字段名及 `string` / `int` / `long` 类型通过；NaN、范围及默认位姿过滤通过 |
| Java 桥接 | 保留的两份桥接在 Android API 32、alpha 客户端和新版 Java 适配层下编译通过 |
| Android AAR 冲突检查 | 未发现活动客户端之间的重复业务 Java 类或同 ABI 原生库路径 |
| Python 验证脚本 | 新 Editor / Android 编译引用检查及编译通过 |

最终 Unity 日志记录 `Exiting batchmode successfully now` 和进程返回码 0。TRAE 沙箱仍报告 Unity Hub、共享缓存及遥测文件的写入限制，导致 Shell 工具状态非零；上述结论依据实际 Unity 日志、加载包检查和生成的程序集，未把工具启动状态当作编译结果。

- [最终 Unity 日志](Logs/pico-sdk-6.1.1-validation-final.log)
- [验证结果 JSON](Logs/pico-sdk-6.1.1-validation/result.json)
- [主界面与 EyeFrame 并列预览](Logs/pico-sdk-6.1.1-validation/main-eyeframe.png)
- [Project Validation 提示](Logs/pico-sdk-6.1.1-validation/project-validation.txt)

眼动 UI 测试入口补上了 Edit mode 下的射线检测器生命周期注册及 Canvas 渲染步骤，使已有断言能够实际执行。预览图来自 Unity 渲染，图像窗口中的等待状态不代表接收到了设备 EyeFrame。

## 兼容差异与验证边界

1. **Motion / 外设标识变化。** 6.1.1 提供数值设备 ID，旧字母数字 SN 轮询接口已移除。现有 `sn` 字段及自定义包标识仍为字符串，但值改为 ID 的十进制字符串。依赖旧硬件 SN 的接收端或设备映射需要适配；没有猜测 ID 与旧 SN 的对应关系。
2. **人体高精度选项。** 新 SDK 提供全身关节集，不再区分旧版 `BTM_FULL_BODY_LOW/HIGH`。当前使用全身关节集，勾选旧 High accuracy 选项会记录这一限制。
3. **已有协议差异保留。** 手柄过滤代码对零时间戳的判断仍是“零时间戳且默认单位位姿无效”，与更严格的全部零时间戳过滤约定存在原有差异；此次没有改变这一行为。
4. **Project Validation 尚有提示。** 原有场景/预制体包含多个 MainCamera 标签，且编辑器 Player Settings 的 keystore/key 尚未满足新 SDK 检查。另有 10 项渲染和可选功能建议。没有执行批量 Fix All；这些提示需要在后续 APK 构建前结合项目相机用途与签名流程处理。
5. **设备结果尚未验证。** 未执行 Gradle、IL2CPP、APK 打包、安装、设备设置调整或真实传感器采集。Game view 中的实际键盘/指针操作、真机头部/手柄追踪、眼动、EyeFrame、相机录制及立体渲染仍需运行验证。

此次没有将所有数据改走企业 SDK，也没有补充 IMU、Hand、Body、Motion 或 EyeFrame 的新 TCP 数据流。迁移前 `enterprise_direct` 的传输范围保持原有行为。

## 已有工作保留与回退

迁移前已保存 1386 个文件的内容和哈希，以及分支、工作树和暂存区差异。备份目录：

`C:/Users/Admin/AppData/Local/Temp/XRoboToolkit-PicoSDK-6.1.1-Migration-20261105/backup`

校验确认 `Assets/Main.unity`、XR Rig 预制体、PICO 输入绑定、PXR 项目设置及两份 Java 桥接与迁移前工作树备份完全一致。原有用户 UI、眼动和模拟器修改保留，采集数据未改动。旧 `PICO Unity Integration SDK` 目录仍保留，但已从活动 UPM 依赖中移除。没有提交或推送。

如需回退，先保存本次迁移差异，再按文件范围从备份恢复旧 SDK 引用、Packages、相关脚本及工程规则。不要执行全工作树 reset/clean，也不要覆盖用户之后新增的修改。
