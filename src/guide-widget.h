/*
 * Copyright (C) 2013 ~ 2015 National University of Defense Technology(NUDT) & Kylin Ltd.
 *
 * Authors:
 *  Xiaoyi Wu    xiaoyiwu@ubuntukylin.com/wuxiaoyi@kylinos.com
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
#pragma once

#include <QWidget>
#include <QSplitter>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QPen>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>
#include <QStackedWidget>
#include <QCheckBox>
#include <QScrollArea>
#include <QSettings>
#include <QMap>
#include <QColorDialog>
#include <QHBoxLayout>
#include <qfontdatabase.h>
#include <QModelIndex>
#include <QStringListModel>
#include <QFileSystemWatcher>

class GuideWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GuideWidget(QWidget *parent = 0);
    ~GuideWidget();
    void initUI();
    void initSettings();
    void showPosition();
protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent * );
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    QPoint dragPos;
    bool mouseinwidget =false;
    bool isClose = false;
    bool mCanDrag = false;
private:
private:
private slots:
public slots:

public:

signals:
};

