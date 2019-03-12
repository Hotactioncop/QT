#include "lab2_3.h"
#include <QDebug>
#include <QString>
#include <QIcon>
#include <QApplication>
#include <QDesktopWidget>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QCursor>
#include <QMouseEvent>
#include <QToolTip>
#include <QPainter>
#include <QPalette>

Lab2_3::Lab2_3(QWidget *parent)
    : QWidget(parent)
{
    rec= this->rect();
}

Lab2_3::~Lab2_3()
{

}


void Lab2_3::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(!vect.isEmpty()){
            vect.clear();
        }
        this->timerID = startTimer(0);
        qDebug() << this->timerID;

        point1=event->pos();
        point2=QPoint(point1.x()+1,point1.y()+1);
    }
    if(event->button()==Qt::RightButton)
    {
        killTimer(timerID);
        qDebug() << this->timerID;
    }
}
void Lab2_3::timerEvent(QTimerEvent *event)
{
    repaint();
}

void Lab2_3::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    pen.setPen(QPen(Qt::darkCyan,2,Qt::SolidLine));
    if(!vect.isEmpty()){
        for(auto&z:vect){
            pen.drawLine(z.first,z.second);
        }
    }
    if(rec.width()<=point2.x()){
        vect.push_back(qMakePair<QPoint>(point1,point2));
        if(point1.y()<point2.y()){
            point1=point2;
            point2=QPoint(point2.x()-1,point2.y()+1);
        }
        else {
            point1=point2;
            point2=QPoint(point2.x()-1,point2.y()-1);
        }
    }
    if(rec.height()<=point2.y()){
        vect.push_back(qMakePair<QPoint>(point1,point2));
        if(point1.x()<point2.x()){
            point1=point2;
            point2=QPoint(point2.x()+1,point2.y()-1);
        }
        else {
            point1=point2;
            point2=QPoint(point2.x()-1,point2.y()-1);
        }
    }
    if(point2.y()<=0){
        vect.push_back(qMakePair<QPoint>(point1,point2));
        if(point1.x()<point2.x()){
            point1=point2;
            point2=QPoint(point2.x()+1,point2.y()+1);
        }
        else {
            point1=point2;
            point2=QPoint(point2.x()-1,point2.y()+1);
        }
    }
    if(point2.x()<=0){
        vect.push_back(qMakePair<QPoint>(point1,point2));
        if(point1.y()<point2.y()){
            point1=point2;
            point2=QPoint(point2.x()+1,point2.y()+1);
        }
        else {
            point1=point2;
            point2=QPoint(point2.x()+1,point2.y()-1);
        }
    }
    if(point1.x()<point2.x() && point1.y()<point2.y()){
        point2=QPoint(point2.x()+1,point2.y()+1);
    }
    if(point1.x()>point2.x() && point1.y()<point2.y()){
        point2=QPoint(point2.x()-1,point2.y()+1);
    }
    if(point1.x()>point2.x() && point1.y()>point2.y()){
        point2=QPoint(point2.x()-1,point2.y()-1);
    }
    if(point1.x()<point2.x() && point1.y()>point2.y()){
        point2=QPoint(point2.x()+1,point2.y()-1);
    }
    if(timerID!=0){
        pixs.load("spider1.bmp");
        pixs.setMask(QBitmap("spider1.bmp"));
        pen.drawLine(point1,point2);
        pen.drawPixmap(point2.x(),point2.y(),pixs);

    }
}



void Lab2_3::resizeEvent(QResizeEvent *event)
{
    rec=this->rect();
}
