#include "tetris.h"
#include "ui_tetris.h"
#include <QPalette>
#include <QPixmap>
#include <QBrush>

TETRIS::TETRIS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TETRIS)
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    ui->setupUi(this);
    QPixmap pix;
    QPalette palette;
    pix.load("F:/ProgrammingQT/QT-TETRIS2/Images/Background3.jpg");
    palette.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(palette);
}

TETRIS::~TETRIS()
{
    delete ui;
}
