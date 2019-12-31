#include <QApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();

//    QFont globalfont = QFont();
//    /*
//     globalfont.setFamily("")
//     文泉驿微米黑
//     文泉驿等宽微米黑
//     方正书宋_GBK
//     方正仿宋_GBK
//     方正姚体_GBK
//     方正宋体S-超大字符集
//     方正宋体S-超大字符集(SIP)
//     方正小标宋_GBK
//     方正楷体_GBK
//     方正细黑一_GBK
//     方正行楷_GBK
//     方正超粗黑_GBK
//     方正隶书_GBK
//     方正魏碑_GBK
//     方正黑体_GBK*/
//    globalfont.setPixelSize(14);
////    globalfont.setFamily("Droid Sans Fallback");
//    qDebug()<<"----------------------"<<QFont().family();
//    a.setFont(globalfont);
//    //加载qss样式表
//    QFile qss("/home/kylin/sogouImeService.qss");
//    qss.open(QFile::ReadOnly);
//    qApp->setStyleSheet(qss.readAll());
//    qss.close();
    return a.exec();
}
