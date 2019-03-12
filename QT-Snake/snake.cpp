#include "snake.h"
#include <qDebug>
Snake::Snake()
{
    first = &my_snake.front();
    last = &my_snake.last();
}

void Snake::moveSnake(uint x, uint y, bool eat)
{
    my_snake.push_front(QPoint(x,y));
    first = &my_snake.front();
    if (!eat){
        my_snake.pop_back();
    }
    last = &my_snake.last();
}

void Snake::restartSnake()
{
    my_snake.clear();
    my_snake.push_back(QPoint(60,140));
    my_snake.push_back(QPoint(40,140));
    my_snake.push_back(QPoint(20,140));
    my_snake.push_back(QPoint(0,140));
    first = &my_snake.front();
    last = &my_snake.last();
}
