#ifndef MYSCENE_H
#define MYSCENE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QAbstractGraphicsShapeItem>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
    MyScene* scene;
    QAbstractGraphicsShapeItem* current;
    bool m_drawingInProcess;
    enum {Rect,Ellips,Circle} ShapeType;
    QPointF m_startPoint;
    QColor col;
    uint wide;
    Qt::PenStyle penSt;
    QBrush m_brush;
public:
    explicit MyScene(QWidget *parent = nullptr);

signals:

public slots:

    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
