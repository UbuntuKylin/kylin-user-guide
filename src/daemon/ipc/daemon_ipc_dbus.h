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

#ifndef __DAEMON_IPC_DBUS_H__
#define __DAEMON_IPC_DBUS_H__

#include <QObject>
#include "common-tool/comm_func.h"

class DaemonIpcDbus : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", KYLIN_USER_GUIDE_INTERFACE)
public:
    DaemonIpcDbus();
    void init();
    virtual ~DaemonIpcDbus();
private:
    void creatDBusService();
    int daemonIsNotRunning();
    int guiIsNotRunning();
    void startGUI(QString );

public slots:
    void showGuide(QString appName);
    void showGuide(int i);
};

#endif
