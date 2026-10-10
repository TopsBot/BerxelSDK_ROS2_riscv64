#install.sh
Password="root"

#move rules to /etc/udev/rules.d
echo $Password | sudo -S cp 99-berxel-camera.rules /etc/udev/rules.d
echo $Password | sudo -S udevadm control --reload-rules
