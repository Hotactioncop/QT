#ifndef LAB2_3_H
#define LAB2_3_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <QTimer>

class Lab2_3 : public QWidget
{
    Q_OBJECT
    int timerID = 0;
    QObject spider;
    QPoint point1, point2;
    QPixmap pixs;
    QRect rec;
    QVector<QPair<QPoint,QPoint>> vect;


public:
    Lab2_3(QWidget *parent = 0);
    ~Lab2_3();

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // LAB2_3_H
