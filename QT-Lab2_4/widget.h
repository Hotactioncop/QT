#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT
    QPushButton *buttonYes;
    QPushButton *buttonNo;
    bool pressBut = false;
public slots:
    void weKnowIt();
    void howDidYouKnowIt();

public:
    Widget(QWidget *parent = 0);
    ~Widget();


    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event);

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
};

#endif // WIDGET_H
