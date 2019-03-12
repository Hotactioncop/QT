#include "nextfigure.h"
#include <QPainter>
#include <qDebug>

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    qDebug() << "NextFigure";

}
void NextFigure::getNextFigure(Figure *other)
{
    next=other;
    gameOn = true;
    repaint();
    qDebug() << "getNextFigure";

}

void NextFigure::stopGame(bool *game)
{
    gameOn = *game;
    repaint();
}


void NextFigure::paintEvent(QPaintEvent *event)
{
    if(gameOn){
        qDebug() << "NextFigure::paintEvent";
        QPainter pain(this);
        pain.fillRect((width()-20)/2, 0,20-1,20-1,next->getCol(0));
        pain.fillRect((width()-20)/2, 20,20-1,20-1,next->getCol(1));
        pain.fillRect((width()-20)/2, 40,20-1,20-1,next->getCol(2));
    }
}

NextFigure::~NextFigure()
{
    next = nullptr;
}
