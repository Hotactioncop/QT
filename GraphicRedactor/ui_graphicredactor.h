/********************************************************************************
** Form generated from reading UI file 'graphicredactor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICREDACTOR_H
#define UI_GRAPHICREDACTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicRedactor
{
public:
    QAction *actionactionLoad;
    QAction *actionactionSave;
    QAction *actionactionExit;
    QAction *actionRectangle;
    QAction *actionEllipse;
    QAction *actionColors;
    QAction *actionOptions;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuWhat;
    QMenu *menuTools;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphicRedactor)
    {
        if (GraphicRedactor->objectName().isEmpty())
            GraphicRedactor->setObjectName(QString::fromUtf8("GraphicRedactor"));
        GraphicRedactor->resize(725, 442);
        actionactionLoad = new QAction(GraphicRedactor);
        actionactionLoad->setObjectName(QString::fromUtf8("actionactionLoad"));
        actionactionSave = new QAction(GraphicRedactor);
        actionactionSave->setObjectName(QString::fromUtf8("actionactionSave"));
        actionactionExit = new QAction(GraphicRedactor);
        actionactionExit->setObjectName(QString::fromUtf8("actionactionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionactionExit->setIcon(icon);
        actionRectangle = new QAction(GraphicRedactor);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Images/Rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon1);
        actionEllipse = new QAction(GraphicRedactor);
        actionEllipse->setObjectName(QString::fromUtf8("actionEllipse"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Images/Ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon2);
        actionColors = new QAction(GraphicRedactor);
        actionColors->setObjectName(QString::fromUtf8("actionColors"));
        actionOptions = new QAction(GraphicRedactor);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        actionCopy = new QAction(GraphicRedactor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionCut = new QAction(GraphicRedactor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionPaste = new QAction(GraphicRedactor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        centralWidget = new QWidget(GraphicRedactor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        graphicsView_2 = new QGraphicsView(splitter);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        splitter->addWidget(graphicsView_2);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        splitter->addWidget(graphicsView);

        horizontalLayout_2->addWidget(splitter);

        GraphicRedactor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphicRedactor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 725, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuWhat = new QMenu(menuBar);
        menuWhat->setObjectName(QString::fromUtf8("menuWhat"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        GraphicRedactor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphicRedactor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GraphicRedactor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GraphicRedactor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphicRedactor->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuWhat->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionactionLoad);
        menuFile->addAction(actionactionSave);
        menuFile->addAction(actionactionExit);
        menuWhat->addAction(actionRectangle);
        menuWhat->addAction(actionEllipse);
        menuTools->addAction(actionColors);
        menuTools->addAction(actionOptions);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        mainToolBar->addAction(actionRectangle);
        mainToolBar->addAction(actionEllipse);
        mainToolBar->addAction(actionColors);
        mainToolBar->addAction(actionOptions);
        mainToolBar->addAction(actionactionExit);

        retranslateUi(GraphicRedactor);

        QMetaObject::connectSlotsByName(GraphicRedactor);
    } // setupUi

    void retranslateUi(QMainWindow *GraphicRedactor)
    {
        GraphicRedactor->setWindowTitle(QApplication::translate("GraphicRedactor", "GraphicRedactor", nullptr));
        actionactionLoad->setText(QApplication::translate("GraphicRedactor", "Load", nullptr));
        actionactionSave->setText(QApplication::translate("GraphicRedactor", "Sacve", nullptr));
        actionactionExit->setText(QApplication::translate("GraphicRedactor", "Exit", nullptr));
        actionRectangle->setText(QApplication::translate("GraphicRedactor", "Rectangle", nullptr));
        actionEllipse->setText(QApplication::translate("GraphicRedactor", "Ellipse", nullptr));
        actionColors->setText(QApplication::translate("GraphicRedactor", "Colors", nullptr));
        actionOptions->setText(QApplication::translate("GraphicRedactor", "Options", nullptr));
        actionCopy->setText(QApplication::translate("GraphicRedactor", "Copy", nullptr));
        actionCut->setText(QApplication::translate("GraphicRedactor", "Cut", nullptr));
        actionPaste->setText(QApplication::translate("GraphicRedactor", "Paste", nullptr));
        menuFile->setTitle(QApplication::translate("GraphicRedactor", "File", nullptr));
        menuWhat->setTitle(QApplication::translate("GraphicRedactor", "What", nullptr));
        menuTools->setTitle(QApplication::translate("GraphicRedactor", "Tools", nullptr));
        menuEdit->setTitle(QApplication::translate("GraphicRedactor", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphicRedactor: public Ui_GraphicRedactor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICREDACTOR_H
