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
#include <QApplication>
#include <QToolTip>
#include <QGraphicsDropShadowEffect>
#include <QPixmap>
#include <QX11Info>
#include <X11/Xlib.h>
#include <QPainterPath>

#include "guide-widget.h"
#include "main_controller.h"
#include "common-tool/comm_func.h"
#include "xatom-helper.h"

GuideWidget::GuideWidget(QWidget *parent) :QWidget(parent)
{
    this->isTopLevel();
    this->resize(1000,750);

    // 添加窗管协议
    MotifWmHints hints;
    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
    hints.functions = MWM_FUNC_ALL;
    hints.decorations = MWM_DECOR_BORDER;
    XAtomHelper::getInstance()->setWindowMotifHint(this->winId(), hints);

//    this->setWindowIcon(QIcon(":/image/kylin-user-guide_44_56.png"));
    this->setWindowIcon(QIcon::fromTheme("kylin-user-guide"));
    //去掉窗口管理器后设置边框不生效了，所以下面通过背景图标提供边框,并且支持最小化。
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QColor(Qt::white)));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
    QDesktopWidget *desktop = QApplication::desktop();
    QRect rect = desktop->screenGeometry(nullptr);
    this->move((rect.bottomRight().x()-this->width())/2,(rect.bottomRight().y()-this->height())/2);


    initSettings();
    initUI();
    getDirAndPng();
}

void GuideWidget::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
//    painter.setBrush(QBrush(Qt::white));
//    painter.setPen(QColor(79,79,79));
//    QRect rect = this->rect();
////    qDebug()<<"====" <<this->rect() << rect.width() << rect.height();
//    rect.setWidth(rect.width()-2);
//    rect.setHeight(rect.height()-2);
//    painter.drawRoundedRect(rect, 10, 10);

//    QStyleOption opt;
//    opt.init(this);
//    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
//    //也可用QPainterPath 绘制代替 painter.drawRoundedRect(rect, 15, 15);
//    {
//        QPainterPath painterPath;
//        painterPath.addRoundedRect(rect, 15, 15);
//        p.drawPath(painterPath);
//    }
    QWidget::paintEvent(event);
}

void GuideWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    //调整边距
    auto rect = this->rect();
    QPainterPath blurPath;
    //增加圆角
    blurPath.addRoundedRect(rect, 10, 10);
    //使用QPainterPath的api生成多边形Region
    setProperty("blurRegion", QRegion(blurPath.toFillPolygon().toPolygon()));
    this->update();

    QTimer* timer = new QTimer();
    timer->start(10);           //以毫秒为单位
    connect(timer,&QTimer::timeout,[=]{
        m_pWebView->page()->mainFrame()->evaluateJavaScript("Refresh_the_content_interface();");
        timer->stop();
    });

//    qDebug() << e->oldSize() << e->size();

    QPushButton *button1 = this->findChild<QPushButton *>("maxOffButton");
    if(e->oldSize() == QSize(desktop->availableGeometry().width(),desktop->availableGeometry().height())){

        QIcon iconRestore(":/image/fullscreen.png");
        button1->setIcon(iconRestore);
        windowsflag = true;
    }
    if(e->size() == QSize(desktop->availableGeometry().width(),desktop->availableGeometry().height())){

        QIcon iconFull(":/image/restore.png");
        button1->setIcon(iconFull);
        windowsflag = false;
    }
}

GuideWidget::~GuideWidget()
{

}

void GuideWidget::initUI()
{
    m_pWebView = new QWebView;
    m_pWebView->installEventFilter(this);
    qDebug() <<"------------"<< m_pWebView->width() << m_pWebView->height();

    this->setObjectName("m_yWidget");
    QPushButton *backOffButton = new QPushButton(this);
    QPushButton *minOffButton = new QPushButton(this);
    QPushButton *maxOffButton = new QPushButton(this);
    QPushButton *closeOffButton = new QPushButton(this);
    QPushButton *menuOffButton = new QPushButton(this);
    QLabel *m_pIconLabel = new QLabel(this);
    QLabel *m_pTitleLabel = new QLabel(this);
    QLineEdit *search_Line = new QLineEdit(this);

    QIcon icon1;
    icon1.addFile(tr(":/image/icon-search.png"));
    search_Line->addAction(icon1,QLineEdit::LeadingPosition);
    //search_Line->setFixedSize(320,30);
    search_Line->setMinimumSize(280,30);
    search_Line->setMaximumSize(800,30);
    search_Line->setPlaceholderText(QString::fromLocal8Bit("搜索"));
    search_Line->setAlignment(Qt::AlignVCenter);
    qDebug() << search_Line->alignment();
    search_Line->setStyleSheet("background-color:rgb(234,234,234)");
    search_Line->hide();//第一个版本不支持搜索
    backOffButton->setObjectName("backOffButton");
    minOffButton->setObjectName("minOffButton");
    maxOffButton->setObjectName("maxOffButton");
    closeOffButton->setObjectName("closeOffButton");

    m_pIconLabel->setFixedSize(24,24);
    m_pIconLabel->setScaledContents(true);
    m_pIconLabel->setPixmap((QPixmap(QString::fromLocal8Bit(":/image/kylin-user-guide_16_24.png"))));

//    m_pTitleLabel->setText(GUIDE_WINDOW_TITLE);
    m_pTitleLabel->setFixedHeight(30);

    QIcon iconReturn(":/image/back.png"); //让QIcon对象指向想要的图标
    backOffButton->setIcon(iconReturn); //给按钮添加图标
    backOffButton->setIconSize(QSize(25,25));//重置图标大小
    backOffButton->setFixedSize(40,30);
    backOffButton->setStyleSheet(/*"QPushButton{border-image: url(:/image/back.png);border-image-size:25px,25px;border-radius:5px;}"\*/
                                 "QPushButton:hover{background-color:rgb(107,142,235);border-radius:5px;}"\
                                 "QPushButton:pressed{background-color:rgb(61,107,229);border-radius:5px;}");

    backOffButton->setFlat(true);
    backOffButton->setFocusPolicy(Qt::NoFocus);
    backOffButton->setVisible(false);
    backOffButton->setCursor(QCursor(Qt::ArrowCursor));
    backOffButton->hide();
//    qDebug() << backOffButton->objectName()<< "=========="<<backOffButton->parent()->objectName();

    QIcon iconMin(tr(":/image/minimize.png"));
    minOffButton->setIcon(iconMin);
    minOffButton->setIconSize(QSize(30,25));
    minOffButton->setFixedSize(40,30);
    minOffButton->setFlat(true);
    minOffButton->setFocusPolicy(Qt::NoFocus);
    minOffButton->setStyleSheet("QPushButton:hover{background-color:rgb(107,142,235);border-radius:5px;}"\
                                "QPushButton:pressed{background-color:rgb(61,107,229);border-radius:5px;}");
    minOffButton->setCursor(QCursor(Qt::ArrowCursor));

    QIcon iconMax(tr(":/image/fullscreen.png"));
    maxOffButton->setIcon(iconMax);
    maxOffButton->setIconSize(QSize(30,25));
    maxOffButton->setFixedSize(40,30);
    maxOffButton->setFlat(true);
    maxOffButton->setFocusPolicy(Qt::NoFocus);
    maxOffButton->setStyleSheet("QPushButton:hover{background-color:rgb(107,142,235);border-radius:5px;}"\
                                "QPushButton:pressed{background-color:rgb(61,107,229);border-radius:5px;}");
    maxOffButton->setCursor(QCursor(Qt::ArrowCursor));

    QIcon iconClose(tr(":/image/close.png"));
    closeOffButton->setIcon(iconClose);
    closeOffButton->setIconSize(QSize(30,25));
    closeOffButton->setFixedSize(40,30);
    closeOffButton->setFlat(true);
    closeOffButton->setFocusPolicy(Qt::NoFocus);
    closeOffButton->setStyleSheet("QPushButton:hover{background-color:rgb(215,52,53);border-radius:5px;}"\
                                "QPushButton:pressed{background-color:rgb(244,110,101);border-radius:5px;}");
    closeOffButton->setCursor(QCursor(Qt::ArrowCursor));

    QIcon iconMenu(tr(":/image/open-menu-symbolic.png"));
    menuOffButton->setIcon(iconMenu);
    menuOffButton->setIconSize(QSize(30,25));
    menuOffButton->setFixedSize(40,30);
    menuOffButton->setFlat(true);
    menuOffButton->setFocusPolicy(Qt::NoFocus);
    menuOffButton->setVisible(false);


    connect(backOffButton,SIGNAL(released()),this,SLOT(slot_backOffButton()));
    connect(closeOffButton,SIGNAL(released()),this,SLOT(slot_onClicked_closeOffButton()));
    connect(minOffButton,SIGNAL(released()),this,SLOT(slot_onClicked_minOffButton()));
    connect(maxOffButton,SIGNAL(released()),this,SLOT(slot_onClicked_maxOffButton()));


    QVBoxLayout *main_layout = new QVBoxLayout(this);
    QGridLayout *widget_layout = new QGridLayout(this);

    widget_layout->addWidget(m_pIconLabel,0,1,1,3);
    widget_layout->addWidget(m_pTitleLabel,0,4,1,10);
    widget_layout->addWidget(backOffButton,0,22,1,4);
    widget_layout->addWidget(search_Line,0,40,1,40);
    widget_layout->addWidget(menuOffButton,0,89,1,4);
    widget_layout->addWidget(minOffButton,0,93,1,4);
    widget_layout->addWidget(maxOffButton,0,97,1,4);
    widget_layout->addWidget(closeOffButton,0,101,1,4);
    widget_layout->setColumnStretch(40,6);
    widget_layout->setColumnStretch(6,2);
    widget_layout->setColumnStretch(39,1);
    widget_layout->setColumnStretch(89,2);

    widget_layout->addWidget(m_pWebView,1,0,1,106);

    QString name = system_name();
    QLocale localeNew;
    if(localeNew.language()==QLocale::Chinese)
    {
        m_pTitleLabel->setText(GUIDE_WINDOW_TITLE);
        m_pWebView->load(QUrl(QString(LOCAL_URL_PATH_UBUNTUKYLIN)+"index-ubuntukylin.html"));
    }
    else
    {
        m_pTitleLabel->setText("Kylin User Guide");
        m_pWebView->load(QUrl(QString(LOCAL_URL_PATH_UBUNTUKYLIN)+"index-ubuntukylin_en_US.html"));
    }
//    m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);
    //m_pWebView->load(QUrl(QString(LOCAL_URL_PATH)+"index.html"));
    m_pWebView->setStyleSheet("border-radius:10px");
    m_pWebView->page()->setLinkDelegationPolicy(QWebPage::DelegateExternalLinks);//外链
    m_pWebView->settings()->setObjectCacheCapacities(0,0,0);
//    m_pWebView->settings()->setAttribute(QWebSettings::WebSecurityEnabled, false);//关闭浏览器安全
    m_pWebView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);//开发模式
    m_pWebView->settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    m_pWebView->settings()->setAttribute(QWebSettings::JavaEnabled,true);
    m_pWebView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    m_pWebView->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
    m_pWebView->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    m_pWebView->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);//设置能访问本地文件
    m_pWebView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    m_pWebView->settings()->setAttribute(QWebSettings::AutoLoadImages,true);
    m_pWebView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    m_pWebView->setContextMenuPolicy(Qt::NoContextMenu);

    QObject::connect(m_pWebView,SIGNAL(loadFinished(bool)),this,SLOT(slot_loadFinished(bool)));
    QObject::connect(m_pWebView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(slot_javaScriptFromWinObject()));
    QObject::connect(m_pWebView->page(),SIGNAL(linkClicked(QUrl)),this,SLOT(slot_webGoto(QUrl)));
    //    m_pWebView->load(QUrl("https://www.w3school.com.cn/html5/html_5_video.asp"));
    widget_layout->setContentsMargins(0, 2, 0, 1);
    widget_layout->setVerticalSpacing(0);

    main_layout->addLayout(widget_layout);

    //设置窗体透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置无边框
//    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

//    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
//    shadow_effect->setBlurRadius(5);
//    shadow_effect->setColor(QColor(0, 0, 0, 127));
//    shadow_effect->setOffset(2, 2);
//    this->setGraphicsEffect(shadow_effect);

//    main_layout->setMargin(2);
    main_layout->setContentsMargins(2,2,2,15);

    this->setLayout(widget_layout);
    this->setLayout(main_layout);

    this->setMouseTracking(true);
//    this->m_yWidget->setMouseTracking(true);
    qDebug() << this->frameGeometry().width() << this->frameGeometry().height();
}

void GuideWidget::slot_webGoto(QUrl url)
{
    qDebug() << Q_FUNC_INFO << url;
    if(url.toString().contains("http"))
        QDesktopServices::openUrl(url);
}

void GuideWidget::jump_app(QString appName)
{
    qDebug() << Q_FUNC_INFO << appName;
    QString cmd = QString("qt_jumpApp(\"%1\");").arg(appName);
    m_pWebView->page()->mainFrame()->evaluateJavaScript(cmd);
}

void GuideWidget::slot_javaScriptFromWinObject()
{
    qDebug() << Q_FUNC_INFO;
    m_pWebView->page()->mainFrame()->addToJavaScriptWindowObject("guideWebkit",this);
//    m_pWebView->page()->mainFrame()->evaluateJavaScript("mywebkit.sig_backOff2js.connect(goBackMainUI());");
}

void GuideWidget::slot_backOffButton()
{
    qDebug() << Q_FUNC_INFO;
//    emit sig_backOff2js();
//    QString name = system_name();
//    if(name == "kylin")
//    {
//        m_pWebView->page()->mainFrame()->evaluateJavaScript("goBackMainUI();");
//    }
//    else if (name == "Ubuntu Kylin") {
    m_pWebView->page()->mainFrame()->evaluateJavaScript("goBackMainUI_ubuntu();");
//    }
    //m_pWebView->page()->mainFrame()->evaluateJavaScript("goBackMainUI();");
    QPushButton *button = this->findChild<QPushButton *>("backOffButton");
    button->hide();
}

void GuideWidget::slot_loadFinished(bool f)
{
    qDebug() << Q_FUNC_INFO << f ;
}

void GuideWidget::slot_onClicked_minOffButton()
{
    QWidget *m_pWindow = this->window();
    if(m_pWindow->isTopLevel())
    {
        m_pWindow->showMinimized();
    }
}

void GuideWidget::slot_onClicked_maxOffButton()
{
    QWidget *m_pWindow = this->window();
    if(m_pWindow->isTopLevel())
    {
        QPushButton *button = this->findChild<QPushButton *>("maxOffButton");
        QIcon iconFull(":/image/restore.png");
        QIcon iconRestore(":/image/fullscreen.png");
        m_pWindow->isMaximized() ? m_pWindow->showNormal() : m_pWindow->showMaximized();
        m_pWindow->isMaximized() ? button->setIcon(iconFull) :button->setIcon(iconRestore);
        if(m_pWindow->isMaximized())
            windowsflag = false;
        else
            windowsflag = true;
    }
}

void GuideWidget::slot_onClicked_closeOffButton()
{
    QWidget *m_pWindow = this->window();
    if(m_pWindow->isTopLevel())
    {
        m_pWindow->close();
    }
}

QString GuideWidget::system_name()
{
    QFile system (OS_RELEASE);
    if(!system.exists())
    {
        return "";
    }
    if (!system.open(QIODevice::ReadOnly))
    {
        return "";
    }
    QString str = system.readLine();
    QString name = str.section("\"",1,1);
    return name;
    //return "Ubuntu Kylin";
}

QStringList GuideWidget::getDirAndPng()
{
    QStringList list;
    QString PathForSystem;
    QString NameForSystem=system_name();
//    if(NameForSystem == "kylin")
//    {
//        PathForSystem = LOCAL_FILE_PATH;
//    }
//    else if(NameForSystem == "Ubuntu Kylin")
//    {
    PathForSystem = LOCAL_FILE_PATH_UBUNTUKYLIN;
//    }
    QDir path(PathForSystem);
    if(!path.exists())
    {
        qDebug()<< PathForSystem << "is not exists !!!";
    }
    QStringList dirList = path.entryList();
    dirList.sort();
    for(int i=0;i<dirList.size();++i)
    {
        QDir dirname(PathForSystem);
        if(dirList.at(i) == "."||dirList.at(i)=="..")
        {
            continue;
        }
        else
        {
            dirname.cd(dirList.at(i));
            //qDebug() << dirname.entryList();
            QStringList namelist=dirname.entryList();
            QStringList Pngname = namelist.filter(".png");
            list << dirList.at(i)+"|"+Pngname.at(0);
        }
    }
    return list;
}

QString GuideWidget::JudgmentSystrm()
{
    QFile system_file (OS_RELEASE);
    QFile system_file1 (LSB_RELEASE);
    QString value;
    if(system_file.exists()){
        QString SystemName = system_name();
        if(SystemName.contains("debian",Qt::CaseInsensitive)){
            value = "Debian";
        }else if(SystemName.contains("kylin",Qt::CaseInsensitive)){
            value = "Ubuntu Kylin";
        }else if(SystemName.contains("ubuntu",Qt::CaseInsensitive)){
            if(QFileInfo("/usr/bin/ukui-panel").exists()){
                value = "Ubuntu Kylin";
            }else{
                value = "Ubuntu";
            }
        }else{
            value = "";
            return value;
        }
    }else{
        if(!system_file1.exists())
        {
            value = "";
            return value;
        }
        if (!system_file1.open(QIODevice::ReadOnly))
        {
            value = "";
            return value;
        }
        QString str = system_file1.readLine();
        QString name = str.section("=",-1);
        name = name.trimmed();
        if(name.contains("debian",Qt::CaseInsensitive)){
            value = "Debian";
        }else if(name.contains("kylin",Qt::CaseInsensitive)){
            value = "Ubuntu Kylin";
        }else if(name.contains("ubuntu",Qt::CaseInsensitive)){
            if(QFileInfo("/usr/bin/ukui-panel").exists()){
                value = "Ubuntu Kylin";
            }else{
                value = "Ubuntu";
            }
        }else{
            value = "";
            return value;
        }
    }
    return value;
}

bool GuideWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_pWebView && event->type() == QEvent::Resize) {
        QPainterPath path;
        path.addRoundedRect(0, 0, this->width()-3, this->height()-47, 5, 5);
        m_pWebView->setMask(path.toFillPolygon().toPolygon());
    }

    if (watched == m_pWebView && event->type() == QEvent::Leave) {
        return true;
    }
    return false;
}

QStringList GuideWidget::js_getIntoFilename()
{
    QStringList test=getDirAndPng();
    return test;
}

QString GuideWidget::js_getIndexMdFilePath(QString appName)
{
    qDebug() << Q_FUNC_INFO << appName;
    QString IndexMdFilePath;
//    QString name = system_name();
//    if(name == "kylin")
//    {
//        IndexMdFilePath = LOCAL_FILE_PATH + appName + "/" +  gLang + "/index.md";
//    }
//    else if (name == "Ubuntu Kylin"){
    IndexMdFilePath = LOCAL_FILE_PATH_UBUNTUKYLIN + appName + "/" +  gLang + "/index.md";
//    }
    //QString IndexMdFilePath = LOCAL_FILE_PATH + appName + "/" +  gLang + "/index.md";
    QPushButton *button = this->findChild<QPushButton *>("backOffButton");
    qDebug() << button;
    button->show();
    return IndexMdFilePath;
}

QString GuideWidget::js_getIndexMdFilePathOther(QString appName)
{
    qDebug() << Q_FUNC_INFO << appName;
    QString IndexMdFilePath;
//    QString name = system_name();
//    if(name == "kylin")
//    {
//        IndexMdFilePath = LOCAL_FILE_PATH + appName + "/" +  gLang + "/index.md";
//    }
//    else if (name == "Ubuntu Kylin"){
    IndexMdFilePath = LOCAL_FILE_PATH_UBUNTUKYLIN + appName + "/" +  gLang + "/index.md";
//    }
    return IndexMdFilePath;
}

QString GuideWidget::js_getIndexMdFileContent(QString IndexMdFilePath)
{
    qDebug() << Q_FUNC_INFO << IndexMdFilePath;
    QFile file (IndexMdFilePath);
    if(!file.exists())
        return "";
    if(!file.open(QIODevice::ReadOnly))
        return "";
    return file.readAll();
}

QString GuideWidget::js_getIndexMdFileTitle(QString IndexMdFilePath)
{
    qDebug() << Q_FUNC_INFO << IndexMdFilePath;
    QFile file (IndexMdFilePath);
    if(!file.exists())
        return "";
    if(!file.open(QIODevice::ReadOnly))
        return "";
    QString title = file.readLine();
    title = title.mid(1,title.length());
    return title.trimmed();
}


void GuideWidget::initSettings()
{

}

void GuideWidget::set_Cursor(QPoint &currentPoint)
{
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());

    int x = currentPoint.x();
    int y = currentPoint.y();

    if (tl.x()+Padding >= x && tl.x() <= x && tl.y()+Padding >= y && tl.y() <= y) {
        site_flag = left_top;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (rb.x()-Padding<= x && rb.x() >= x && tl.y()+Padding >= y && tl.y() <= y) {
        site_flag = right_top;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (tl.x()+Padding >= x && tl.x() <= x && rb.y()-Padding <= y && rb.y() >= y) {
        site_flag = left_bottm;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (rb.x()-Padding <= x && rb.x() >= x && rb.y()-Padding <= y && rb.y() >= y) {
        site_flag = right_botm;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (tl.x()+Padding >= x && tl.x() <= x && tl.y()+Padding <= y && rb.y()-Padding >= y) {
        site_flag = left;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (rb.x()-Padding <= x && rb.x() >= x && rb.y()-Padding >= y && tl.y()+Padding <= y) {
        site_flag = right;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (tl.x()+Padding <= x && rb.x()-Padding >= x && tl.y()+Padding >= y && tl.y() <= y) {
        site_flag = top;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (tl.x()+Padding <= x && rb.x()-Padding >= x && rb.y()-Padding <= y && rb.y() >= y) {
        site_flag = bottom;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else {
        site_flag = middle;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}

void GuideWidget::mousePressEvent(QMouseEvent *event)
{
    mouseinwidget = false; //避免在其他控件上按下鼠标移动出现位置不正确问题
    if(event->pos().y()>=3&&event->pos().y()<=30)
        mCanDrag = true;
    else
        mCanDrag = false;
    if (event->button() == Qt::LeftButton) {
        mouseinwidget = true;
        this->setCursor(QCursor(Qt::OpenHandCursor));
        dragPos = event->globalPos() - frameGeometry().topLeft();
    }
    event->accept();
}

void GuideWidget::mouseMoveEvent(QMouseEvent *event)
{
//    QPoint gloPoint = event->globalPos();
//    QRect rect = this->rect();
//    QPoint tl = mapToGlobal(rect.topLeft());
//    QPoint rb = mapToGlobal(rect.bottomRight());
//    if(windowsflag){
//        if (!mouseinwidget)
//        {
//            set_Cursor(gloPoint);
//        }
//        else
//        {
//            if (site_flag != middle )
//            {
//                QRect rMove(tl, rb);
//                switch (site_flag)
//                {
//                    case left_top:
//                        if(rb.x()-gloPoint.x() >= this->minimumWidth())
//                            rMove.setLeft(gloPoint.x());

//                        if(rb.y()-gloPoint.y() >= this->minimumHeight())
//                            rMove.setTop(gloPoint.y());
//                        break;
//                    case right_top:
//                        if(gloPoint.x()-tl.x() >= this->minimumWidth())
//                            rMove.setRight(gloPoint.x());

//                        if(rb.y()-gloPoint.y() >= this->minimumHeight())
//                            rMove.setTop(gloPoint.y());
//                        break;
//                    case left_bottm:
//                        if(rb.x()-gloPoint.x() >= this->minimumWidth())
//                            rMove.setLeft(gloPoint.x());

//                        if(gloPoint.y()-tl.y() >= this->minimumHeight())
//                            rMove.setBottom(gloPoint.y());
//                        break;
//                    case right_botm:
//                        if(gloPoint.x()-tl.x() >= this->minimumWidth())
//                            rMove.setRight(gloPoint.x());

//                        if(gloPoint.y()-tl.y() >= this->minimumHeight())
//                            rMove.setBottom(gloPoint.y());
//                        break;
//                    case top:
//                        if(rb.y()-gloPoint.y() >= this->minimumHeight())
//                            rMove.setTop(gloPoint.y());
//                        break;
//                    case right:
//                        if(gloPoint.x()-tl.y() >= this->minimumWidth())
//                            rMove.setRight(gloPoint.x());
//                        break;
//                    case bottom:
//                        if(gloPoint.y()-tl.y() >= this->minimumHeight())
//                            rMove.setBottom(gloPoint.y());
//                        break;
//                    case left:
//                        if(rb.x()-gloPoint.x() >= this->minimumWidth())
//                            rMove.setLeft(gloPoint.x());
//                        break;
//                    default:
//                        break;
//                }
//                this->setGeometry(rMove);
//                QTimer* timer = new QTimer();
//                timer->start(10);           //以毫秒为单位
//                connect(timer,&QTimer::timeout,[=]{
//                    m_pWebView->page()->mainFrame()->evaluateJavaScript("Refresh_the_content_interface();");
//                    timer->stop();
//                });

//            }
//        }
//    }

    if(mCanDrag && mouseinwidget){
        qreal  dpiRatio = qApp->devicePixelRatio();
        if (QX11Info::isPlatformX11()) {
            Display *display = QX11Info::display();
            Atom netMoveResize = XInternAtom(display, "_NET_WM_MOVERESIZE", False);
            XEvent xEvent;
            const auto pos = QCursor::pos();

            memset(&xEvent, 0, sizeof(XEvent));
            xEvent.xclient.type = ClientMessage;
            xEvent.xclient.message_type = netMoveResize;
            xEvent.xclient.display = display;
            xEvent.xclient.window = this->winId();
            xEvent.xclient.format = 32;
            xEvent.xclient.data.l[0] = pos.x() * dpiRatio;
            xEvent.xclient.data.l[1] = pos.y() * dpiRatio;
            xEvent.xclient.data.l[2] = 8;
            xEvent.xclient.data.l[3] = Button1;
            xEvent.xclient.data.l[4] = 0;

            XUngrabPointer(display, CurrentTime);
            XSendEvent(display, QX11Info::appRootWindow(QX11Info::appScreen()),
                       False, SubstructureNotifyMask | SubstructureRedirectMask,
                       &xEvent);
            //XFlush(display);

            XEvent xevent;
            memset(&xevent, 0, sizeof(XEvent));

            xevent.type = ButtonRelease;
            xevent.xbutton.button = Button1;
            xevent.xbutton.window = this->winId();
            xevent.xbutton.x = event->pos().x() * dpiRatio;
            xevent.xbutton.y = event->pos().y() * dpiRatio;
            xevent.xbutton.x_root = pos.x() * dpiRatio;
            xevent.xbutton.y_root = pos.y() * dpiRatio;
            xevent.xbutton.display = display;

            XSendEvent(display, this->effectiveWinId(), False, ButtonReleaseMask, &xevent);
            XFlush(display);

            if (event->source() == Qt::MouseEventSynthesizedByQt) {
                if (!this->mouseGrabber()) {
                    this->grabMouse();
                    this->releaseMouse();
                }
            }

            mouseinwidget = false;
        } else {
            this->move((QCursor::pos() - dragPos) * dpiRatio);
        }
    }
    event->accept();
}

void GuideWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        QWidget *m_yWindow = this->window();
        if(m_yWindow->isTopLevel())
        {
            QPushButton *button1 = this->findChild<QPushButton *>("maxOffButton");
            QIcon iconFull(":/image/restore.png");
            QIcon iconRestore(":/image/fullscreen.png");
            m_yWindow->isMaximized() ? m_yWindow->showNormal() : m_yWindow->showMaximized();
            m_yWindow->isMaximized() ? button1->setIcon(iconFull) :button1->setIcon(iconRestore);
            if(m_yWindow->isMaximized())
                windowsflag = false;
            else
                windowsflag = true;
        }
        qDebug() << this->rect();
    }
    event->accept();
}

void GuideWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mouseinwidget = false;
        this->setCursor(Qt::ArrowCursor);
    }
    event->accept();
}

void GuideWidget::closeEvent(QCloseEvent *)
{
//    QApplication* app;
//    app->quit();
}

