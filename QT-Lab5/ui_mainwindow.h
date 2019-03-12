/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelNextFigure;
    QFrame *frame;
    QSpacerItem *verticalSpacer;
    QWidget *Glass;
    QVBoxLayout *verticalLayout_2;
    QPushButton *buttonNewGame;
    QPushButton *buttonExit;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelScore;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(680, 649);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelNextFigure = new QLabel(centralWidget);
        labelNextFigure->setObjectName(QString::fromUtf8("labelNextFigure"));
        labelNextFigure->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelNextFigure);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        Glass = new QWidget(centralWidget);
        Glass->setObjectName(QString::fromUtf8("Glass"));
        Glass->setFocusPolicy(Qt::StrongFocus);
        Glass->setProperty("rows", QVariant(20u));
        Glass->setProperty("columns", QVariant(9u));

        gridLayout->addWidget(Glass, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonNewGame = new QPushButton(centralWidget);
        buttonNewGame->setObjectName(QString::fromUtf8("buttonNewGame"));
        buttonNewGame->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setPointSize(11);
        buttonNewGame->setFont(font);

        verticalLayout_2->addWidget(buttonNewGame);

        buttonExit = new QPushButton(centralWidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setMinimumSize(QSize(0, 40));
        buttonExit->setFont(font);

        verticalLayout_2->addWidget(buttonExit);

        verticalSpacer_2 = new QSpacerItem(20, 208, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        labelScore = new QLabel(centralWidget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelScore);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_3 = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(buttonExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labelNextFigure->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217", nullptr));
        buttonNewGame->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
        buttonExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        labelScore->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
