# Kylin Control Center
## Overview
Kylin Control Center provides a graphic interface to manage the system general settings.

It can be divided into two categories:

- **System Configuration** -- Including desktop environment and system level settings

- **Hardware Configuration** -- Including hardware devices settings
 
![Fig 1 Kylin Control Center-big](image/1.png)
<br>

## System Configuration
### Personalization
#### Wallpaper
Set the background of the current desktop, the lay style, and add/delete wallpapers, as shown in Fig 2.
 
![Fig 2 Wallpaper-big](image/2.png)

#### Theme
There provides two types to choose.
 
![Fig 3 Theme-big](image/3.png)

#### Font
Set the font and font size, as shown in Fig 4.
 
![Fig 4 Font-big](image/4.png)

Click "Restore Defaults" to cancel the all changes.

#### Lockscreen Wallpaper
Choose lockscreen background from the list.

![Fig 5 Lockscreen wallpaper-big](image/5.png)

### Autostart
List the autostart softwares existed in the system already: left shows the name and right shows the status.
 
![Fig 6 Autostart-big](image/6.png)

### Default App
Set the default app to open the corresponding files.
 
![Fig 7 Default app-big](image/7.png)

### Time Dates
There are two ways to synchronize time:

- Check "With the network time synchronization" -- Synchronize time with the network NTP server, and it's not allowed to modify time.

- Uncheck "With the network time synchronization" -- Synchronize time with the local computer's RTC.
 
![Fig 8 Time dates-big](image/8.png)

### User Account
- Manage all users in the system.

- Allow administrators to create/delete users and modify user's informations.

- There must be a administrator at least.

![Fig 9 User account-big](image/9.png)
<br>

## Hardware Configuration
### Keyboard
It provides three tabs: General, Layouts and Shortcut.
 
![Fig 10 Keyboard-big](image/10.png)

Include repeat keys, keyboard tips, other languages layouts, edit/add/delete shortcut, etc..

### Mouse
Include habitual hand, pointer moving speed, mouse wheel speed, etc..
 
![Fig 11 Mouse-big](image/11.png)

### Sound
There're 5 tabs, and users can set the volume of output, alert, input, etc., the effects of sound, the devices of input/output, etc..
 
![Fig 12 Sound-big](image/12.png)

### Network Agent
There are 3 options to be selected, and only can choose one.

![Fig 13 Network agent-big](image/13.png)

### Monitor
The interface as shown below.
 
![Fig 14 Monitor-big](image/14.png)

- Open/Close Monitor only can be selected when there are more than 1 opening monitor.

- The resolution, refresh, direction are all for the current monitor.

- There only exists one primary monitor.

### Power Management
- The power interface as shown below.

(Tips: The options depend on the platforms, and the picture only for reference.)

![Fig 15 Power-big](image/15.png)

- The screensaver interface as shown below.
 
![Fig 16 Screensaver-big](image/16.png)

### Network Connections
Click network icon on the tray bar > "Edit Connections" can also open the configuration interface.

![Fig 17 Network connection](image/17.png)

Users can edit the existed connections or create new connections.

"Ethernet" tab -- Choose a net device

"IPv4  Settings" tab -- Configure IP, Gateway, etc.. And users can select the method, such as Automatic, Manual.

![Fig 18 Edit connection](image/18.png)
<br>

## Q&A
### No respond after clicking "Settings" on "Start Menu"
Press Ctrl + Alt + T to open terminal, and execute "kylin-control-center" to see the error informations.

### The status returns back immediately after modifing
Probably because of the permission problem.

Press Ctrl + Alt + T, and execute "rm ~/.config/dconf/user".

And then modify it again.
