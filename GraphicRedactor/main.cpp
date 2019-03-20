#include "graphicredactor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicRedactor w;
    w.show();

    return a.exec();
}
