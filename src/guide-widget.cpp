/*
 * Copyright (C) 2013 ~ 2020 National University of Defense Technology(NUDT) & Kylin Ltd.
 *
 * Authors:
 *  Xiaoyi Wu    xiaoyiwu@ubuntukylin.com
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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>
#include <QTextStream>
#include <iostream>
#include <QDesktopWidget>
#include <QPainter>
#include <QComboBox>
#include <QScrollBar>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QApplication>
#include <QToolTip>

#include "guide-widget.h"
#include "main_controller.h"
#include "common-tool/comm_func.h"

GuideWidget::GuideWidget(QWidget *parent) :QWidget(parent)
{
    this->isTopLevel();
    this->setFixedSize(700,540);
    this->setWindowIcon(QIcon(":/picture/sogou130x130.png"));
    this->setWindowTitle(GUIDE_WINDOW_TITLE);
    //去掉窗口管理器后设置边框不生效了，所以下面通过背景图标提供边框,并且支持最小化。
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap("://picture/backImage-700x540.png")));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

    initSettings();
    initUI();
}

GuideWidget::~GuideWidget()
{

}

void GuideWidget::initUI()
{
    QWidget *tmpWidget = new QWidget();
    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(tmpWidget);

    main_layout->setSpacing(0);
    main_layout->setMargin(0);
    main_layout->setContentsMargins(1, 1, 1, 1);
    this->setLayout(main_layout);
}

void GuideWidget::initSettings()
{

}
void GuideWidget::mousePressEvent(QMouseEvent *event)
{
     mouseinwidget = false; //避免在其他控件上按下鼠标移动出现位置不正确问题
     if(event->pos().y()>=0&&event->pos().y()<=30)
         mCanDrag = true;
     else
         mCanDrag = false;
    if (event->button() == Qt::LeftButton) {
        mouseinwidget = true;
        dragPos = event->globalPos() - frameGeometry().topLeft();
    }
    event->accept();
}

void GuideWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton )
    {
        if(mouseinwidget&&mCanDrag)
            move(event->globalPos() - dragPos);
    }
    event->accept();
}

void GuideWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mouseinwidget = false;
    }
    event->accept();
}

void GuideWidget::closeEvent(QCloseEvent *)
{
//    QApplication* app;
//    app->quit();
}

