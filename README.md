# BerxelSDK_ROS2_riscv64

[中文文档](README_cn.md)

Berxel camera SDK (riscv64) with ROS 2 package `berxel_camera_ros2`.

## Setup

1. Sample apps under `samples/` need OpenGL installed if you run them.
2. First time on a machine: run `install.sh` as root, then unplug/replug the device.
3. Load library path: `source berxel_set_env.sh`
4. ROS driver is under `RosSDKNode/berxel_camera_ros2`. Build/use that package in a ROS 2 workspace; keep SDK libs available via `berxel_set_env.sh` (or equivalent `LD_LIBRARY_PATH`).

## Launch

```bash
ros2 launch berxel_camera_ros2 berxel_camera.launch.py
ros2 launch berxel_camera_ros2 berxel_camera_multi.launch.py
```

Configs: `RosSDKNode/berxel_camera_ros2/config/`  
Driver notes: `RosSDKNode/berxel_camera_ros2/README_EN.MD`

## Layout

| Path | Content |
| ---- | ------- |
| `Include/`, `libs/` | Headers and shared libraries |
| `RosSDKNode/berxel_camera_ros2/` | ROS 2 driver |
| `samples/` | Native samples |
| `Documentation/` | Vendor PDFs |
| `install.sh`, `berxel_set_env.sh` | Install / env helpers |
| `RosSDKNode/berxel_camera_ros2/scripts/99-berxel-camera.rules` | udev rules |

## License

Apache-2.0 — see [LICENSE](LICENSE).
