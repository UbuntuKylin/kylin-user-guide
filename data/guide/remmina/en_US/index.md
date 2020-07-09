# Remmina
## Overview
Remmina provides the function that connect to remote computers through VNC (graphic) or SSH (terminal). The main interface as shown in Fig 1.

![Fig 1 Remmina](image/1.png)
<br>

## Basic Function
Icons and Function:

| Icon | Function | Icon | Function |
| :------------ | :------------ | :------------ | :------------ |
|![](image/icon1.png)| Connect to the selected remote desktop |![](image/icon5.png)| Create a new connection |
|![](image/icon2.png)| Copy a connection |![](image/icon6.png)| Edit a connection
|![](image/icon3.png)| Delete |![](image/icon7.png)| Open preferences

<br>

### New Connection Steps
Click "![](image/icon5.png)" to create a new connection. Taking SSH for example, connect to the computer with IP address 172.19.40.86.

1) Ensure the sshd service is running on two computers.

The preferences window as shown in Fig 2.

![Fig 2 Remote desktop preferences](image/2.png)

2) Select SSH

"Server" box : Input IP address 172.19.40.86

"SSH Authentication" - "User name" : Input the name of connected computer

![Fig 3 Input informations](image/3.png)

Click "Connect" and input the password of connected computer. If it's first time to connect to this computer, users are needed to trust the new public key.

![Fig 4 Connecting-big](image/4.png)

3) After authenticated, the interface as shown in Fig 5.

![Fig 5 Connect successfully](image/5.png)

### Preferences
Click "![](image/icon7.png)" or "Edit" > "Preferences" to customize the remmina settings, as shown in Fig 6.

![Fig 6 Preferences](image/6.png)
<br>

## Advanced Function
### View
Click "View" to select the items displayed on the window.

![Fig 7 View](image/7.png)

### Import & Export
Click "Tools" > "Import" to import a file of other connection, or click "Tools" > "Export" to generate a configuration file from a connection.

### Plugins
CLick "Tools" > "Plugins" to see the current plugins' informations, such as name, type, etc., as shown in Fig 8.

![Fig 8 Plugins](image/8.png)
<br>

## Appendix
### Shortcut Key

| Shortcut | Function |
| :------------ | :------------ |
| Ctrl+O | Connect |	
| Ctrl+N | New |	
| Ctrl+C | Copy |	
| Ctrl+E | Edit |	
| Ctrl+D | Delete |	
| Ctrl+X | Quit |	
| Ctrl+P | Preferences |	
