#include "glass.h"
#include <QPainter>
#include <qDebug>

Glass::Glass(QWidget *parent) : QWidget(parent)
{

    QObject::connect(this,SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()),Qt::QueuedConnection);
    emit signalGlassInit();
    qDebug() << "Glass";
}

void Glass::clearGlass()
{
    qDebug() << "clearGlass";
    for(auto&x:glassArray)
    {
        x.fill(emptyCell);
    }
}

void Glass::slotGlassInit()
{
    qDebug() << "slotGlassInit";
    glassArray.resize(m_rows);
    for(auto&x:glassArray)
    {
        glassArray.resize(m_columns);
    }
    s.setWidth(W*m_columns);
    s.setHeight(W*m_rows);
    setFixedSize(s);
    repaint();
}


void Glass::paintEvent(QPaintEvent *event)
{
    qDebug() << "I'm drawing";
    QPainter pain(this);
    pain.setBrush(Qt::red);
    pain.drawRect(0,0,19,19);
//    for(auto&x:glassArray)
//    {
//        for(auto&y:x)
//        {
//            pain.setBrush(QBrush(y));
//            pain.fillRect()
//        }
//    }
}
