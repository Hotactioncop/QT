#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    QPixmap pix;
    QPalette palette;
    pix.load("Images/BackgroundCrystals.png");
    palette.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePauseButton()
{
    if(ui->buttonPause->text()=="Pause"){
        ui->buttonPause->setText("Continue");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/Start_37108.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->buttonPause->setIcon(icon);
    }
    else{
        ui->buttonPause->setText("Pause");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/PauseDisabled_26933.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->buttonPause->setIcon(icon);
    }
}
