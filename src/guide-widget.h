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
#include <QLineEdit>
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
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKit/QWebSettings>
//#include <QtWebChannel/QtWebChannel>
class GuideWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GuideWidget(QWidget *parent = 0);
    ~GuideWidget();
    void initUI();
    void initSettings();
    void showPosition();
    void jump_app(QString);
    void set_Cursor(QPoint &event);
    QString system_name();
    QStringList getDirAndPng();
protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent * );
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    QPoint dragPos;
    bool mouseinwidget =false;
    bool isClose = false;
    bool mCanDrag = false;
    enum LocaTion{top,bottom,left,right,left_top,left_bottm,right_top,right_botm,middle};
    LocaTion site_flag;
    int Padding = 2;
private:
    QWebView *m_pWebView;
    QString mJumpAppName;
    QWidget *m_yWidget;
private slots:
    void slot_backOffButton();
    void slot_javaScriptFromWinObject();
    void slot_loadFinished(bool);
    void slot_onClicked_minOffButton();
    void slot_onClicked_maxOffButton();
    void slot_onClicked_closeOffButton();
    void slot_webGoto(QUrl);
public slots:
    Q_INVOKABLE QString js_getIndexMdFilePath(QString);
    Q_INVOKABLE QString js_getIndexMdFilePathOther(QString);
    Q_INVOKABLE QString js_getIndexMdFileContent(QString);
    Q_INVOKABLE QString js_getIndexMdFileTitle(QString);
    Q_INVOKABLE QStringList js_getIntoFilename();
public:

signals:
    Q_INVOKABLE void sig_backOff2js();
};

