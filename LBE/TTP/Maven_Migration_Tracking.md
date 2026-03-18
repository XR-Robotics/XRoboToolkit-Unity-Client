# Maven 迁移追踪（高优先级）

## 背景
作为 TTP 合规流程的一部分，我们需要将 Android 模块 (`LSpaceLib`) 中的本地二进制依赖（`.aar` / `.jar`）迁移为 Maven 远程依赖。这有助于改善版本控制、净化代码库，并符合“Binary Check（二进制检查）”的合规规则。

## 待替换列表

| 库名称 (Library Name) | 当前文件路径 (Current File Path) | 状态 (Status) | 行动项 (Action Item) |
|---|---|---|---|
| **pxr_api.aar** | `LSpaceLib/app/libs/pxr_api.aar` | ⏳ 等待信息 | 联系 PICO SDK 团队获取 Maven 坐标 |
| **PxrPlatform.aar** | `LSpaceLib/app/libs/PxrPlatform.aar` | ⏳ 等待信息 | 联系 PICO SDK 团队获取 Maven 坐标 |
| **pxrnotification.jar** | `LSpaceLib/app/libs/pxrnotification.jar` | ⏳ 等待信息 | 联系 PICO SDK 团队获取 Maven 坐标 |
| **libSafetyArea.so** | `LSpaceLib/safearealib/src/main/jniLibs/...` | ⏳ 等待信息 | 联系 PICO 算法团队获取 Maven 坐标 (AAR) |
| **libairclient.so** | `LSpaceLib/safearealib/src/main/jniLibs/...` | ⏳ 等待信息 | 联系 PICO 算法团队获取 Maven 坐标 (AAR) |
| **libaircamera.so** | `LSpaceLib/safearealib/src/main/jniLibs/...` | ⏳ 等待信息 | 联系 PICO 算法团队获取 Maven 坐标 (AAR) |
| **libairservice.so** | `LSpaceLib/safearealib/src/main/jniLibs/...` | ⏳ 等待信息 | 联系 PICO 算法团队获取 Maven 坐标 (AAR) |
| **libdatabuffer.so** | `LSpaceLib/safearealib/src/main/jniLibs/...` | ⏳ 等待信息 | 联系 PICO 算法团队获取 Maven 坐标 (AAR) |
| **configclientlibrary.jar** | `LSpaceLib/app/libs/configclientlibrary.jar` | ⏳ 等待信息 | 联系 PICO 平台团队获取 Maven 坐标 |

## 行动计划 (Action Plan)

1.  **索取信息**: 联系 PICO 平台/SDK 团队及算法团队。
    *   **SDK 团队**: "请问 `pxr_api`, `PxrPlatform`, `pxrnotification`, `configclientlibrary` 的 Maven 坐标？"
    *   **算法团队**: "请问 `libSafetyArea.so`, `libairclient.so`, `libaircamera.so`, `libairservice.so`, `libdatabuffer.so` 是否有封装好的 AAR 及其 Maven 坐标？"
2.  **验证坐标**: 收到信息后，在 `LSpaceLib/app/build.gradle` 中进行测试。
    ```gradle
    dependencies {
        // 预期格式 (示例):
        // compileOnly 'com.pico.vr:pxr_api:3.1.0'
        // compileOnly 'com.pico.vr:PxrPlatform:3.1.0'
        // compileOnly 'com.pvr.pxrnotification:pxrnotification:1.0.0'
    }
    ```
3.  **删除本地文件**:
    *   `git rm LSpaceLib/app/libs/pxr_api.aar`
    *   `git rm LSpaceLib/app/libs/PxrPlatform.aar`
    *   `git rm LSpaceLib/app/libs/pxrnotification.jar`
4.  **验证构建**: 在 `LSpaceLib` 目录下运行 `./gradlew clean build`，确保编译通过。
5.  **更新 TTP 报告**: 在 `List_Report_Feishu.md` 中将对应的 ID 标记为 `fixed`。

## 关联 TTP ID

*   **pxr_api.aar**: `85667842` (Android), `85667945` (Unity)
*   **PxrPlatform.aar**: `85667834` (Android), `85667934` (Unity)
*   **pxrnotification.jar**: `85667839` (Android), `85667964` (Unity)
*   **libSafetyArea.so**: `85667838` (Android), `85667831` (Android)
*   **libairclient.so**: `85667836` (Android), `85667833` (Android)
*   **libaircamera.so**: `85667837` (Android)
*   **libairservice.so**: `85667830` (Android)
*   **libdatabuffer.so**: `85667829` (Android)
*   **configclientlibrary.jar**: `85667832` (Android), `85667963` (Unity)
