#include "space.h"
#include <QPainter>
#include <QColor>
#include <QKeyEvent>
#include <qDebug>
#include <QMessageBox>
#include <QList>
#include <iterator>

Space::Space(QWidget *parent) : QWidget(parent)
{
    qDebug() << "Space";

    QObject::connect(this,SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()),Qt::QueuedConnection);
    emit signalGlassInit();
    omnomnom = new Snake();
    for(uint i = 0; i < m_rows;i++){
        for(uint j = 0; j < m_columns; j++){
            appleArea.push_back(QPoint(j*W,i*W));
        }
    }
}



void Space::slotGlassInit()
{
    qDebug() << "slotGlassInit";

    glass.resize(m_rows);
    for(auto&x:glass){
        x.resize(m_columns);
        x.fill(emptyCell);
    }
    s.setWidth(W*m_columns);
    s.setHeight(W*m_rows);
    setFixedSize(s);
}

void Space::startGame()
{
    qDebug() << "startGame";

    if(gameOn){
        if(pause==true){
            pause = false;
            emit changePause();
        }
        else{
           killTimer(idTimer);
        }
        omnomnom->restartSnake();
    }
    gameOn = true;
    idTimer = startTimer(200);
    setApple();
    this->setFocus();
    direct = right;
    score = 0;
    emit setScore(score);
}

void Space::pauseGame()
{
    if(gameOn){
        if(pause==false){
            killTimer(idTimer);
            pause = true;
        }
        else{
            idTimer = startTimer(200);
            pause = false;
            this->setFocus();
        }
        emit changePause();
    }
}

void Space::stopGame()
{
    if(gameOn){
        if(pause==true){
            pause = false;
            emit changePause();

        }
        else {
            killTimer(idTimer);
        }
        gameOn = false;
        score = 0;
        emit setScore(score);
        omnomnom->restartSnake();
        repaint();
    }
}

void Space::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";

    QPainter p_pen(this);
    for(uint i = 0; i < m_rows;i++){
        for(uint j = 0; j < m_columns; j++){
            p_pen.fillRect(j*W, i*W, W,W, glass[i][j]);
        }
    }
    if(gameOn){
        p_pen.fillRect(apple.x(),apple.y(),W-1,W-1,QColor(68,145,56));
        for(auto&X:omnomnom->my_snake){
            p_pen.fillRect(X.x(), X.y(), W-1, W-1, QColor(223,111,60));
        }
    }
}

void Space::timerEvent(QTimerEvent *event)
{
    if(gameOn){
        for(auto x = omnomnom->my_snake.begin()+2; x!=omnomnom->my_snake.end(); x++){
            if (*omnomnom->first==*x){
                QMessageBox::information(this,"Message", "GAME OVER");
                gameOn = false;
                killTimer(idTimer);
                omnomnom->restartSnake();
                qDebug() << "А может тут";
                return;
            }
        }
        switch (direct){
        case right:
            if(omnomnom->first->x()==m_columns*W-W){
                if(*omnomnom->first==apple){
                    omnomnom->moveSnake(0,omnomnom->first->y(), true);
                    score+=10;
                    emit setScore(score);
                    setApple();
                }
                else{
                    omnomnom->moveSnake(0,omnomnom->first->y());
                }
            }
            else if(*omnomnom->first==apple){
                omnomnom->moveSnake(omnomnom->first->x()+W,omnomnom->first->y(), true);
                score+=10;
                emit setScore(score);
                setApple();
            }
            else{
                omnomnom->moveSnake(omnomnom->first->x()+W,omnomnom->first->y());
            }
            break;
        case left:
            if(omnomnom->first->x()==0){
                if(*omnomnom->first==apple){
                    omnomnom->moveSnake(m_columns*W-W,omnomnom->first->y(),true);
                    score+=10;
                    emit setScore(score);
                    setApple();
                }
                else{
                    omnomnom->moveSnake(m_columns*W-W,omnomnom->first->y());
                }
            }
            else if(*omnomnom->first==apple){
                omnomnom->moveSnake(omnomnom->first->x()-W,omnomnom->first->y(), true);
                score+=10;
                emit setScore(score);
                setApple();
            }
            else{
                omnomnom->moveSnake(omnomnom->first->x()-W,omnomnom->first->y());
            }
            break;
        case up:
            if(omnomnom->first->y()==0){
                if(*omnomnom->first==apple){
                    omnomnom->moveSnake(omnomnom->first->x(),m_rows*W-W,true);
                    score+=10;
                    emit setScore(score);
                    setApple();
                }
                else {
                    omnomnom->moveSnake(omnomnom->first->x(),m_rows*W-W);
                }
            }
            else if(*omnomnom->first==apple){
                omnomnom->moveSnake(omnomnom->first->x(),omnomnom->first->y()-W, true);
                score+=10;
                emit setScore(score);
                setApple();
            }
            else{
                omnomnom->moveSnake(omnomnom->first->x(),omnomnom->first->y()-W);
            }
            break;
        case down:
            if(omnomnom->first->y()==m_rows*W-W){
                if(*omnomnom->first==apple){
                    omnomnom->moveSnake(omnomnom->first->x(), 0, true);
                    score+=10;
                    emit setScore(score);
                    setApple();
                }
                omnomnom->moveSnake(omnomnom->first->x(), 0);
            }
            else if(*omnomnom->first==apple){
                omnomnom->moveSnake(omnomnom->first->x(),omnomnom->first->y()+W, true);
                score+=10;
                emit setScore(score);
                setApple();
            }
            else{
                omnomnom->moveSnake(omnomnom->first->x(),omnomnom->first->y()+W);
            }
            break;
        default:
            break;
        }
        repaint();
    }
}


void Space::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "keyPressEvent";

    if(gameOn)
    {
        switch (direct){
        case right:
            if(event->key() == Qt::Key_Up){direct = up;}
            else if(event->key() == Qt::Key_Down){direct = down;}
            break;
        case left:
            if(event->key() == Qt::Key_Up){direct = up;}
            else if(event->key() == Qt::Key_Down){direct = down;}
            break;
        case up:
            if(event->key() == Qt::Key_Left){direct = left;}
            else if(event->key() == Qt::Key_Right){direct = right;}
            break;
        case down:
            if(event->key() == Qt::Key_Left){direct = left;}
            else if(event->key() == Qt::Key_Right){direct = right;}
            break;
        default:
            break;
        }
    }
}

void Space::setApple()
{
    qDebug() << "setApple";

   QList<QPoint> actualArea = appleArea;
   qDebug() << actualArea.size();

   for(auto&x:omnomnom->my_snake){
       actualArea.removeAt(std::find(actualArea.begin(),actualArea.end(), x)-actualArea.begin());
   }
   qDebug() << actualArea.size();

   apple = actualArea.at(qrand()%actualArea.size());
}
