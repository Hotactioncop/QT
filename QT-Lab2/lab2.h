#ifndef LAB2_H
#define LAB2_H

#include <QWidget>

class Lab2 : public QWidget
{
    Q_OBJECT
    QCursor spCursor;
    bool isDrawing = false;
    QPoint _point;
    QRect _rect;



public:
    Lab2(QWidget *parent = 0);
    ~Lab2();

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // LAB2_H
