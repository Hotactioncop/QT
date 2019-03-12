#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <mainwindow.h>
#include <QWidget>
#include <QPixmap>

class MyPicture : public QWidget
{
    Q_OBJECT
    QPixmap pixmap;
    double scale;
    int _style;
public:
    explicit MyPicture(QWidget *parent = nullptr);


signals:

public slots:
    void scaleChanged(int);
    void chooseStyleFirst();
    void chooseStyleSecond();
    void chooseStyleThird();
    void openFile();


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);

};

#endif // MYPICTURE_H
