#ifndef SPACE_H
#define SPACE_H
#define emptyCell QColor(47,60,78)

#include <QWidget>
#include <QList>
#include <QVector>
#include <QColor>
#include "snake.h"

static const uint W=20;
//enum direction{up,down,left,right};

class Space : public QWidget
{
    Q_OBJECT
    QVector<QVector<QColor>> glass;
    uint m_rows = 15;
    uint m_columns = 22;
    QList<QPoint> snake;
    bool gameOn = false;
    uint idTimer;
    Snake* omnomnom;
    QSize s;
    enum direction{up,down,left,right} direct = right;
    QPoint apple;
    QList<QPoint> appleArea;
    int score = 0;
    bool pause = false;
    friend class Snake;

    void setApple();

public slots:
    void slotGlassInit();
    void startGame();
    void pauseGame();
    void stopGame();

signals:
    void signalGlassInit();
    void changePause();
    void setScore(int);

public:
    explicit Space(QWidget *parent = nullptr);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // SPACE_H
