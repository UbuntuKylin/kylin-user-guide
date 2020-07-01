# UKUI Control Center 
## Overview
The control center provides a user-friendly graphical user interface for managing common operating system configuration items. 

The control center boils down common configurations into two categories, system configuration and hardware configuration. 

The system configuration mainly contains the desktop environment and system level configuration items; the hardware configuration mainly contains the computer hardware and its related configuration items.

![Fig. 1 Control Center Main Interface -big](image/1.png)

## System 
The system configuration settings provide four modules: monitor, default application, power, and power-on.

### Display
The display can be configured to display related settings.

![Fig. 2 Display settings-big](image/2.png)

####  Monitor
The monitor settings can be selected for the current monitor, adjusting the screen resolution, orientation, screen refresh rate, etc.

The upper colored rectangle represents the current screen, with the monitor name and interface name displayed in the middle.

The drop-down list on the right side of the monitor contains all the current monitors, and these are active. If users need to set the selected monitor as the main screen, then click "set as home screen" . And there is and only one home screen at the same time.

All configuration changes to resolution, refresh rate, etc. are for the currently active monitor.

**Resolution:** The drop-down list on the right contains a list of resolutions supported by the system and monitor.The resolution of the currently active monitor can be toggled by the drop-down list, and the change will take effect.

**Orientation:**The drop-down list on the right contains 4 options: arrow-up, 90°arrow-right,arrow-down,90°arrow-left, check to make the change real.

**Refresh Rate:**The drop-down list on the right contains the list of the current refresh rate supported by the monitor at the current resolution automatically and 50Hz, checked to make the change real.

All monitors display the home screen image: this option needs to be changed only if there are multiple monitors and the change is true by turning on their on/off buttons.

#### Night mode
Turn on the night mode, the user can modify the time and set the monitor on drink off time to adjust the color temperature of the monitor.

![Fig. 3 Night mode -big](image/3.png)

### Defaultapp
The default application provides configuration items for the system's default application, which can modify the default open application for six types of Browser, Mail, Image Viewer, Video Player, Audio Player, and Text Editor. 

![Fig. 4 Default application-big](image/4.png)

### Power
The Power management offers three power plans : Balance(suggest) mode, Saving Minimize performance mode, custom mode are provided for the user to choose. 

User-defined Power supply or Battery powered, and screen protection settings: 30 minutes for the computer to go to sleep, 30 minutes for the system to turn off the monitor.

![Fig. 5 System power settings-big](image/5.png)

### Autoboot
Autoboot provides configuration management functions for the booting software.

![Fig. 6 boot up](image/6.png)

The list shows the boot software that already exists on the current system, the left side of the list is the software name; the right side of the list is the boot status of the corresponding software.

The switch button on the right side of the list represents the boot state of the software on the left side, open means the software starts with boot; otherwise it means the software does not start. Status can be switched by clicking the on/off button.

Click "+" to add the boot application button to bring up the add window.

![Fig. 7 Autoboot added](image/7.png)

#### Add autoboot app
(1) Fill in the "Program name".

(2) fill in the "program exec", pay attention to ensure that the command is legal and valid or by clicking the "Open" button, in the pop-up file selection interface, select the file with the suffix "desktop" and the program will automatically parse and export the command data in the desktop file.

(3) "Description of the procedure" is optional and may be filled in.

(4) Finally, by clicking the "Certain" button, a new start-up item is created and displayed in the list.

(5) The newly created startup item defaults to the boot-up state.

<br>

## Equipment
Device Setup provides six setup modules for the printer, mouse, touchpad, keyboard, shortcut keys, and voice.

### Printer
Through The control center Devices > Printer, the user can add printers and scanners, and a list of available printers and scanners will be displayed below.

![Fig. 8 Printer Equipment-big](image/8.png)

### Mouse
The control center Devices > Mouse allows users to personalize the Mouse key settings, Pointer settings and cursor.

![Fig. 9 mouse device -big](image/9.png)

### Touchpad
Through The control center device > touchpad, the touchpad can be turned on and personalized according to the user's needs: Disable touchpad while typing, Enable the mouse clicks with touchpad, Scrolling(supports vertical boundary scrolling) , etc.

![Fig. 10 touchpad settings-big](image/10.png)

### Keyboard
The keyboard module in The control center device allows for general settings of the keyboard and the ability to adjust the keyboard layout  according to the keyboard language.

![Fig. 11 keyboard -big](image/11.png)

#### Keys settings
General Settings mainly sets the basic settings related to keyboard input.

![Fig. 12 Keys Settings](image/12.png)

When you turn on the Enable Key Repeat setting and activate the Repeat Key function, the system will enter the behavior as a repeated uninterrupted keyboard input when a certain key is pressed and not released; when you turn it off, the system will enter the behavior as a keyboard input when a certain key is pressed and not released.

When the key repeat setting is enabled, the delay and speed options can be set.

**Delay:**The slider on the right side is used to set the interval between pressing a key and the system starting to receive keyboard input, near the "short" direction, the shorter the interval, the faster the system starts to receive keyboard input; and vice versa.

**Speed:** The slider on the right is used to set the interval between repetitive inputs after the button is pressed, near the "slow" direction, the longer the interval, the less the number of repetitive inputs in the same time; and vice versa.

**Enter characters to test repetition speed:**The text box below is used to test the effect of the settings. Left mouse click on the text box to get the input focus and press a button to see the effect in real time.

<br>

#### Keyboard Layout 
Set the keyboard layout of the current system.

![Fig. 13 Keyboard layout Settings](image/13.png)

The keyboard language drop-down menu displays a list of installed keyboard layout, and up to 4 keyboard layout can be added.

Click "Install layouts" to add another language.

<br>

### Shortcut
Shortcut allow users to make changes to system shortcuts, and custom shortcuts can be added or removed. View all the shortcuts in the system via The control center Device > Shortcuts key.

![Fig. 14 shortcut setting-big](image/14.png)

There are currently two categories of shortcuts: system shortcuts and custom shortcuts.

**System Shortcut:** Only hotkey key values can be modified.

**Custom Shortcut:**These are user shortcuts that can be added, deleted, or modified.

Click the "Add Custom Shortcut" button to bring up the Shortcut Add screen.

![Fig. 15 Add Shortcut](image/15.png)

Fill in the shortcut name and shortcut exec, note that to ensure that the command is legal and valid, if it is occupied, it will be prompted at the bottom: this shortcut key has been occupied by "open terminal", please reset.

In this case, users need to reset it, and after clicking "Certain" if the shortcut is set legally, the shortcut will be added successfully and take effect immediately.

<br>

### Audio
Input, output, and system sound can be set via Control Center Devices > Sound.

![Fig. 16 Audio Device-big](image/16.png)

#### Output
The output provides the relevant configuration of the output device.

![Fig. 17 Audio Device Output Settings-big](image/17.png)

**Select Output Device:**The list shows all available sound output devices for the current system, switch output devices by clicking the radio button.

**Master Volume Size:** Adjusts the master volume size of the output device.

**Channel balance:** users can set the channel for the selected output device, near "left" for the left channel and near "right" for the right channel.

<br>

#### Input
The input provides the relevant configuration of the input device.

![Fig. 18 Audio Device Output Settings-big](image/18.png)

**Select Input Device:** The list lists all the current input devices, select the input device by clicking the radio button.

**Volume:** users can configure the input volume size of the input settings.

**Input level:** users can configure the level of sound input device, near "low" direction is low level, near "high" direction is advanced.

<br>

#### System sound
System sound provides settings for system sound themes and personalized settings for the prompt tones for power on, log off, wake up, operation success, etc.

![Fig. 19 System Sound Settings-big](image/19.png)

There is two sound theme for the current system: Default and Ubuntu.

The initial sound effects provide four effects: bark, raindrops, glass, and sonar, which can be switched by clicking the corresponding option. 

<br>

## Personalization
Personalization provides six modules for background, theme, screenlock, font, screensaver, and desktop settings.

<br>

### Background
The background module targets desktop backgrounds and provides users with a choice of two background forms: image and color.

<br>

#### Picture
Desktop Background > Select Background Form: image.

![Fig. 20 image background settings-big](image/20.png)

Browse the thumbnails in the background list, encounter the intention background directly click the thumbnail desktop background is set successfully.

Click "Browse Local Wallpaper" to bring up the file selection screen.

![Fig. 21 background-add](image/21.png)

Clicking "Delete Wallpaper" will remove the current desktop background from the background list and the next wallpaper file will be set as a new desktop background.

<br>

#### Color
Desktop Background > Select Background Form: color. 

![Fig. 22 Solid Color Background Settings -big](image/22.png)

### Theme
Theme include theme mode, icon theme, space theme, cursor theme, effect settings five panels.

![Fig. 23 personalization settings-big](image/23.png)

<br>

#### Theme mode
The theme mode provides users with two themes to switch: system default, dark color mode, according to user needs, check the corresponding theme mode.

![Fig. 24 Theme Mode](image/24.png)

#### Icon Theme
Icon themes provide users with two themes to switch: basic, classic, default, according to user needs, check the corresponding icon theme.

![Fig. 25 Icon Theme-big](image/25.png)

#### Cursor theme
The cursor theme provides several kinds of themes for users to choose, according to the user's needs, select the cursor theme users want to set.

![Fig. 26 cursor theme-big](image/26.png)

#### Effect Setting
Turn on the transparent effects switch, near "low" direction for low transparency, near "high" for high transparency.

![Fig. 27 Effect Settings-big](image/27.png)

### Lock screen
The lock screen module for the lock screen interface provides users background images.

Users can set the time required for the computer to turn on the lock screen by selecting the button that displays the lock screen background image on the login screen.

![Fig. 28 Lock screen settings-big](image/28.png)

### Font
The Font module provides configuration items for system fonts and font sizes. Users can set the font and its size and width according to the requirements, provide the corresponding font settings in the advanced settings.

Click the "Reset to default" button to restore all font settings to the system default state.

![Fig. 29 font-set-big](image/29.png)

### Screensaver
Users can set the screensaver through Personalization > Screen Saver, turn on the screen saver, and set the waiting time for turning on the screensaver.

![Fig. 30 Screensaver-set-big](image/30.png)

### Desktop
Users can set the start menu and set the icon locked in the start menu through Personalization > Desktop.

![Fig. 31 Desktop-set-big](image/31.png)

## Network
Network proxy is mainly to configure. network proxy related settings, divided into Netconnect, VPN, Proxy three modules.

![Fig. 32 network settings-big](image/32.png)

###  Netconnect
#### Netconnect status
The user can view the current network connection status through the network status panel in the network connection module.

![Fig. 33 Current network status-big](image/33.png)

#### Available Networks
The currently available networks can be viewed within the list of available networks.

![Fig. 34 List of available networks-big](image/34.png)

### VPN
In the VPN module, users can add a VPN connection by clicking "Add VPN Connect", editing the name, selecting the type, setting the server address, etc.

![Fig. 35 VPN Settings-big](image/35.png)

###  Proxy
The proxy module is usually divided into two modes that can be connected to the Internet automatically (i.e., auto proxy) and manual proxy, and only one of the two modes can exist at the same time.

![Fig. 36 Proxy settings-big](image/36.png)

#### Auto Proxy
Select Auto Settings i.e. the current system does not set the proxy, directly access the Internet, click the switch button of Auto Settings proxy.

![Fig. 37 Auto Proxy-big](image/37.png)

#### Manual Proxy
When there is a clear proxy agreement, such as Http proxy, Https proxy, Ftp proxy, Socks proxy, users can choose to configure. the proxy manually, the proxy server IP address and port number into the corresponding text box. In addition, the Http proxy can configure. proxy authentication here, thus eliminating the authentication window that pops up when accessing the network. Click the "Cetification" button to bring up the authentication interface.

![Fig. 38 Manual Proxy-big](image/38.png)

## Account
The account provides administrative configuration of system users, allowing administrators to create users, delete users, and modify user information.

![Fig. 39 Account Information Settings-big](image/39.png)

### Current User
#### Modify user avatar
Click on the user avatar to modify the user avatar, the picture can be selected from the local picture.

![Fig. 40 Modify user avatar](image/40.png)

#### Change password
Users can change the password of their current account by clicking "Change pwd".

![Fig. 41 Change password](image/41.png)

#### Change type
There are two types of system users, standard users and administrators. The difference is that administrators can temporarily enhance root privileges by entering their own password; standard users cannot enhance their privileges. Users can switch from regular user to administrator by clicking on "Change type".

Click the left mouse button to select the radio button, then click the Confirm button to update the user type of the current user. 

Note: The system needs to have at least one administrator user, so the last remaining administrator user cannot modify the user type to a standard user.

And a standard user switching to an administrator needs to know the password of any system administrator to be allowed to switch.

Tips:The current user cannot delete himself/herself.

![Fig. 42 Change user type](image/42.png)

### Other users
In the Other Users section, users can edit other users' avatars and account types to match the current account settings, and add/delete operations to other users.

Other users' account avatars show the default system avatar, click the account avatar area to bring up the system avatar list, click the avatar file in the list or click "Select face from local" in the pop-up list to select a custom avatar file, and the avatar in the avatar setting area is updated to the latest avatar.

![Fig. 43 Other user settings-big](image/43.png)

#### Add new user
Click "Add new user" to define the Username, Password, Account type, etc.

Enter the new account name, select the password type, enter the password, confirm the password, click the user type radio button below to determine the type of the new user, click the "Confirm" button, the new user is created.

![Fig. 44 Add new user](image/44.png)

## Datetime 
Datetime settings provide two modules, date time and Area.

![Fig. 45 Datetime settings-big](image/45.png)

### Datetime 
In the Datetime, users can synchronize the system time, change the time manually, and change the time zone, set to 24-hour system or 12-hour system.

![Fig. 46 Datetime ](image/46.png)

The current state of time and date synchronization is of two kinds, one is synchronized with network time, that is, synchronized with the NTP server time on the Internet, and the other is synchronized with the local computer's clock chip time.

<br>

#### Sync system time
After selecting "Sync System Time", the computer's time is synchronized with the network NTP server's time, in this state, it is no longer allowed to modify the time or date; after canceling "Syn System Time", the computer's time is synchronized with the local computer's clock chip, in this state, you can modify the time or date.

#### Change time
Click "Change time" to set the time(hours, minutes, seconds),year, month and day.

![Fig. 47 Manually set time and date](image/47.png)

<br>

#### Change the time zone
Click on the drop-down list to the right of "Change Time Zone" to display a list of all time zones.

<br>

#### Time format
The time format is divided into 12 and 24 hours and is immediately effective by clicking the corresponding switch button on the right.

<br>

### Area
####  Current area
The current region can be set in the Area module with the default region being China.

![Fig. 48 Area -big](image/48.png)

####  Format of area
Click "Change format of data", the pop-up window is shown in figure below, you can customize the calendar, first day of the week, date, time.

![Fig. 49 Change of format data](image/49.png)

####  First language
The preferred recommended language for displaying system windows, menus and web pages is Simplified Chinese.

Users can add other area languages as an alternative to the system language by clicking "Add main language".

<br>

## Update
The Update settings provide two modules, Systenm-Update and Backup.

![Fig. 50 Update and backup main interface-big](image/50.png)

### Backup 
Backup provides two panels for backup and recovery, select "Begin Backup" to backup files to other drives, select "Start Restore" to view the list of backups and select the restore point where the system needs to be restored for recovery.

![Fig. 51 Backup settings-big](image/51.png)

## Notification & Task
Notifications and Tasks provides two modules: Notice, About Native OS.

<br>

### Notice
Notice include two panels, Notification, Set Notification Source.
#### Notification
Set to display notification messages in the Operations Center after the system version update, get notifications from applications and other senders, and display notifications on the lock screen interface.

![Fig. 52 Operation Center notification settings-big](image/52.png)

#### Set Notification Source
Take Power-manager as an example, open the switch button to set Power-manager as the notification source, settings: allow notification, set the number of notifications seen in the notification center.

![Fig. 53 set Kylin Software Center as notification source](image/53.png)

### About
In this section,users can find details about the version, version number, installation date information and equipment specification details of the local system.

![Fig. 54 about native system-big](image/54.png)

## FAQ
## Can’t start? 
No response when I click the "Control Center" button on the "Start Menu"?

Press Ctrl+Alt+t on the keyboard to open the command line terminal, type ukui-control-center and then press Enter.

View error output.
## Can’t change the configuration? 
After modifying the control state, the control immediately reverts to its pre-modification state?

It is highly likely that the reason for the above problems is due to a question of authority. Use the following methods to fix the problem.

Open the command line terminal by pressing Ctrl+Alt+t on the keyboard, enter “rm ~/.config/dconf/user” and press Enter to fix the problem.

Reconfiguration.

