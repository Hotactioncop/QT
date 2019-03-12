#include "lab1.h"
#include <QDebug>
#include <QString>
#include <QIcon>
#include <QApplication>
#include <QDesktopWidget>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QCursor>
#include <QMouseEvent>
#include<QToolTip>
#include<QPainter>

Lab1::Lab1(QWidget *parent)
    : QWidget(parent)
{
    /*Поэкспериментируйте с флагами группы hint.
        Задание 1
        1) Получите текущее значение флагов, заданное по умолчанию.*/
        qDebug() << windowFlags();
        //2) Создайте переменную типа Qt::WindowFlags
        Qt::WindowFlags flags;
        //3) задайте тип окна (имеет смысл использовать значенияQt::Window,Qt::Dialog )
        flags = Qt::Widget;
        qDebug() << windowType();
        //4) с помощью  флагов группыhint, объединенных побитовой операцией или, попытайтесь задать различные стили окна.
        flags|=Qt::CustomizeWindowHint;
        flags|=Qt::WindowTitleHint;
        flags|=Qt::WindowCloseButtonHint;
        flags|=Qt::WindowFullscreenButtonHint;
        flags|=Qt::WindowMinimizeButtonHint;
        flags|=Qt::WindowMaximizeButtonHint;
        flags|=Qt::WindowStaysOnTopHint;
        //4)  установите на виджете  полученное значение флагов
        setWindowFlags(flags);
        //5) проверьте, что получилось
        /*Подсказки:
        1) удобнее всего наблюдать эффект, установив значение Qt::WindowStaysOnTopHint.
        2) стилиQt::WindowTitleHint, Qt::WindowSystemMenuHint, Qt::WindowMinimizeButtonHint, Qt::WindowMaximizeButtonHint,
        Qt::WindowCloseButtonHintучитываются только в том случае, когда одновременно установлен Qt::CustomizeWindowHint.*/


        /*Задание 2
    Поэкспериментируйте с состоянием главного окна. Заставьте его появляться на экране в максимизированном (минимизированном) виде.*/

        qDebug() << windowState();
        //Qt::WindowStates st = Qt::WindowMaximized;
        //Qt::WindowStates st = Qt::WindowMinimized;
        //Qt::WindowStates st = Qt::WindowNoState;
        //setWindowState(st);
        //showMaximized();
        //showMinimized();
        //showNormal();

        /*Задание 3
        Установите заголовок окна*/

        QString title = QStringLiteral("Forever young");
        //setWindowTitle(title);
        qDebug()<<windowTitle();
        setWindowTitle(QObject::tr("Queen jam"));

        /*Задание 4.1:
    1) Для экономии времени на занятии позаимствуйте мою иконку (перепишите файл .ico в папку Вашего проекта или лучше перепишите целиком папку Images_lab1)
    2) проассоциируйте ее с Вашим приложением (она должна появиться в левом верхнем углу строки заголовка).*/

        QIcon icon("F:/ProgrammingQT/QT-Lab1/icon2.ico");
        setWindowIcon(icon);
        qDebug() << windowIcon();

        /*Задание 4.2:
    Установите пиктограмму приложения в Windows*/

        /*Задание 5.1:
    сделайте фон окна разным в активном состоянии и в неактивном*/

        QPalette palette;
        QColor col(255,0,255);
        //palette.setColor(QPalette::Active, QPalette::Window, QColor(col));

        //palette.setColor(QPalette::Active, QPalette::Window, Qt::darkCyan);
        //palette.setBrush(QPalette::Inactive, QPalette::Window, QBrush(Qt::green));
        //setPalette(palette);

        /*Задание 5.2
    задайте картинку в качестве фона окна (лучше для неактивного состояния).
    Изображение можете для экспериментов позаимствовать у меня (а на досуге найти/создать своюкартинку)*/

        QPixmap pix1("Disney_42.png");
        QPixmap pix2;
        pix2.load("WomanAndDog.jpg");
        //palette.setBrush(QPalette::Inactive,QPalette::Window, QBrush(pix1));
        //setPalette(palette);

        /*Задание 5.3
    сделайте фон окна полупрозрачным*/
        setWindowOpacity(1);

        /*Задание 6.1
    В нашей заготовке размеры и позиция окна задаются по умолчанию ОС. Задайте эти значения самостоятельно посредством перечисленных выше методов.*/

        qDebug()<<frameGeometry();
        qDebug()<<frameSize();
        qDebug()<<pos();
        qDebug()<<rect();
        //move(0,0);
        //resize(960,840);
        //setGeometry(0,30,640,480);


        /*Задание 6.2
    расположите окно в любой четверти экрана*/

        QDesktopWidget *desc =QApplication::desktop();
        qDebug() << desc->screenGeometry();
        setGeometry(960,540,960,540);

        /*Задание 6.3
    задайте минимальный/максимальный размер окнa*/

        setMaximumSize(960,540);
        setMinimumSize(640,480);

        /*Задание 6.4
    задайте фиксированный размер окна (если для фона используется изображение, то логично зафиксировать размер окна, чтобы картинка «не обрезалась» и «не множилась»)
    Размер окна лучше изменить в соответствии с размерами изображения посредством
    QSize QPixmap::size () const;
    Логично, чтобы размер окна не превышал размеры картинки, поэтому стоит ограничить максимальный размер окна:
    voidQWidget::setMaximumSize ( constQSize& )*/

        //setFixedHeight(540);
        //setFixedWidth(960);
        setFixedSize(640,480);

        /*Задание 7.1
    замените стандартную стрелку на любой из предоставляемых Qtкурсоров*/

        QCursor cursor = Qt::CrossCursor;
        //setCursor(cursor);
        unsetCursor();
        cursor = Qt::PointingHandCursor;

        /*Задание 7.2
    Измените вид курсора.
    Подсказка:
    в классе главного окна заведите переменную типа QCursor, например
    QCursor*spCursor;
    а в конструкторе предусмотрите формирование курсора посредством картинки.*/

        QBitmap bmp("Disney_42.png");
        QCursor cur (bmp, bmp);
        //setCursor(cur);

        QPixmap pix3("F:/ProgrammingQT/QT-Lab1/super_spy.bmp");
        pix3.setMask(QBitmap("F:/ProgrammingQT/QT-Lab1/super_spy.bmp"));
        QCursor cur1(pix3);
        spCursor = pix3;
        setCursor(spCursor);

        /*Задание 8.1
    В задании 5.1требовалось задать цвет для фона.
    Используйте диалог выбора цвета фона.*/

        QColor choose = QColorDialog::getColor(Qt::darkCyan);
        if(choose.isValid()){
            palette.setColor(QPalette::Active, QPalette::Window, choose);
        }
        else {
            palette.setColor(QPalette::Active, QPalette::Window, Qt::darkBlue);
        }

        /*Задание 8.1
    В задании 5.2 требовалось загрузить картинку для фона.
    Используйте диалог выбора файла для определения имени файла картинки.  Проверьте работу.*/

        QPixmap pix4;

        QString file1 = QFileDialog::getOpenFileName();
        if(!file1.isEmpty())
        {
           pix4.load(file1);
        }
        else {
            pix4.load("Disney_42.png");
        }
        palette.setBrush(QPalette::Inactive,QPalette::Window, QBrush(pix4));
        this->setPalette(palette);

        /*Задание 9.1
    Проверьте работу переводчика*/

        /*Задание 10
    Воспользуйтесь утилитой windeployqt     для развертывания приложения.
    Проверьте, что не испортилась ли Ваша работа по интернационализации. Подумайте,  как это исправить.
    Подсказка:
    Обратите внимание на то, что стандартные диалоги переводятся нормально. Это происходит потому, что файл перевода стандартных диалогов находится в директории /Spider/ exe/translations.*/
}

Lab1::~Lab1()
{

}
