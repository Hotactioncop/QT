#include "lab1.h"
#include <QApplication>
#include <QTranslator>
#include<QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    //translator.load("spider_ru.qm", ".");
    //translator.load(QLocale::system(),"QT-Lab1", "_");
    QString filespec=QString("spider_");
    filespec += QLocale::system().name();
    translator.load(filespec,"F:/ProgrammingQT/QT-Lab1/exe/QT-Lab1.exe/translations");
    QTranslator translator2;
    QString filespec2=QString("qt_")+QLocale::system().name();
    QString directory=QLibraryInfo::location(QLibraryInfo::TranslationsPath);
    translator2.load(filespec2,directory);
    QApplication ::installTranslator(&translator);
    QApplication ::installTranslator(&translator2);
    Lab1 w;
    w.show();

    return a.exec();
}
