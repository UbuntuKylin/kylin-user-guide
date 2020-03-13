/*
 * Copyright (C) 2019 National University of Defense Technology(NUDT) & Kylin Ltd.
 *
 * Authors:
 *  xiaoyi wu    wuxiaoyi@kylinos.cn
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <QDebug>
#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusReply>
#include <QtDBus/QDBusConnectionInterface>
#include <unistd.h>
#include "ipc_dbus.h"
#include "main_controller.h"

IpcDbus::IpcDbus()
{

}

void IpcDbus::init()
{
    if(IsNotRunning())
    {
        creatDBusService();
        qDebug()<<"--------------creatDBusService";
    }
    else
    {
        if(gStartShowApp == "")
            notifyGuideWidgetActive();
        else
            notifyGuideWidgetActive(gStartShowApp);
        exit(0);
        qDebug()<<"--------------notifySettingsWidgetActive";
    }

}

IpcDbus::~IpcDbus()
{

}

void IpcDbus::creatDBusService()
{
    // 用于建立到session bus的连接
    QDBusConnection bus = QDBusConnection::sessionBus();
    // 在session bus上注册名为"com.kylin_user_guide.hotel"的service

    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_GUI_SERVICE,getuid());

    if (!bus.registerService(service_name)) {  //注意命名规则-和_
            qDebug() << bus.lastError().message();
            exit(1);
    }
    // "QDBusConnection::ExportAllSlots"表示把类Hotel的所有Slot都导出为这个Object的method
    bus.registerObject("/", this ,QDBusConnection::ExportAllSlots);
}

int IpcDbus::IsNotRunning()
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

void IpcDbus::notifyGuideWidgetActive()
{
    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_GUI_SERVICE,getuid());

    QDBusInterface iface(service_name, KYLIN_USER_GUIDE_GUI_PATH, KYLIN_USER_GUIDE_GUI_INTERFACE, QDBusConnection::sessionBus());
    if(!iface.isValid()){
        qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
    }
    iface.call("ActiveGuideWidget");
}

void IpcDbus::notifyGuideWidgetActive(QString appName)
{
    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s_%d",KYLIN_USER_GUIDE_GUI_SERVICE,getuid());
    // 用来构造一个在D-Bus上传递的Message
    QDBusMessage m = QDBusMessage::createMethodCall(QString(service_name),KYLIN_USER_GUIDE_GUI_PATH,KYLIN_USER_GUIDE_GUI_INTERFACE,"ShowGuideGUI");
    // 给QDBusMessage增加一个参数;
    // 这是一种比较友好的写法，也可以用setArguments来实现
    m << appName;

    bool bRet;
    // 发送Message
    QDBusMessage response = QDBusConnection::sessionBus().call(m);
    // 判断Method是否被正确返回
    if (response.type()== QDBusMessage::ReplyMessage)
    {
        // QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值;
        bRet = response.arguments().at(0).toBool();
    }
    else
    {
        qDebug()<<"showGuide In fail!\n";
    }

    qDebug()<<"bRet:"<<bRet;
}


bool IpcDbus::ActiveGuideWidget()
{
    qDebug() << Q_FUNC_INFO;
    MainController::self()->showGuide();
    return true;
}

bool IpcDbus::ShowGuideGUI(QString appName)
{
    qDebug() << Q_FUNC_INFO << appName;
    MainController::self()->showGuide(appName);
    return true;
}

bool IpcDbus::ShowGuideGUI(int i)
{
    qDebug()<<"showGuide:"<<i;
    return false;
}

