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
#include <QFile>
#include <QtCore>
#include "daemon_main_controller.h"
#include "ipc/daemon_ipc_dbus.h"

MainController* MainController::mSelf = 0;
MainController* MainController::self()
{
    if (!mSelf) {
        mSelf = new MainController;
    }
    return mSelf;
}

MainController::MainController()
{
    daemonIpcDbus = new DaemonIpcDbus;
    daemonIpcDbus->init();
}


MainController::~MainController()
{

}

