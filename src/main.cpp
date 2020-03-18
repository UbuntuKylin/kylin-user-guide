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

#include <QApplication>
#include <QTextCodec>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include <QFont>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <execinfo.h>
#include "main_controller.h"
#include "common-tool/comm_func.h"

QString gLang = "zh_CN";
QString gStartShowApp = "";
#define BUFF_SIZE 128
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

int main(int argc, char *argv[])
{
//#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
//#endif

    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("ubuntukylin user guide");
    QCoreApplication::setApplicationVersion("0.0.0.0001");
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
    if(bJumpApp)
        jumpApp = args.at(2);
    qDebug()<<"args"<<args<< "  jumpApp =" << jumpApp <<"       bJumpApp=" << bJumpApp;

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

    gStartShowApp = jumpApp;
    MainController *ctrl = MainController::self();
    app.exec();

    delete ctrl;
    return 0;

}
