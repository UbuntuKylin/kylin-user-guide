/*
 * Copyright (C) 2020, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <QDebug>
#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusReply>
#include <QtDBus/QDBusConnectionInterface>
#include <QProcess>
#include <unistd.h>
#include "daemon_ipc_dbus.h"
#include "main_controller.h"

DaemonIpcDbus::DaemonIpcDbus()
{

}

void DaemonIpcDbus::init()
{
    if(daemonIsNotRunning())
    {
        creatDBusService();
        qDebug()<<"--------------creatDBusService";
    }
    else
    {
        qDebug()<<"Daemon is Running";
        exit(0);
    }

}

DaemonIpcDbus::~DaemonIpcDbus()
{

}

void DaemonIpcDbus::creatDBusService()
{
    // 用于建立到session bus的连接
    QDBusConnection bus = QDBusConnection::sessionBus();
    // 在session bus上注册名为"com.kylin_user_guide.hotel"的service

    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_SERVICE,getuid());

    if (!bus.registerService(service_name)) {  //注意命名规则-和_
            qDebug() << bus.lastError().message();
            exit(1);
    }
    // "QDBusConnection::ExportAllSlots"表示把类Hotel的所有Slot都导出为这个Object的method
    bus.registerObject("/", this ,QDBusConnection::ExportAllSlots);
}

int DaemonIpcDbus::daemonIsNotRunning()
{
    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_SERVICE,getuid());
    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.isConnected())
        return 0;

    QDBusReply<QString> reply = conn.interface()->call("GetNameOwner", service_name);
    return reply.value() == "";
}

int DaemonIpcDbus::guiIsNotRunning()
{
    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_GUI_SERVICE,getuid());
    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.isConnected())
        return 0;

    QDBusReply<QString> reply = conn.interface()->call("GetNameOwner", service_name);
    return reply.value() == "";
}

void DaemonIpcDbus::startGUI(QString appName)
{
    QString cmd = "/usr/bin/kylin-user-guide";
    QStringList list;
    list<<"-A"<<appName;
    QProcess::startDetached(cmd,list);
}

void DaemonIpcDbus::showGuide(QString appName)
{
    qDebug() << Q_FUNC_INFO << appName;
    bool bRet  = false;
    if(guiIsNotRunning())
    {
        startGUI(appName);
        return;
    }
    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_GUI_SERVICE,getuid());
    // 用来构造一个在D-Bus上传递的Message
    QDBusMessage m = QDBusMessage::createMethodCall(QString(service_name),KYLIN_USER_GUIDE_GUI_PATH,KYLIN_USER_GUIDE_GUI_INTERFACE,"ShowGuideGUI");
    // 给QDBusMessage增加一个参数;
    // 这是一种比较友好的写法，也可以用setArguments来实现
    m << appName;

    // 发送Message
    QDBusMessage response = QDBusConnection::sessionBus().call(m);
    // 判断Method是否被正确返回
    if (response.type()== QDBusMessage::ReplyMessage)
    {
        // QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值;
        bRet = response.arguments().at(0).toBool();
    }
    else {
        qDebug()<<"showGuide In fail!\n";
    }

    qDebug()<<"bRet:"<<bRet;
}

void DaemonIpcDbus::showGuide(int i)
{
    qDebug()<<"showGuide:"<<i;
}

