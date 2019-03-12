#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"
#include "glass.h"

class NextFigure : public QWidget
{
    Q_OBJECT
    QSize s;
    Figure*next;
    bool gameOn = false;
public:
    explicit NextFigure(QWidget *parent = nullptr);

signals:

public slots:
    void getNextFigure(Figure *);
    void stopGame(bool*);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
    ~NextFigure();
};

#endif // NEXTFIGURE_H
