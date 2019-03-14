#include "glass.h"
#include <QKeyEvent>

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    glassArray.resize(m_rows);
    for(auto&X:glassArray){
        X.resize(m_columns);
        X.fill(emptyCell);
    }
    s.setWidth(W*m_columns);
    s.setHeight(W*m_rows);
    setFixedSize(s);
    current = new Figure;
    next = new Figure;
}

void Glass::recolorGlass()
{
    for(auto&X:current->myFigure){

        glassArray[X.y()/W][X.x()/W]=current->figCol;
    }
    std::swap(next,current);

    next->refresh();
}

void Glass::spaceFigure()
{
    for(auto&X:current->myFigure){
        qDebug() << "X=" <<(X.y()+W)/W << ", Y=" << X.x()/W;
        if(X.y()==W*(m_rows-1) || glassArray[(X.y()+W)/W][X.x()/W]!=emptyCell){
            qDebug()<< "Вылетел тут";
            recolorGlass();
            repaint();
            return;
        }
    }
    current->setDown(W);
}

void Glass::gameStart()
{
    if(gameOn){
        killTimer(idTimer);
        for(auto&X:glassArray){
            X.fill(emptyCell);
        }
        current->refresh();
        next->refresh();
    }
    gameOn = true;
    score = 0;
    idTimer = startTimer(300);
    this->setFocus();
}


void Glass::timerEvent(QTimerEvent *event)
{
    if(gameOn){
        for(auto&X:current->myFigure){
            qDebug() << "X=" <<(X.y()+W)/W << ", Y=" << X.x()/W;
            if(X.y()==W*(m_rows-1) || glassArray[(X.y()+W)/W][X.x()/W]!=emptyCell){
                qDebug()<< "Вылетел тут";
                recolorGlass();
                repaint();
                return;
            }
        }
        current->setDown(W);
        repaint();
    }
}

void Glass::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    for(uint i = 0; i<m_columns; i++){
        for(uint j = 0; j<m_rows; j++){
            pen.fillRect(i*W,j*W,W-1,W-1,glassArray[j][i]);
        }
    }
    if(gameOn){
        int i = 0;
        for(auto&X:current->myFigure){
                i++;
           pen.fillRect(X.x(),X.y(),W-1,W-1,current->figCol);
        }
    }
}


void Glass::keyPressEvent(QKeyEvent *event)
{
    if(gameOn){
        if(event->key()==Qt::Key_Up){
           current->rotate();
           repaint();
        }
        else if(event->key()==Qt::Key_Left){
            for(auto&X:current->myFigure){
                if(X.x()==0*W || glassArray[X.y()/W][(X.x()-W)/W]!=emptyCell){
                    return;
                }
            }
            current->figureMove(false, W);
            repaint();
        }
        else if(event->key()==Qt::Key_Right){
            for(auto&X:current->myFigure){
                if(X.x()==(m_columns-1)*W || glassArray[X.y()/W][(X.x()+W)/W]!=emptyCell){
                    return;
                }
            }
            current->figureMove(true, W);
            repaint();
        }
        else if(event->key()==Qt::Key_Space){
            spaceFigure();
            repaint();
        }
    }
}
