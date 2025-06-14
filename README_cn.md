# XRoboToolkit-Unity-Client 项目说明

## 项目概述
`XRoboToolkit-Unity-Client` 是一个基于PICO设备用Unity引擎开发的服务于机器人训练与遥控的软件。本软件与PC端软件协助完成机器人的训练与遥控。
## 功能特性
- **训练数据录制**可以将VST图像与位姿数据同步录制为mp4文件保存到本机的Download目录。
- **机器人遥控**：将本机位姿数据传输到PC机器人端，用来遥控机器人。
- **图像的编解码**：可以将本机的VST图像进行编码发送，也可以将PC端的图像进行解码显示。

## 目录结构

### Assets
Unity 项目的核心资源文件夹，包含了项目中使用的所有资源。
- **InteractionTools**：XR交互相关的代码与模型资源。
- **Plugins**：包含了提供Android接口的robotassistant_lib.aar和其他android平台配置。
- **Resources**：本项目相关的资源。
- **Scripts**：存放项目的脚本文件。
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
