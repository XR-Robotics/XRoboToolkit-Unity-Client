# TTP Compliance Issues List

## Type: chinese

| ID | Rule | File Path | Handler | Status | Details |
|---|---|---|---|---|---|
| 85667849 | 中文 | `safearealib/src/main/res/layout/activity_main.xml` | lijialun.qwq | fixed |  |
| 85667848 | 中文 | `jenkinsfile` | lijialun.qwq | fixed |  |

## Type: domain

| ID | Rule | File Path | Handler | Status | Details |
|---|---|---|---|---|---|
| 85670788 | https://stone-review.byted.org | `jenkinsfile` | Gemini | fixed |  |
| 85670758 | https://obric-pdm.bytedance.net | `jenkinsfile` | zhaozhenjia | fixed |  |
| 85670757 | https://obric-pdm-be.bytedance.net | `jenkinsfile` | zhaozhenjia | fixed |  |

## Type: binary_check

| ID | Rule | File Path | Handler | Status | Details |
|---|---|---|---|---|---|
| 85667842 | .aar | `app/libs/pxr_api.aar` |  | open | **外部依赖整体跟进** |
| 85667841 | .so | `app/src/main/jniLibs/arm64-v8a/libnative-lib.so` |  | open |  |
| 85667840 | .jar | `app/libs/safearealib.jar` | Gemini | fixed |  |
| 85667839 | .jar | `app/libs/pxrnotification.jar` | Gemini | fixed | **外部依赖整体跟进** |
| 85667838 | .so | `safearealib/src/main/jniLibs/arm64-v8a/libSafetyArea.so` |  | open |  |
| 85667837 | .so | `safearealib/src/main/jniLibs/armeabi-v7a/libaircamera.so` |  | open |  |
| 85667836 | .so | `safearealib/src/main/jniLibs/armeabi-v7a/libairclient.so` |  | open |  |
| 85667835 | .jar | `app/libs/unity-classes.jar` | Gemini | fixed | **外部依赖整体跟进** |
| 85667834 | .aar | `app/libs/PxrPlatform.aar` |  | open | **外部依赖整体跟进** |
| 85667833 | .so | `safearealib/src/main/jniLibs/arm64-v8a/libairclient.so` |  | open |  |
| 85667832 | .jar | `app/libs/configclientlibrary.jar` |  | open |  |
| 85667831 | .so | `safearealib/src/main/jniLibs/armeabi-v7a/libSafetyArea.so` |  | open |  |
| 85667830 | .so | `safearealib/src/main/jniLibs/armeabi-v7a/libairservice.so` |  | open |  |
| 85667829 | .so | `safearealib/src/main/jniLibs/armeabi-v7a/libdatabuffer.so` |  | open |  |
| 85667824 | .jar | `app/libs/classes.jar` | Gemini | fixed |  |

## External Dependencies Summary

| Component | Ownership | Binary Count | Note |
|---|---|---|---|
| PICO SDK | Second Party | 3 | Follow up with owner |
| Unity | Third Party | 1 | Follow up with owner |

### External Dependencies Details

#### PICO SDK (3)
| ID | File Path | Status |
|---|---|---|
| 85667842 | `app/libs/pxr_api.aar` | open |
| 85667839 | `app/libs/pxrnotification.jar` | fixed |
| 85667834 | `app/libs/PxrPlatform.aar` | open |

#### Unity (1)
| ID | File Path | Status |
|---|---|---|
| 85667835 | `app/libs/unity-classes.jar` | fixed |
