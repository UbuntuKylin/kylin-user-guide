# Box manager
## Overview
Box manager is developed by Kylin security team with a simple interface, and it aims to provide users with convenient and safe personal file protection.

![Fig 1 Box Manager-big](image/1.png)

Kylin Box-manager can realize the security protection and sharing of user's private data by the combination of isolation and hiding, encryption protection and sharing authorization. The features as shown below:

- Newly created personal directories (i.e. BOX, BOX directories) are visible only to the user himself and not to other users.

- Users can authorize other users to access private box with read-only or read-write permission, and access the box shared by other users.

- Users can set encryption for private box. Therefor other users need to have sharing authorization and password authentication to access encrypted box.

- Encrypted box needs to be used after mounting. The mounted box cannot be deleted or renamed; Password setting and sharing setting are not allowed, either. If the changes above are necessary, the box should be umount first. 

![Fig 2 Mount (password authentication)-big](image/2.png)

Different icons mean different states of the box directory，as shown below:

| Icon | Decription |
|:-----|:-----|
|![](image/icon1.png)| General box directory |
|![](image/icon2.png)| Encrypted box directory |
|![](image/icon3.png)| Encrypted box directory (Mount state) |
|![](image/icon4.png)| Box directory shared |
|![](image/icon5.png)| Encrypted and sharing box directory |
|![](image/icon6.png)| Encrypted and sharing box directory (Mount state) |
|![](image/icon7.png)| Box directory shared by other users |
|![](image/icon8.png)| Encrypted box directory shared by other users |
|![](image/icon9.png)| Encrypted box directory shared by other users (Mount state) |

<br>

## Basic Function
Kylin Box-manager provides box creation, rename, delete, encryption and share settings, etc., and two ways to view - icon, list. Users can operate them by using function buttons and right-click menu.

![Fig 3 Function buttons and right-click menu-big](image/3.png)

The boxes created by different user are located at "/box/[UserName]/", and users can access this directory by double-clicking the corresponding icon on the tool interface. The operations for the files and directories in the box are the same way as in general - terminal and caja are both allowed.

### New
Click "New" button to create a new private box. Input the name of the box and click "Yes", as shown in Fig 4:

![Fig 4 New-big](image/4.png)

If users want to encrypt at the same time, please open the encrypt switch and input the password, as shown in Fig 5:

![Fig 5 New-encrypt-big](image/5.png)

### Delete
Click "Delete" button to delete the box directory that users don't need anymore. Select "Yes" in the pop-up window, as shown in Fig 6.

![Fig 6 Delete-big](image/6.png)

### Rename
Right click the box directory choosing "Rename", and input the new name. If the box is encrypted: 

- Password verification is required.

- Mount state is not allowed. 

![Fig 7 Rename-big](image/7.png)

### Set Password
For unencrypted box directories, users can click "Set Password" button to encrypt them, as shown in Fig 8: 

![Fig 8 Set password-big](image/8.png)

For encrypted box directory, it can change password or removal protection. If the box is mounted, you should umount it first.

![Fig 9 Change password-big](image/9.png)

![Fig 10 Removal protection-big](image/10.png)

### Share Settings
If it's necessary to share the private box to others, you can choose the box and click "Share settings" button to set permissions for associated users in the share settings window. And then click "Apply" to make it effective. If the box is mounted, you should umount it first.

![Fig 11 Share settings-big](image/11.png)

For encrypted boxes, password authentication is required.

![Fig 12 Password authentication-big](image/12.png)

### View Switching
It provides two types of views: Icon and List. And the default is icon view.

- Icon view: When the cursor hovers over the box, it will show the detailed path.

- List view: It supports to show the detailed informations of the box, and it can filter display by encryption, sharing and creator.

To change the viewing type, click the function button at the bottom right of the window.

![Fig 13 Icon view-big](image/13.png)

![Fig 14 List view-big](image/14.png)
