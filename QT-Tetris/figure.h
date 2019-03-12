#ifndef FIGURE_H
#define FIGURE_H

#include <QPair>
#include <QColor>
#include <QPainter>
#include <QVector>
#include <QTime>

class Figure
{
    QColor arr[3];//figure
    const QColor e_col[4] = {QColor(101,89,139),QColor(223,136,165),QColor(253,206,185)};
    //QVector<QColor> v_col[3];//figure
    uint m_i, m_j;// X and Y coordinates, where is the figure placed
    uint m_W;//size of cell(клетка)
public:
    explicit Figure(QWidget *parent = nullptr);
//1.	Конструктор
//2.	Методы изменения индексов верхней клетки фигуры
    void figureMove(uint n_i, uint n_j);
//3.	Методы получения индексов верхней/нижней клеток
    QPoint getIndex();
//4.	Циклическое перемещение цветов –вниз/вверх, например:
//voidrotateColors(<признак – вверх/вниз>)
    void rotateColors(bool);
//5.	Формирование случайным образом цветов, например void MakeRandomColors();
    void MakeRandomColors();
//6.	Отрисовкафигуры, например: void paintFigure(QPainter&painter);
    void paintFigure(QPainter&painter);
//7.	Метод получения цветов;
    QColor getCol(int);



public:
    Figure(uint);
};

#endif // FIGURE_H
