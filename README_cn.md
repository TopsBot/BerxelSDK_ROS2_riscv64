# BerxelSDK_ROS2_riscv64

[English](README.md)

Berxel 相机 SDK（riscv64）及 ROS 2 功能包 `berxel_camera_ros2`。

## 使用说明

1. 若运行 `samples/` 下示例，需事先安装 OpenGL。
2. 设备首次在本机使用：以 root 执行 `install.sh`，然后拔插设备。
3. 设置库路径：`source berxel_set_env.sh`
4. ROS 驱动位于 `RosSDKNode/berxel_camera_ros2`，放入 ROS 2 工作空间编译使用；并通过 `berxel_set_env.sh`（或等价方式）保证能找到 SDK 动态库。

## Launch

```bash
ros2 launch berxel_camera_ros2 berxel_camera.launch.py
ros2 launch berxel_camera_ros2 berxel_camera_multi.launch.py
```

配置文件：`RosSDKNode/berxel_camera_ros2/config/`  
驱动说明：`RosSDKNode/berxel_camera_ros2/README.MD`

## 目录

| 路径 | 内容 |
| ---- | ---- |
| `Include/`、`libs/` | 头文件与动态库 |
| `RosSDKNode/berxel_camera_ros2/` | ROS 2 驱动 |
| `samples/` | 原生示例 |
| `Documentation/` | 厂商 PDF |
| `install.sh`、`berxel_set_env.sh` | 安装 / 环境脚本 |
| `RosSDKNode/berxel_camera_ros2/scripts/99-berxel-camera.rules` | udev 规则 |

## 许可证

Apache-2.0，见 [LICENSE](LICENSE)。
