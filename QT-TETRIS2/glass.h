#ifndef GLASS_H
#define GLASS_H
#define emptyCell QColor(130,114,168)

#include <QWidget>
#include <QVector>
#include "figure.h"
#include <QPainter>
#include <QPoint>
#include <qDebug>

static const uint W = 20;

class Glass : public QWidget
{
    Q_OBJECT
    QVector<QVector<QColor>> glassArray;
    uint m_rows = 20;
    uint m_columns = 11;
    bool gameOn = false;
    uint idTimer;
    QSize s;
    Figure* current;
    Figure* next;
    uint score=0;
    friend class Figure;
public:
    explicit Glass(QWidget *parent = nullptr);
    void recolorGlass();
    void spaceFigure();

signals:

public slots:
    void gameStart();

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // GLASS_H
