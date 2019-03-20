#include "myscene.h"

MyScene::MyScene(QWidget *parent) : QGraphicsScene(parent)
{
    QGraphicsScene::setSceneRect(0,0,500,500);
}


void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        qDebug() << "WOHOO";
        m_startPoint = event->pos();
        QGraphicsRectItem *m_current = new QGraphicsRectItem(m_startPoint.x(),m_startPoint.y(),0.,0.);
        QAbstractGraphicsShapeItem::setPen(m_current);
    }
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}
