# Enterprise Collection Data Guide

## 目的

这份文档用于说明：

- 头显端录制数据保存在哪里
- 如何手动查看和拉取录制结果
- 每种文件分别表示什么
- 如何理解 `采样频率` 和 `有效频率`
- 当前已验证的一组右手柄有效频率结论

## 头显端存盘目录

当前项目的 Enterprise 采集文件默认保存到：

```text
/storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/
```

每次录制会生成一个时间戳目录，例如：

```text
/storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/20260713_150503/
```

## 常见文件说明

一个录制目录里通常包含以下文件：

- `enterprise_head.jsonl`
  - 企业服务采集到的头显数据
- `enterprise_controller_pose.jsonl`
  - 企业服务采集到的左右手柄 Pose 数据
- `unity_head.jsonl`
  - Unity/PICO/XR 主线程采集到的头显数据
- `unity_controller_pose.jsonl`
  - Unity/PICO/XR 主线程采集到的手柄 Pose 数据
  - 如果当前代码中禁用了 Unity 手柄采集，这个文件可能不存在
- `meta.json`
  - 本轮录制的元信息，例如是否启用文件写入、采样频率、录制时长等

## 手动查看头显端数据

### 方法 1：用 adb 查看目录

查看录制目录列表：

```powershell
adb shell ls -1 /storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection
```

查看某一轮录制目录内的文件：

```powershell
adb shell ls -l /storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/20260713_150503
```

### 方法 2：把数据拉到本地

把某一轮录制拉到本地：

```powershell
adb pull /storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection/20260713_150503 .\PulledData\EnterpriseCollection_20260713_150503
```

## 一键拉取最新一轮

如果只想拉最新目录，可以在 PowerShell 中执行：

```powershell
$remoteBase = "/storage/emulated/0/Android/data/com.xrobotoolkit.client/files/EnterpriseCollection"
$latest = adb shell ls -1 $remoteBase | ForEach-Object { $_.Trim() } | Sort-Object | Select-Object -Last 1
adb pull "$remoteBase/$latest" ".\PulledData\EnterpriseCollection_$latest"
```

## 如何理解频率

### 1. 采样频率

采样频率指的是录制线程调用接口、写入 JSONL 的频率。

例如：

- 文件总行数：`26040`
- 录制时长：`32.757s`

那么采样频率约为：

```text
26040 / 32.757 = 794.945 Hz
```

### 2. 有效频率

有效频率不是看“调用了多少次”，而是看“数据值真正变化了多少次”。

对于手柄 Pose，当前采用的判定口径是：

- 只要 `right.pose.pose` 整串字符串发生变化
- 就认为这是一帧新的有效数据

如果连续多帧 `pose` 完全一样，则这些帧虽然被采到了，但不算新增有效数据。

## 当前已验证结果

分析文件：

```text
PulledData/EnterpriseCollection_20260713_150503/enterprise_controller_pose.jsonl
```

针对右手柄 `data.right.pose.pose` 的分析结论：

- 总采样条数：`26040`
- 总时长：`32.757s`
- 采样频率：约 `794.945 Hz`
- 有效变化段数：`14362`
- 右手柄有效频率：约 `438.441 Hz`

这说明：

- 虽然录制线程接近 `795Hz` 在取数
- 但右手柄 Pose 真正发生变化的频率大约只有 `438Hz`
- 高于 `500Hz` 持续轮询时，确实会出现多帧连续相同值

## 重复帧情况

针对右手柄 Pose 的重复情况：

- 平均每个 Pose 会连续重复：`1.813` 帧
- 最长连续重复：`11` 帧
- 重复帧占比约：`44.8%`

重复段分布：

- 连续 1 帧：`8021`
- 连续 2 帧：`3512`
- 连续 3 帧：`1503`
- 连续 4 帧：`688`
- 连续 5 帧及以上：`638`

这说明在“右手柄持续运动”的情况下，仍然存在明显的重复帧，当前链路尚不能把 `1000Hz` 全部转化为有效 Pose 更新。

## 当前建议

如果后续评估右手柄数据链路的“实际有效频率”，建议优先使用：

```text
约 438 Hz
```

如果只是评估“采样线程实际跑到了多少次”，则看：

```text
约 795 Hz
```

这两个数字代表的含义不同，分析时不要混用。
