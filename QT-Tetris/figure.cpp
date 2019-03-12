#include "figure.h"
#include <QColor>
#include <QtAlgorithms>
#include <iostream>

void Figure::figureMove(uint n_i, uint n_j)
{
    m_i= n_i;
    m_j= n_j;
}

QPoint Figure::getIndex()
{
    return QPoint(this->m_i,this->m_j);
}

void Figure::rotateColors(bool b)
{
    if(b){
        std::swap(arr[0],arr[1]);
        std::swap(arr[1],arr[2]);
    }
    else {
        std::swap(arr[1],arr[2]);
        std::swap(arr[0],arr[1]);
    }
}

void Figure::MakeRandomColors()
{
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    for(auto&x:arr)
    {
        x = e_col[qrand()%3];
    }
}

QColor Figure::getCol(int num)
{
    return arr[num];
}

Figure::Figure(uint n_W):m_W(n_W)
{
}
