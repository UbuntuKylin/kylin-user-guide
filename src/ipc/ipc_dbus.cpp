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
    creatDBusService();
}

IpcDbus::~IpcDbus()
{

}
void IpcDbus::creatDBusService()
{
    // 用于建立到session bus的连接
    QDBusConnection bus = QDBusConnection::sessionBus();
    // 在session bus上注册名为"com.kylin_user_guide.hotel"的service
#define SERVICE_NAME_SIZE 64
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

void IpcDbus::showGuide(QString appName)
{
    qDebug()<<"showGuide:"<<appName;
    MainController::self()->showGuide(appName);
}

void IpcDbus::showGuide(int i)
{
    qDebug()<<"showGuide:"<<i;
}

