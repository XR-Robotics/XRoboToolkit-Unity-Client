# XRoboToolkit-Unity-Client 项目说明

## 项目概述
`XRoboToolkit-Unity-Client` 是一个基于PICO设备用Unity引擎开发的服务于机器人训练与遥控的软件。本软件与PC端软件协助完成机器人的训练与遥控。
## 功能特性
- **训练数据录制**可以将VST图像与位姿数据同步录制为mp4文件保存到本机的Download目录。
- **机器人遥控**：将本机位姿数据传输到PC机器人端，用来遥控机器人。
- **图像的编解码**：可以将本机的VST图像进行编码发送，也可以将PC端的图像进行解码显示。
- **机器人麦克风播放**：远端视觉开启后，会用同一个PC/operator IP连接原始PCM音频端口，在头显内播放机器人侧麦克风声音。
- **Pico 麦克风上行**：将头显麦克风转为 `s16le`、`16 kHz`、单声道、20 ms PCM 帧发送到 operator bridge。

## G1-Wuji operator 音频
当 G1-Wuji operator 栈使用 `--with-audio` 启动时，operator 侧头显桥会把
G1 自带麦克风转成原始 `s16le`、`16 kHz`、单声道 PCM，并默认暴露在 TCP
`13580` 端口。Pico App 在 Remote Vision 点击 Listen 并输入 operator IP 后，
会自动连接同一个 IP 的音频端口；关闭远端相机窗口会同时停止视频和音频。
Pico 麦克风在同一 Listen 生命周期内默认全双工上行。运行时会明确请求
`RECORD_AUDIO`；若用户拒绝，只停用麦克风上行，不阻塞相机或原有遥操。
上行不是匿名裸 PCM 端口：当前控制连接必须先发送 `AUDIO_SESSION`，并拿到
与本次请求匹配的一次性令牌，Pico 才会连接和发送。

下行 fallback 可在 `Assets/StreamingAssets/video_source.yml` 里通过
`AudioStreamPort` 调整。麦克风端口不再采用静态 fallback，必须由 schema 为
`g1_wuji_audio_ports_v2` 的安全 `AUDIO_CONFIG` 下发。当前 Inspire profile
协商为 `13680/13681`。

协议 payload 示例：

```json
{
  "schema": "g1_wuji_audio_ports_v2",
  "audio_request_id": "<本次32字符请求ID>",
  "audio_stream_port": 13680,
  "microphone_upload_port": 13681,
  "microphone_upload_protocol": "g1_wuji_audio_uplink_v1",
  "microphone_upload_token": "<一次性会话令牌>",
  "sample_rate": 16000,
  "channels": 1,
  "sample_format": "s16le"
}
```

上行 TCP 首帧是带长度的 `G1AT` 鉴权记录；语音用 `G1AF` 记录携带序号、
采集时间和固定 640 字节 PCM；静音/空闲时用 `G1AH` 心跳保活。operator 会在
进入云链路前丢弃错误来源、错误令牌、乱序、畸形和陈旧帧，状态文件不会写入令牌。
Remote Vision 控制连接使用 App 内的 `OperatorControlClient`，通过 read-exact
和每次连接独立 socket 避开 vendor AAR 的长度头短读与快速重连串线问题。

麦克风上行默认全双工。调用 `UICameraCtrl.SetMicrophoneMuted(true)` 后，本地
仍持续消费采集环，但不会发送静音 PCM 帧，避免 G1 侧播放/duck 状态被永久激活。

在 `g1_wuji_teleoperation` operator 仓库中启动：

```bash
scripts/run_operator_cloud_stack.sh --cleanup-first --with-camera --with-audio --auto-start
```

## 目录结构

### Assets
Unity 项目的核心资源文件夹，包含了项目中使用的所有资源。
- **InteractionTools**：XR交互相关的代码与模型资源。
- **Plugins**：包含了提供Android接口的robotassistant_lib.aar和其他android平台配置。
- **Resources**：本项目相关的资源。
- **Scripts**：存放项目的脚本文件。
  - **Audio**：机器人麦克风播放和 Pico 麦克风 PCM 上行逻辑。
  - **Camera**：与Camera相关的逻辑代码。
  - **ExtraDev**：用来读取PICO追踪器外设的相关逻辑。
  - **Network**：网络相关逻辑。
  - **UI**：UI交互界面相关逻辑。
### robotassistant_lib.aar
此aar由Android工程导出，主要包含了对Pico设备的接口调用以及图像的编解码逻辑。

### 关键类介绍
UIOperater：UI交互界面相关逻辑。
UICameraCtrl：与Camera相关的逻辑代码。
TcpHandler: 网络发送相关逻辑。
TrackingData:处理位姿数据的产生。

### Packages
Unity 项目使用的各种包的存放位置，可通过 Unity Package Manager 进行管理。

### ProjectSettings
Unity 项目的各种设置文件，如音频设置、物理设置、输入设置等。
## PICO Unity Integration SDK
PICO Unity官方SDK，官方下载地址：https://developer.picoxr.com/zh/resources/

## 工程配置
### 环境配置
- Unity 2022.3.16f1+
- Android Studio 4.2.2
- Android SDK 29
- Android NDK 21.4.7075529
- PICO Unity SDK 1.1.0（推荐）
（安装Unity 2022.3.16f1过程中，勾选Android配置下载，Unity即可自行完成环境构建）

### 注意事项 
- 请优先使用Unity 2022.3.16f1版本，其他版本可能会出现问题。
- 请确保Android Studio和Android SDK的路径配置正确。
- 请确保PICO Unity SDK的版本与Unity版本兼容。
- 请确保PICO Unity SDK的路径配置正确。

### Unity打包导出APK步骤
- 请确保Unity的版本为2022.3.16f1。
- 请确保Unity的导出设置为Android平台。
- 请确保ProjectKey和KeyAlias的配置正确，首次打包请通过Keystore Manager -> Create New。
- 通过File -> Build Settings中的Build按钮进行导出。(Mac)
- 导出的APK文件将保存在ProjectSettings目录下的Android文件夹中。

## 一键打包
- 请确保环境配置正确。

### 快捷键操作
- Windows：Ctrl + Shift + B
- macOS：Cmd + Shift + B
- 支持通过菜单栏 Build > One - click packaging 调用

### 版本管理：
- 自动递增版本号（格式：Major.Minor.Build）
- 示例：1.0.0 → 1.0.1 → ... → 1.1.0

### 输出路径
- ProjectRoot/
- └── Builds/
-  ├── Android/
-   ├── iOS/
-   ├── macOS/
-   └── Windows/

### 打包后操作
- Windows：自动打开资源管理器并选中输出文件
- macOS：在 Finder 中显示构建文件
- 显示构建结果弹窗

### 核心接口
- 硬件交互层
  - PICO企业级接口调用（需设备权限）
  - PXR_Enterprise.SwitchSystemFunction(SystemFunctionSwitchEnum.SFS_SECURITY_ZONE_PERMANENTLY, SwitchEnum.S_OFF);
  - PXR_Enterprise.OpenVSTCamera(); // 开启VST透视相机
- 图像处理管线
  - 安卓原生解码器桥接
  - private static AndroidJavaObject _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.MediaDecoder");
  - public static void initialize(int unityTextureId, int width, int height) {
    GetJavaObject().Call("initialize", unityTextureId, width, height);}
- 网络传输层
  - 异步UDP数据接收
    UdpClient client = new UdpClient(port);
    BeginReceive();
    void BeginReceive() {client.BeginReceive(ReceiveCallback, null); }
    void ReceiveCallback(IAsyncResult ar) {IPEndPoint remoteEP = null; byte[] data = client.EndReceive(ar, ref remoteEP); // 数据解析... }
- 数据同步机制
  - TcpHandler -> NetPacket : 封装数据包
  - NetPacket -> ByteBuffer : 序列化处理
  - ByteBuffer -> Socket : 异步发送
  - Socket --> TcpHandler : 回调处理
- Unity业务逻辑
  - 带格式校验的IP输入
    if (!IPAddress.TryParse(ip, out _)) {SetRemind(LogType.Error, "The IP format is incorrect!");return;}
    TcpHandler.Connect(ip); // 触发TCP连接

### 架构说明
- 跨平台混合架构：Unity C#层与Android Java层通过JNI桥接，实现硬件加速编解码
- 双数据通道：独立的视频流(60FPS)和位姿数据通道(90Hz)，采用不同QoS策略
- 线程模型：
- 主线程：UI渲染和用户输入
- 工作线程：视频编码/网络传输
- GL线程：OpenGL ES纹理操作
- 内存管理：采用环形缓冲区处理视频帧，防止GC卡顿
- 异常恢复：TCP断线自动重连机制，视频解码支持关键帧请求
- 关键性能指标：
- 端到端延迟：<150ms (720P@30FPS)
- 位姿数据包大小：56字节/帧
- 视频编码比特率：动态调整（2-8Mbps）
- 网络容错：3次重传+前向纠错

### TIP
### 必要软件
- PICO企业设置（如遇USB网络分享问题，请联系我们）
