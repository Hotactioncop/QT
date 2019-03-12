#ifndef LAB2_2_H
#define LAB2_2_H

#include <QWidget>
#include <QVector>
#include <QPair>

class Lab2_2 : public QWidget
{
    Q_OBJECT
    QCursor spCursor;
    bool isDrawing = false;
    QPoint point1, point2;
    QRect _rect;
    QVector<QPair<QPoint,QPoint>> vec;

public:
    Lab2_2(QWidget *parent = 0);
    ~Lab2_2();

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
};

#endif // LAB2_2_H
