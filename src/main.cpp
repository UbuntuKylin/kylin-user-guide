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

#include <QApplication>
#include <QTextCodec>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QTranslator>
#include <QLibraryInfo>
#include <QProcess>
#include <QByteArray>

#include <ukui-log4qt.h>

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <execinfo.h>
#include "main_controller.h"
#include "common-tool/comm_func.h"


#define BUFF_SIZE 128
#define CHANGELOG_PATH "/usr/share/doc/kylin-user-guide/changelog.Debian.gz"

QString gLang = "zh_CN";
QString gStartShowApp = "";
static void crashHandler(int sig)
{
    signal(sig, SIG_IGN);
    int size;
    char **strings;
    int i = 0;

    char path[BUFF_SIZE] = {0};
    static char *homePath = getenv("HOME");
    snprintf(path, BUFF_SIZE, "%s/.config/kylin-user-guide", homePath);
    strcat(path,"/config-crash.log");
    FILE *fp = fopen(path,"a+");

    void *array[20];
    size = backtrace (array, 20);
    strings = (char **)backtrace_symbols (array, size);

    char logStr[BUFF_SIZE] = "0";
    sprintf(logStr,"!!!--- received signal: %d=%s! Stack trace\n", sig,strsignal(sig));
    fwrite(logStr,sizeof(char),BUFF_SIZE,fp);
    for (i = 0; i < size; i++)
    {
        memset(logStr,0,BUFF_SIZE);
        sprintf(logStr,"%d %s \n",i,strings[i]);
        fwrite(logStr,sizeof(char),BUFF_SIZE,fp);
    }

    fflush(fp);
    fclose(fp);
    free (strings);

    exit(128 + sig);
}

QString getAppVersion(){
    QProcess process;
    process.start(QString("dpkg-parsechangelog -l %1 --show-field Version").arg(CHANGELOG_PATH));
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    result = result.left(result.length()-1);
    return result;
}

int main(int argc, char *argv[])
{
    initUkuiLog4qt("kylin-user-guide");

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    qputenv("QT_QPA_PLATFORMTHEME", "ukui");
    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("Kylin User Guide");
    QCoreApplication::setApplicationVersion(getAppVersion());
    QStringList args = app.arguments();

    QCommandLineOption jumpAppOption(QStringList()<< "A" << "appName","指定打开应用程序版本手册","");
//    QCommandLineOption asDaemonOption(QStringList()<< "D" << "daemon","作为后台demon，显示图形");
    QCommandLineParser cmdinParser;

    cmdinParser.setApplicationDescription("ubuntukylin user guide");
    cmdinParser.addHelpOption();
    cmdinParser.addVersionOption();
    cmdinParser.addOption(jumpAppOption);
//    cmdinParser.addOption(asDaemonOption);

    cmdinParser.addPositionalArgument("--help","显示全部帮助选项");
    cmdinParser.addPositionalArgument("--version","显示安装的程序的版本并退出");
    cmdinParser.addPositionalArgument("--display","要使用的X显示");

    cmdinParser.process(args);
    bool bJumpApp = cmdinParser.isSet(jumpAppOption);
//    QString jumpApp = cmdinParser.value("-A");//拿不到值
    QString jumpApp = "";
    if(argc>2&&bJumpApp)
    {
        jumpApp = args.at(2);
//        if(1==jumpApp.split(":"))//dbus调用没有带:
        if(2==jumpApp.split(":").length())//标准帮助URL help:xxx,部分开源app调用模式，新app可以统一用help:标准方式
        {
            jumpApp = jumpApp.split(":").at(1);
        }
        //games
        QStringList gamesList,toolsList;
        gamesList << "iagno" << "gnome-mines" << "gnome-tetravex";
        toolsList << "onboard" << "atril" << "indicator-china-weather"<< "kylin-recorder" << "kylin-usb-creator" << "kylin-screenshot"\
                  << "kylin-calculator" << "kylin-camera" << "kylin-scanner";
        if(gamesList.contains(jumpApp))
            jumpApp = "game/"+jumpApp;
        if(toolsList.contains(jumpApp))
            jumpApp = "tools/"+jumpApp;
//        QMessageBox::information(NULL, "Title", jumpApp,
//                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
//    qDebug()<<"args"<<args<< "  jumpApp =" << jumpApp <<"       bJumpApp=" << bJumpApp;

    if(signal(SIGCHLD,SIG_IGN)==SIG_ERR)//忽略子进程已经停止或退出
    {
        //注册SIGSEGV信号失败
        perror("signal error");
    }
    if(signal(SIGSEGV,crashHandler)==SIG_ERR)//无效内存段访问
    {
        //注册SIGSEGV信号失败
        perror("signal error");
    }
    if(signal(SIGILL,crashHandler)==SIG_ERR)//非法指令
    {
        //注册SIGILL信号失败
        perror("signal error");
    }
    if(signal(SIGHUP,crashHandler)==SIG_ERR)//系统挂断
    {
        //注册SIGHUP信号失败
        perror("signal error");
    }
    if(signal(SIGABRT,crashHandler)==SIG_ERR)//进程停止运行
    {
        //注册SIGABRT信号失败
        perror("signal error");
    }

    QLocale locale;
    if(locale.language()==QLocale::Chinese)
    {
        gLang = "zh_CN";
    }
   else
   {
       gLang = "en_US";
   }
    app.setApplicationName(APPLICATION_NAME);
//    app.setQuitOnLastWindowClosed(true);

#ifdef APP_USE_QSS
    //加载qss样式表
    QFile qss(":kylin-user-guide.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
#endif

    QString qm_name = QLocale::system().name();
//        QString locale = "bo_CN";
    QTranslator translator;
    if(qm_name == "zh_CN" || qm_name == "es" || qm_name == "fr" || qm_name == "de" || qm_name == "ru" || qm_name == "bo_CN") {//中文 西班牙语 法语 德语 俄语
//        if(!translator.load("kylin-user-guide_" + qm_name + ".qm",
//                            ":/translation/"))
        if(!translator.load("kylin-user-guide_" + qm_name + ".qm",
                            "/usr/share/kylin-user-guide/translations/"))
            qDebug() << "Load translation file："<< "kylin-user-guide_" + qm_name + ".qm" << " failed!";
        else
            app.installTranslator(&translator);
    }

    //加载Qt对话框默认的国际化
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + qm_name,
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    gStartShowApp = jumpApp;
    MainController *ctrl = MainController::self();
    app.exec();

    delete ctrl;
    return 0;

}
