# 常见问题说明
## iptables转发策略默认为DROP
这是由安卓兼容引起的。因为安卓兼容依赖docker.io，而docker修改了系统默认的防火墙规则,把FORWARD改为DROP。

可在终端执行以下命令，把三个服务设为开机不启动，FORWARD即为ACCEPT。

- systemctl disable kydroid-daemon.service（或是 systemctl disable kydroid2-daemon.service）

- systemctl disable docker.socket

- systemctl disable docker.service

<br>
