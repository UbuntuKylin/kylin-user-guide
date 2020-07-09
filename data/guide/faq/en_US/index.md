# FAQ
## iptables forward policy is DROP by default
It caused by Kydroid. Because Kydroid depends on docker.io and docker modifies the default rules of firewall.

Execute the commands listed below and FORWARD can be ACCEPT.

- systemctl disable kydroid-daemon.service (or systemctl disable kydroid2-daemon.service)

- systemctl disable docker.socket

- systemctl disable docker.service

<br>
