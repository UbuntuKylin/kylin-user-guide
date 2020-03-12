/*
 * Copyright (C) 2018 National University of Defense Technology(NUDT) & Kylin Ltd.
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

#ifndef __IPC_DBUS_H__
#define __IPC_DBUS_H__

#include <QObject>
#include "common-tool/comm_func.h"

class IpcDbus : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", KYLIN_USER_GUIDE_INTERFACE)
public:
    IpcDbus();
    void init();
    virtual ~IpcDbus();
private:
    void creatDBusService();
    int IsNotRunning();
    void notifyGuideWidgetActive();
    void notifyGuideWidgetActive(QString);
public slots:
    bool ShowGuideGUI(QString appName);
    bool ShowGuideGUI(int i);
    bool ActiveGuideWidget();
};

#endif // __IPC_DBUS_H__
