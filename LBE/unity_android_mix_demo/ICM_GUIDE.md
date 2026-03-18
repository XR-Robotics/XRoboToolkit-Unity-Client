# Unity + Android 混编工程镜像化与 CI 构建指南

本文档旨在指导如何在 ICM 镜像环境中配置、构建和部署本混编工程（Form B：Unity 主工程 + Android 插件）。本方案采用了“导出工程 -> Gradle 构建”的策略，确保了构建过程的稳定性和可审计性。

## 1. 工程结构概览

本工程采用了 **Form B** 结构，即 Unity 作为主入口，Android 原生能力以 AAR 插件形式提供。

```text
unity_android_mix_demo/
├── android/                 # [Android] 原生插件工程
│   ├── android_plugin/      # 核心逻辑模块
│   │   ├── src/main/java/   # Java 源码 (PluginInstance.java)
│   │   └── build.gradle     # 产出 AAR 配置
│   ├── build.gradle         # 根构建配置 (Gradle 7.5 + AGP 7.4.2)
│   └── settings.gradle      # 包含 :android_plugin
├── unity/                   # [Unity] 主工程
│   ├── Assets/
│   │   ├── Plugins/Android/ # 存放编译好的 AAR (android_plugin.aar)
│   │   ├── Scripts/         # C# 调用 Android 的桥接代码
│   │   └── Editor/Build.cs  # Unity 导出构建脚本
│   └── ProjectSettings/
├── scripts/                 # [CI/CD] 自动化脚本
│   ├── build_plugin.sh      # 步骤1：编译 Android 插件 -> 拷贝 AAR 到 Unity
│   └── build_apk.sh         # 步骤2：Unity 导出 Gradle 工程 -> 编译最终 APK
├── build/                   # [Output] 构建产出
│   ├── exported_project/    # Unity 导出的中间态 Gradle 工程
│   └── android/             # 最终 APK 产物
└── ICM_GUIDE.md             # 本指南
```

## 2. 镜像环境要求 (ICM / BigMac)

为了在 CI 环境中成功构建，基础镜像需要满足以下工具链版本要求。这些版本是根据 Unity 2021.3 和 Android 兼容性测试得出的最佳组合。

| 工具 | 版本要求 | 说明 |
| :--- | :--- | :--- |
| **OS** | Linux (ICM) / macOS (BigMac) | 推荐使用 Linux 容器进行标准化构建 |
| **JDK** | **OpenJ9 / JDK 11** | 必须是 JDK 11，以兼容 Unity 2021.3 导出的 Gradle 工程 |
| **Android SDK** | API Level 33 (compileSdk) | 需包含 Build-Tools 30.0.3+ |
| **Unity** | **2021.3.x LTS** | 需安装 Android Build Support 模块 (OpenJ9, IL2CPP) |
| **Gradle** | 7.5+ | 工程内置了 `gradlew`，但环境需支持运行它 |

### 2.1 环境变量配置
在镜像或 CI 任务中，请确保设置以下环境变量：

```bash
# 指向 Unity 安装目录 (示例路径，按实际修改)
export UNITY_EXECUTABLE="/opt/Unity/Editor/Unity"

# 指向 JDK 11 根目录
export JAVA_HOME="/usr/lib/jvm/java-11-openjdk"

# Android SDK 路径
export ANDROID_HOME="/opt/android-sdk"
export ANDROID_NDK_HOME="/opt/android-ndk"
```

## 3. 标准构建流程

构建过程分为两个串行阶段：先编译插件，再编译主包。

### 阶段一：编译 Android 插件
此步骤编译 `android/` 目录下的原生代码，生成 AAR 并自动分发到 Unity 工程中。

```bash
# 在工程根目录下执行
chmod +x ./scripts/build_plugin.sh
./scripts/build_plugin.sh
```

*   **输入**：`android/android_plugin` 源码
*   **输出**：`unity/Assets/Plugins/Android/android_plugin.aar`
*   **验证**：脚本运行成功后，检查上述 AAR 文件是否更新。

### 阶段二：构建 Unity APK
此步骤调用 Unity 引擎将工程导出为 Gradle 项目，并使用 Gradle 打包。

```bash
# 在工程根目录下执行
chmod +x ./scripts/build_apk.sh
./scripts/build_apk.sh
```

*   **输入**：`unity/` 工程（含刚生成的 AAR）
*   **中间产物**：`build/exported_project/` (完整的 Android Studio 工程)
*   **最终产出**：`build/android/UnityAndroidMixDemo.apk`

## 4. 常见问题排查 (Troubleshooting)

### Q1: "Manifest merger failed: minSdkVersion 22 cannot be smaller than version 24"
*   **原因**：Android 插件 (`build.gradle`) 设置的 `minSdk` 高于 Unity 工程的默认值 (22)。
*   **解决**：已在 `android/android_plugin/build.gradle` 中将 `minSdk` 降级为 22。如果插件确实需要更高版本，需在 Unity Player Settings 中同步提高 `Minimum API Level`。

### Q2: "Gradle build failed with Java 17"
*   **原因**：Unity 2021 导出的 Gradle 工程默认配置不兼容 JDK 17。
*   **解决**：确保 `JAVA_HOME` 指向 **JDK 11**。我们在 `build_apk.sh` 中已显式指定了兼容的 JDK 路径，镜像中需对应安装。

### Q3: Unity 提示 "No such file or directory"
*   **原因**：`UNITY_EXECUTABLE` 路径错误，或机器上未安装 Unity。
*   **解决**：修改脚本中的路径，或在 CI 环境变量中正确注入。

## 5. 后续工作 (AI 提示)

如果您是接手的 AI 助手，请关注以下任务：

1.  **CI 集成**：将上述脚本配置到 `.gitlab-ci.yml` 或 Jenkins Pipeline 中。
2.  **镜像固化**：编写 `Dockerfile`，将 JDK 11、Android SDK 和 Unity Editor 固化到镜像中。
3.  **依赖管理**：目前插件依赖直接写在 `build.gradle`，建议迁移到 TOML 版本目录或 TTP 私有源。
4.  **功能扩展**：在 `PluginInstance.java` 添加更多业务方法，并在 `AndroidPluginTest.cs` 中增加对应调用。
