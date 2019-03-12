#include "lab2_2.h"
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

Lab2_2::Lab2_2(QWidget *parent)
    : QWidget(parent)
{
    setCursor(Qt::CrossCursor);
    _rect = this->rect();
    this->setMouseTracking(true);
}

Lab2_2::~Lab2_2()
{

}


void Lab2_2::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        isDrawing=true;
        point1=event->pos();
        qDebug() << "mousePressEvent";
    }
    if(event->button()==Qt::RightButton && event->modifiers() == Qt::ControlModifier)
    {
        if(!vec.isEmpty()){
            vec.pop_back();
            update();
        }
    }
    else if(event->button()==Qt::RightButton)
    {
        vec.clear();
        repaint();
    }
}

void Lab2_2::mouseReleaseEvent(QMouseEvent *event)
{
    if(isDrawing==true){
        isDrawing=false;
        unsetLocale();
        qDebug() << "mouseReleaseEvent";
        vec.push_back(qMakePair(point1,event->pos()));

    }
}

void Lab2_2::mouseMoveEvent(QMouseEvent *event)
{
    bool find =false;
    qDebug() << isDrawing;

    if(spCursor!=Qt::SizeFDiagCursor){
        for(auto&z:vec)
        {
            QRect rec(z.second.x(),z.second.y(),5,5);
           // if(event->pos()==z.second)
            if(rec.contains(event->pos()))
            {
               setCursor(Qt::SizeFDiagCursor);
                find = true;
                if(isDrawing==true)
                {
                    point1=z.first;
                    auto*it=vec.end();
                    --it;
                    z=*it;
                    vec.pop_back();
                    point2=event->pos();
                    repaint();
                }
            }
        }
    }

    if(find ==false && isDrawing==false)
    {
        setCursor(Qt::CrossCursor);
    }
    if(isDrawing==true){
        if(spCursor!=Qt::SizeFDiagCursor){
            point2=event->pos();
            repaint();
            qDebug() << "mouseMoveEvent";
        }
    }
}

void Lab2_2::paintEvent(QPaintEvent *event)
{

    QPainter pen(this);
    pen.setPen(QPen(Qt::darkCyan,2,Qt::SolidLine));
    if(!vec.isEmpty()){
        for (auto&z:vec)
        {
            pen.drawRect(QRect(z.first, z.second));
        }
    }
    if(isDrawing==true){
        pen.drawRect(QRect(point1,point2));
    }
}
