#include "tetris.h"
#include "ui_tetris.h"
#include <QPalette>

Tetris::Tetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tetris)
{
    ui->setupUi(this);
    QPixmap pix;
    QPalette palette;
    pix.load("Images/BackGround.jpg");
    palette.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(palette);
}

Tetris::~Tetris()
{
    delete ui;
}

void Tetris::changeButtonPause()
{
    if(ui->buttonPause->text()=="Пауза"){
        ui->buttonPause->setText("Продолжить");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/Start_37108.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->buttonPause->setIcon(icon);
    }
    else{
        ui->buttonPause->setText("Пауза");
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/PauseDisabled_26933.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ui->buttonPause->setIcon(icon);
    }
}
