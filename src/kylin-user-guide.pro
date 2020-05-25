######################################################################
# Automatically generated by qmake (3.1) Sat Apr 18 11:17:25 2020
######################################################################
QT += core gui webkitwidgets dbus
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
TARGET = src
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += guide-widget.h \
           main_controller.h \
           common-tool/comm_func.h \
           ipc/ipc_dbus.h
SOURCES += guide-widget.cpp \
           main.cpp \
           main_controller.cpp \
           common-tool/comm_func.cpp \
           ipc/ipc_dbus.cpp
RESOURCES += kylin-user-guide.qrc
