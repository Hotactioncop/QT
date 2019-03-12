#include "mypicture.h"
#include <QPainter>
#include <qDebug>
#include <QFileDialog>

MyPicture::MyPicture(QWidget *parent) : QWidget(parent)
{
    pixmap.load("F:/ProgrammingQT/QT-Lab4/Images/WomenAndDog.jpg");
    scale = 100;
}


void MyPicture::paintEvent(QPaintEvent *event)
{
    QPainter pen(this);
    if (_style==0)
    {
        pen.scale(scale, scale);
        pen.drawPixmap(this->rect(), pixmap);
    }
    else if (_style==1)
    {
        pixmap.scaled(this->rect().width(),this->rect().height(), Qt::KeepAspectRatio);
        QPixmap tmp= pixmap.scaled(this->width()*scale/100, this->height()*scale/100);
        pen.drawPixmap(0,0, tmp);
    }
    else if (_style==2)
    {
        QRectF source(0.0,0.0,pixmap.width()*scale/100,pixmap.height()*scale/100);
        QRectF target(0.0,0.0,this->width()*scale/100,this->height()*scale/100);
        pen.drawPixmap(target, pixmap, source);
    }
}

void MyPicture::scaleChanged(int index)
{
    if (_style==0)
    {
        scale = index/100.;
    }
    else{
        scale = index;
    }
    repaint();
}

void MyPicture::chooseStyleFirst()
{
    _style = 0;
    scale = 1;
    repaint();
}
void MyPicture::chooseStyleSecond()
{
    _style = 1;
    scale = 100;
    repaint();

}
void MyPicture::chooseStyleThird()
{
    _style =2;
    scale = 100;
    repaint();
}

void MyPicture::openFile()
{
    QString file1 = QFileDialog::getOpenFileName();
    if(!file1.isEmpty())
    {
       pixmap.load(file1);
    }
    _style = 0;
    scale = 1;
    repaint();
}

