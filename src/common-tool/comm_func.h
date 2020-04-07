#pragma once
#include <QString>

#define APPLICATION_NAME "用户手册"
#define GUIDE_WINDOW_TITLE "用户手册"

#define SERVICE_NAME_SIZE 64
//daemon监听app的调用传给GUI
#define KYLIN_USER_GUIDE_PATH "/"
#define KYLIN_USER_GUIDE_SERVICE "com.kylinUserGuide.hotel"
#define KYLIN_USER_GUIDE_INTERFACE "com.guide.hotel"

#define KYLIN_USER_GUIDE_GUI_PATH "/"
#define KYLIN_USER_GUIDE_GUI_SERVICE "com.kylinUserGuideGUI.hotel"
#define KYLIN_USER_GUIDE_GUI_INTERFACE "com.guide.hotel"

#define SYSTEM_FILE "/etc/os-release"

#define LOCAL_FILE_PATH "/usr/share/kylin-user-guide/data/guide/"
#define LOCAL_URL_PATH "file://///usr/share/kylin-user-guide/web/"


#define LOCAL_FILE_PATH_UBUNTUKYLIN "/usr/share/kylin-user-guide/data/guide-ubuntukylin/"
#define LOCAL_URL_PATH_UBUNTUKYLIN "file://///usr/share/kylin-user-guide/web/"

extern QString gLang;
extern QString gStartShowApp;
