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
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QTimer>
#include "main_controller.h"
#include "ipc/ipc_dbus.h"
#include "guide-widget.h"

#include "xatom-helper.h"

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
    qDebug() << Q_FUNC_INFO << QString::fromLocal8Bit(qgetenv("XDG_RUNTIME_DIR"));
    if((""!=QString::fromLocal8Bit(qgetenv("XDG_RUNTIME_DIR")))||(""!=QString::fromLocal8Bit(qgetenv("DBUS_SESSION_BUS_ADDRESS"))))
    {
        ipcDbus = new IpcDbus;
        ipcDbus->init();
    }
    guideWidget = new GuideWidget;
    startShowApp();
}

void MainController::startShowApp()
{
    QTimer::singleShot(800, this, SLOT(showGuide()));//消息循环起来后打通js和qt通信在执行跳转
}

void MainController::showGuide(QString appName)
{
    if(appName!="")
        guideWidget->jump_app(appName);

//    qDebug() << Q_FUNC_INFO  << guideWidget->isMinimized() << guideWidget->size();
    QList<QScreen *> list = QGuiApplication::screens();
    if(guideWidget->isMinimized()){
        if(guideWidget->size() == QSize(list.at(0)->availableGeometry().width(),list.at(0)->availableGeometry().height()))
            guideWidget->showMaximized();
        else
            guideWidget->showNormal();
    }

    flags = guideWidget->windowFlags();
    guideWidget->setWindowFlags(flags|Qt::WindowStaysOnTopHint);

    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(guideWidget->winId(), hints);
    QTimer::singleShot(10, this, SLOT(setwindowFlags()));
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

void MainController::setwindowFlags()
{
    guideWidget->setWindowFlags(flags);
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(guideWidget->winId(), hints);
    XAtomHelper::getInstance()->setWindowBorderRadius(guideWidget->winId(), 6, 6, 6, 6);
    guideWidget->show();
}

MainController::~MainController()
{

}

