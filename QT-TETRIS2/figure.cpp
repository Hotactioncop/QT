#include "figure.h"

Figure::Figure()
{
    figView = static_cast<figurs>(qrand()%7);
    if (figView==0){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(80,20)};
        figCol = Qt::darkBlue;
    }
    else if(figView==1){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(120,20)};
        figCol = Qt::yellow;
    }
    else if(figView==2){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(100,20)};
        figCol = Qt::green;
    }
    else if(figView==3){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(140,0)};
        figCol = Qt::darkCyan;
    }
    else if(figView==4){
        myFigure=QVector<QPoint>{QPoint(80,20),QPoint(100,20),QPoint(100,00),QPoint(120,00)};
        figCol = Qt::magenta;
    }
    else if(figView==5){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(100,20),QPoint(120,20)};
        figCol = Qt::blue;
    }
    else if(figView==6){
        myFigure=QVector<QPoint>{QPoint(100,0),QPoint(120,0),QPoint(100,20),QPoint(120,20)};
        figCol = Qt::white;
    }
}

void Figure::rotate()
{
    QPoint p = myFigure[1];
    if(figView!=6){
        for(int i = 0; i <myFigure.size(); i++){
            int X = myFigure[i].x()-p.x();
            int Y = myFigure[i].y()-p.y();
           myFigure[i] = QPoint(p.x()+Y,p.y()-X);
        }
    }
}

void Figure::setDown(uint W)
{
    for(auto&X:myFigure){
        X = QPoint(X.x(),X.y()+W);
    }
}

void Figure::refresh()
{
    figView = static_cast<figurs>(qrand()%7);
    if (figView==0){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(80,20)};
        figCol = Qt::darkBlue;
    }
    else if(figView==1){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(120,20)};
        figCol = Qt::yellow;
    }
    else if(figView==2){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(100,20)};
        figCol = Qt::green;
    }
    else if(figView==3){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(120,0),QPoint(140,0)};
        figCol = Qt::darkCyan;
    }
    else if(figView==4){
        myFigure=QVector<QPoint>{QPoint(80,20),QPoint(100,20),QPoint(100,00),QPoint(120,00)};
        figCol = Qt::magenta;
    }
    else if(figView==5){
        myFigure=QVector<QPoint>{QPoint(80,0),QPoint(100,0),QPoint(100,20),QPoint(120,20)};
        figCol = Qt::blue;
    }
    else if(figView==6){
        myFigure=QVector<QPoint>{QPoint(100,0),QPoint(120,0),QPoint(100,20),QPoint(120,20)};
        figCol = Qt::white;
    }
}

void Figure::figureMove(bool direction, uint W)
{
    if(direction){
        for(auto&X:myFigure){
            X = QPoint(X.x()+W, X.y());
        }
    }
    else{
        for(auto&X:myFigure){
            X = QPoint(X.x()-W, X.y());
        }
    }
}
