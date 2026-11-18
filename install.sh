#install.sh
Password="root"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)"
RULES_FILE="${SCRIPT_DIR}/RosSDKNode/berxel_camera_ros2/scripts/99-berxel-camera.rules"

#move rules to /etc/udev/rules.d
echo $Password | sudo -S cp "${RULES_FILE}" /etc/udev/rules.d/99-berxel-camera.rules
echo $Password | sudo -S udevadm control --reload-rules && echo $Password | sudo -S udevadm trigger
