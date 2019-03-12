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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mypicture.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSize_change_first;
    QAction *actionSize_change_second;
    QAction *actionCut;
    QAction *actionAbout;
    QAction *actionOpen_file;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QLabel *label_3;
    MyPicture *widget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *Act;
    QMenu *menuInformation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(761, 614);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Images/icon2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSize_change_first = new QAction(MainWindow);
        actionSize_change_first->setObjectName(QString::fromUtf8("actionSize_change_first"));
        actionSize_change_second = new QAction(MainWindow);
        actionSize_change_second->setObjectName(QString::fromUtf8("actionSize_change_second"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Images/Disney_42.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(3);

        horizontalLayout_2->addWidget(lineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_2->addWidget(label_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(100);
        spinBox->setValue(100);

        horizontalLayout->addWidget(spinBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setToolTipDuration(5);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);

        horizontalLayout_3->addWidget(horizontalSlider);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_3->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 2);

        widget = new MyPicture(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(false);
        widget->setMinimumSize(QSize(0, 440));

        gridLayout_2->addWidget(widget, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 761, 21));
        Act = new QMenu(menuBar);
        Act->setObjectName(QString::fromUtf8("Act"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QString::fromUtf8("menuInformation"));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit);
        label->setBuddy(spinBox);
        label_3->setBuddy(horizontalSlider);
#endif // QT_NO_SHORTCUT

        mainToolBar->addAction(actionOpen_file);
        mainToolBar->addAction(actionSize_change_first);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSize_change_second);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);
        mainToolBar->addSeparator();
        menuBar->addAction(Act->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        Act->addAction(actionOpen_file);
        Act->addAction(actionSize_change_first);
        Act->addAction(actionSize_change_second);
        Act->addAction(actionCut);
        menuInformation->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(spinBox, SIGNAL(valueChanged(QString)), lineEdit, SLOT(setText(QString)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), MainWindow, SLOT(slotToInt(QString)));
        QObject::connect(MainWindow, SIGNAL(mySignal(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(scaleChanged(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(setStatusBar(int)));
        QObject::connect(actionSize_change_first, SIGNAL(triggered()), widget, SLOT(chooseStyleFirst()));
        QObject::connect(actionSize_change_second, SIGNAL(triggered()), widget, SLOT(chooseStyleSecond()));
        QObject::connect(actionCut, SIGNAL(triggered()), widget, SLOT(chooseStyleThird()));
        QObject::connect(actionOpen_file, SIGNAL(triggered()), widget, SLOT(openFile()));


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSize_change_first->setText(QApplication::translate("MainWindow", "Size change (first)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSize_change_first->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_NO_SHORTCUT
        actionSize_change_second->setText(QApplication::translate("MainWindow", "Size change (second)", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSize_change_second->setShortcut(QApplication::translate("MainWindow", "Ctrl+3", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+4", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+5", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "&EditBuddy", nullptr));
        label->setText(QApplication::translate("MainWindow", "&SpinBuddy", nullptr));
#ifndef QT_NO_TOOLTIP
        horizontalSlider->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "&SliderBuddy", nullptr));
        Act->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuInformation->setTitle(QApplication::translate("MainWindow", "Information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
