#include "lab2.h"
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
#include<QToolTip>
#include<QPainter>

Lab2::Lab2(QWidget *parent)
    : QWidget(parent)
{
    spCursor = Qt::CrossCursor;
    setCursor(spCursor);
    //_rect.setSize(QSize(960,540));
    setGeometry(480,270,960,540);
    _rect=this->rect();
    QString str2 = "Spy bear width=";
    str2+=QString().setNum(_rect.width());
    str2+="; height=";
     str2+=QString().setNum(_rect.height());
    setWindowTitle(str2);
}

Lab2::~Lab2()
{

}



void Lab2::mousePressEvent(QMouseEvent *event)
{
    _point = pos();
    if(event->button()==Qt::RightButton && event->modifiers() == Qt::ControlModifier){
        QString str;
        QTextStream tstream(&str);
        tstream << "x=" << event->pos().x() << "; y=" << event->pos().y();
        //QToolTip::showText(this->pos(), str);
        //qDebug() << tstream();
        QString str2 = "x=";
        str2+=QString().setNum(event->pos().x());
        str2+="; y=";
        str2+=QString().number(event->pos().y());
        QToolTip::showText(this->pos(), str2);
    }
    else if (event->button()==Qt::LeftButton){
        isDrawing = true;
        _point = event->pos();//this->pos();
        qDebug() << "isDrawing == true";

        QPixmap pixs("super_spy.bmp");
        pixs.setMask(QBitmap("super_spy.bmp"));
        spCursor = pixs;
        setCursor(spCursor);
    }
}

void Lab2::mouseReleaseEvent(QMouseEvent *event)
{
    if (isDrawing == true){
        isDrawing = false;
        setCursor(Qt::CrossCursor);
        unsetLocale();
        qDebug() << "isDrawing == false";
        repaint();
    }

}

void Lab2::mouseMoveEvent(QMouseEvent *event)
{
    if(isDrawing==true){
        _point = event->pos();
       // repaint();
    }
    //QRect rect=this->rect();
    //qDebug() << event->pos();
    //qDebug() << rect;

    if(!_rect.contains(event->pos())){
        unsetCursor();
        //if(event->pos().x()<0){spCursor.setPos(mapToGlobal(rect.topLeft()).x(),mapToGlobal(_point).y());}
        //if(event->pos().y()<0){spCursor.setPos(mapToGlobal(rect.topLeft()).x(),mapToGlobal(_point).y());}
    }
   else if (_rect.contains(event->pos())) {
        setCursor(spCursor);
        repaint ();
    }
}

void Lab2::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    if(isDrawing==true){
    pen.setPen(QPen(Qt::darkCyan,1,Qt::SolidLine));
    pen.drawLine(_point, _rect.topLeft());
    pen.drawLine(_point, _rect.topRight());
    pen.drawLine(_point, QPoint(_rect.width(),_rect.height()));
    pen.drawLine(_point, QPoint(0,_rect.height()));
    pen.drawLine(_point, QPoint(_rect.width(),_rect.height()));
    pen.drawLine(_point, QPoint(0,_rect.height()));
    pen.drawLine(_point, QPoint(_rect.width()/2,0));
    pen.drawLine(_point, QPoint(0,_rect.height()/2));
    pen.drawLine(_point, QPoint(_rect.width()/2,_rect.height()));
    pen.drawLine(_point, QPoint(_rect.width(),_rect.height()/2));

    pen.drawLine(QPoint(_point.x()/2,_point.y()/2), QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/3,_point.y()/3));
    pen.drawLine(QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/3,_point.y()/3), QPoint(_point.x()+(_rect.topRight().x()-_point.x())/2,_point.y()/2));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())/2,_point.y()/2), QPoint(_point.x()+(_rect.topRight().x()-_point.x())*2/3,_rect.height()/2+(_point.y()-_rect.height()/2)/3));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())*2/3,_rect.height()/2+(_point.y()-_rect.height()/2)/3),QPoint(_point.x()+(_rect.topRight().x()-_point.x())/2,_point.y()+(_rect.height()-_point.y())/2));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())/2,_point.y()+(_rect.height()-_point.y())/2),QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/3,_point.y()+(_rect.height()-_point.y())*2/3));
    pen.drawLine(QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/3,_point.y()+(_rect.height()-_point.y())*2/3),QPoint(_point.x()/2,_point.y()+(_rect.height()-_point.y())/2));
    pen.drawLine(QPoint(_point.x()/2,_point.y()+(_rect.height()-_point.y())/2),QPoint(_point.x()/3,_rect.height()/2+(_point.y()-_rect.height()/2)/3));
    pen.drawLine(QPoint(_point.x()/3,_rect.height()/2+(_point.y()-_rect.height()/2)/3),QPoint(_point.x()/2,_point.y()/2));

    pen.drawLine(QPoint(_point.x()/4,_point.y()/4), QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/6,_point.y()/6));
    pen.drawLine(QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/6,_point.y()/6), QPoint(_point.x()+(_rect.topRight().x()-_point.x())*3/4,_point.y()/4));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())*3/4,_point.y()/4), QPoint(_point.x()+(_rect.topRight().x()-_point.x())*5/6,_rect.height()/2+(_point.y()-_rect.height()/2)/6));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())*5/6,_rect.height()/2+(_point.y()-_rect.height()/2)/6),QPoint(_point.x()+(_rect.topRight().x()-_point.x())*3/4,_point.y()+(_rect.height()-_point.y())*3/4));
    pen.drawLine(QPoint(_point.x()+(_rect.topRight().x()-_point.x())*3/4,_point.y()+(_rect.height()-_point.y())*3/4),QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/6,_point.y()+(_rect.height()-_point.y())*5/6));
    pen.drawLine(QPoint(_rect.width()/2+(_point.x()-_rect.width()/2)/6,_point.y()+(_rect.height()-_point.y())*5/6),QPoint(_point.x()/4,_point.y()+(_rect.height()-_point.y())*3/4));
    pen.drawLine(QPoint(_point.x()/4,_point.y()+(_rect.height()-_point.y())*3/4),QPoint(_point.x()/6,_rect.height()/2+(_point.y()-_rect.height()/2)/6));
    pen.drawLine(QPoint(_point.x()/6,_rect.height()/2+(_point.y()-_rect.height()/2)/6),QPoint(_point.x()/4,_point.y()/4));
    }

}


void Lab2::resizeEvent(QResizeEvent *event)
{
    _rect = this->rect();
    QString str2 = "Spy bear width=";
    str2+=QString().setNum(_rect.width());
    str2+="; height=";
    str2+=QString().setNum(_rect.height());
    setWindowTitle(str2);
}
