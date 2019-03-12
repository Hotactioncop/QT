#ifndef GLASS_H
#define GLASS_H

#define emptyCell QColor(122,158,175)

#include <QWidget>
#include "figure.h"
#include <QVector>
#include <QPair>
#include <QSet>
static const uint W=20;

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ rows WRITE setColumns)
    bool gameOn = false;
    uint score = 0;
    uint m_rows = 20;
    uint m_columns = 11;
    QSize s;
    uint timerInterval;
    Figure *cur; //current falling figure
    Figure *next; //next figure, shows on Frame
    int idTimer;
    int countOn;//Count for start visual effects(3 - 2 - 1)
    bool pressSpace = false;//if true - allow to use space button. Turn off, when the figure stops, and turns on when new figure appears
    uint easyTime = 1000, normTime = 300;//easyTime for start visual effects, normalTime for usual figure moving effects
    bool spreadGlass = false;// use for spreading glass, after clearing the matched cells
    bool matchCells = false;//use to seeparate between moves: clear matched cells, or spreading glass
    bool PausePressed = false;

    QVector<QVector<QColor>>glassArray;

public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();

    uint rows() const
    {
        return m_rows;
    }
    void clearGlass();


public slots:
    void setRows(uint rows)
    {
       m_rows = rows;
    }
    void setColumns(uint columns)
    {
        m_columns = columns;
    }
    void slotGlassInit();
    void slotNewGame();
    void pauseGame();
    void stopGame();

signals:
    void signalGlassInit();
    void setScore(int);
    void changePauseButton();
    void sendNextFigure(Figure*);
    void stopNextFigure(bool*);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);
    void AcceptColors(int i, int j);//добавляем фигуру в стакан
    void CheckGlass();

    // QWidget interface
protected:
    void pushSpaceMoveFast();
};

#endif // GLASS_H
