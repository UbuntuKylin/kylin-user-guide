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
#include <QFile>
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include "main_controller.h"
#include "ipc/ipc_dbus.h"
#include "guide-widget.h"

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
    ipcDbus = new IpcDbus;
    ipcDbus->init();
    guideWidget = new GuideWidget;
    guideWidget->activateWindow();
    startShowApp();
    guideWidget->show();
}

void MainController::startShowApp()
{
    QTimer::singleShot(500, this, SLOT(showGuide()));//消息循环起来后打通js和qt通信在执行跳转
}

void MainController::showGuide(QString appName)
{
    if(appName!="")
        guideWidget->jump_app(appName);
    guideWidget->activateWindow();
    guideWidget->show();
}

void MainController::showGuide()
{
    if(gStartShowApp!="")
    {
        qDebug() << Q_FUNC_INFO;
        guideWidget->jump_app(gStartShowApp);
        gStartShowApp = "";
    }
    guideWidget->activateWindow();
    guideWidget->show();
}

MainController::~MainController()
{

}

