/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonNewGame;
    QPushButton *buttonPause;
    QPushButton *buttonStop;
    QPushButton *buttonExit;
    QSpacerItem *verticalSpacer_3;
    QLabel *Score;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_2;
    Glass *widget;
    QVBoxLayout *verticalLayout;
    QLabel *NextLable;
    NextFigure *widget_2;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName(QString::fromUtf8("Tetris"));
        Tetris->resize(584, 471);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/Tetris.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tetris->setWindowIcon(icon);
        centralWidget = new QWidget(Tetris);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonNewGame = new QPushButton(centralWidget);
        buttonNewGame->setObjectName(QString::fromUtf8("buttonNewGame"));
        buttonNewGame->setMinimumSize(QSize(0, 30));
        buttonNewGame->setMaximumSize(QSize(150, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Images/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNewGame->setIcon(icon1);

        verticalLayout_2->addWidget(buttonNewGame);

        buttonPause = new QPushButton(centralWidget);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setMinimumSize(QSize(0, 30));
        buttonPause->setMaximumSize(QSize(150, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Images/PauseDisabled_26933.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPause->setIcon(icon2);

        verticalLayout_2->addWidget(buttonPause);

        buttonStop = new QPushButton(centralWidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setMinimumSize(QSize(0, 30));
        buttonStop->setMaximumSize(QSize(150, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Images/Stop_37106.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonStop->setIcon(icon3);

        verticalLayout_2->addWidget(buttonStop);

        buttonExit = new QPushButton(centralWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setMinimumSize(QSize(0, 30));
        buttonExit->setMaximumSize(QSize(150, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Images/exit_closethesession_close_6317.ico"), QSize(), QIcon::Normal, QIcon::Off);
        buttonExit->setIcon(icon4);

        verticalLayout_2->addWidget(buttonExit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        Score = new QLabel(centralWidget);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setMinimumSize(QSize(150, 20));
        Score->setMaximumSize(QSize(150, 20));
        Score->setFrameShape(QFrame::NoFrame);
        Score->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(Score);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(150, 0));
        lcdNumber->setMaximumSize(QSize(150, 30));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setLineWidth(1);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        widget = new Glass(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(220, 400));
        widget->setSizeIncrement(QSize(40, 20));
        widget->setProperty("m_rows", QVariant(0u));
        widget->setProperty("m_columns", QVariant(0u));

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        NextLable = new QLabel(centralWidget);
        NextLable->setObjectName(QString::fromUtf8("NextLable"));
        NextLable->setMinimumSize(QSize(0, 20));
        NextLable->setFrameShape(QFrame::NoFrame);
        NextLable->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(NextLable);

        widget_2 = new NextFigure(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(180, 80));

        verticalLayout->addWidget(widget_2);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(180, 280));
        textBrowser->setMaximumSize(QSize(180, 280));

        verticalLayout->addWidget(textBrowser);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        Tetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tetris);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 584, 21));
        Tetris->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tetris);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMovable(false);
        mainToolBar->setFloatable(false);
        Tetris->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tetris);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tetris->setStatusBar(statusBar);

        retranslateUi(Tetris);
        QObject::connect(buttonExit, SIGNAL(clicked()), Tetris, SLOT(close()));
        QObject::connect(buttonNewGame, SIGNAL(clicked()), widget, SLOT(slotNewGame()));
        QObject::connect(widget, SIGNAL(setScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(buttonPause, SIGNAL(clicked()), widget, SLOT(pauseGame()));
        QObject::connect(widget, SIGNAL(changePauseButton()), Tetris, SLOT(changeButtonPause()));
        QObject::connect(buttonStop, SIGNAL(clicked()), widget, SLOT(stopGame()));
        QObject::connect(widget, SIGNAL(sendNextFigure(Figure*)), widget_2, SLOT(getNextFigure(Figure*)));
        QObject::connect(widget, SIGNAL(stopNextFigure(bool*)), widget_2, SLOT(stopGame(bool*)));

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QMainWindow *Tetris)
    {
        Tetris->setWindowTitle(QApplication::translate("Tetris", "Tetris", nullptr));
        buttonNewGame->setText(QApplication::translate("Tetris", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        buttonPause->setText(QApplication::translate("Tetris", "\320\237\320\260\321\203\320\267\320\260", nullptr));
        buttonStop->setText(QApplication::translate("Tetris", "\320\241\321\202\320\276\320\277", nullptr));
        buttonExit->setText(QApplication::translate("Tetris", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        Score->setText(QApplication::translate("Tetris", "\320\241\321\207\320\265\321\202", nullptr));
        NextLable->setText(QApplication::translate("Tetris", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217", nullptr));
        textBrowser->setHtml(QApplication::translate("Tetris", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\260\320\262\320\270\320\273\320\260 \320\270\320\263\321\200\321\213.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\244\320\270\320\263\321\203\321\200\321\213 \321\200\320\260\320\267\320\275\321\213\321\205 \321\206\320\262\320\265\321\202\320\276\320\262 \321\201 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\274 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\276"
                        "\320\274 \320\264\320\262\320\270\320\266\321\203\321\202\321\201\321\217 \320\262\320\275\320\270\320\267. \320\237\321\200\320\270 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\270 3\321\205 \320\270 \320\261\320\276\320\273\320\265\320\265 \321\206\320\262\320\265\321\202\320\276\320\262 \320\262 \320\276\320\264\320\270\320\275 \321\200\321\217\320\264 (\320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\321\213\320\271 \320\270\320\273\320\270 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\321\213\320\271) - \320\277\320\276\320\273\320\265 \320\276\321\207\320\270\321\211\320\260\320\265\321\202\321\201\321\217.</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\246\320\265\320\273\321\214 \320\270\320\263\321\200\321\213.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260\320\261\321\200\320\260\321\202\321\214 \320\275\320\260\320\270\320\261\320\276\320\273\321\214\321\210\320\265\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\207\320\272\320\276\320\262.</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\321\202\321\200\320\265\320\273\320\272\320\270 \320\262\320\273\320\265\320\262\320\276 \320\270 \320\262\320\277\321\200\320\260\320\262\320\276 - \321\201\320\264\320\262\320\270\320\275\321\203\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203 \320\262 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\320\276\320\274 "
                        "\320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\270.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\321\202\321\200\320\265\320\273\320\272\320\270 \320\262\320\262\320\265\321\200\321\205 \320\270 \320\262\320\275\320\270\320\267 - \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\320\264\320\260\321\206\320\270\321\216 \321\206\320\262\320\265\321\202\320\276\320\262 \320\262 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\320\276\320\274 \320\275\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\270.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\276\320\261\320\265\320\273 - \321\203\321\201\320\272\320\276\321\200\320\270\321\202\321\214 \320\277\320\260\320\264\320\265\320\275\320\270\320\265 \321\204\320"
                        "\270\320\263\321\203\321\200\321\213.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
