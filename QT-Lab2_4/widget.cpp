#include "widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QEvent>
#include <QKeyEvent>
#include <qDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Вас устраивает ваша зарплата?");
    QRect rec;
    rec = this->rect();
    rec.setSize(QSize(960,540));
    setGeometry(480,270,960,540);
    buttonYes= new QPushButton(QObject::tr("Да"), this);
    buttonNo= new QPushButton(QObject::tr("Нет"), this);
    buttonYes->setGeometry(415,250,60,40);
    QRect recNo = buttonNo->rect();
    buttonNo->setGeometry(485,250,60,40);
    QObject::connect(buttonYes,SIGNAL(clicked()),this, SLOT(weKnowIt()));
    buttonNo->installEventFilter(this);
    buttonNo->setFocusPolicy(Qt::NoFocus);

    //press ALT and use mouse to click the buttonNo
    QObject::connect(buttonNo,SIGNAL(clicked()),this, SLOT(howDidYouKnowIt()));

    setMouseTracking(true);
}

Widget::~Widget()
{

}

void Widget::weKnowIt()
{
    QMessageBox::information(this,"Message", "Мы так и думали!");
}
void Widget::howDidYouKnowIt()
{
    QMessageBox::information(this,"Message", "Навык чтения кода +35");
}



bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==buttonNo)
    {
        if(pressBut == true && event->type() == QEvent::HoverMove)
        {
            return true;
        }
        else if(event->type() == QEvent::HoverMove)
        {
            buttonNo->move(rand()%900,rand()%500);
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Alt)
    {
        pressBut=true;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    pressBut = false;
}
