#ifndef LAB1_H
#define LAB1_H

#include <QWidget>

class Lab1 : public QWidget
{
    Q_OBJECT
    QCursor spCursor;
    bool isDrawing;
    QPoint _point;
    QPoint _point1;
    QRect _rect;

public:
    Lab1(QWidget *parent = 0);
    ~Lab1();
};

#endif // LAB1_H
