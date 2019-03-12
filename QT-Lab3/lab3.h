#ifndef LAB3_H
#define LAB3_H

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>

class Lab3 : public QWidget
{
    Q_OBJECT
    QFrame *fram;
    QVBoxLayout* rvbox;
    QHBoxLayout* hbox;
    QVBoxLayout* lvbox;
    QGridLayout* gbox;
    QHBoxLayout* main;
    QPushButton *buttonExit, *buttonEnable, *buttonStyle;
    QLabel *labl;
    QLineEdit *ledit;
    QSlider *slidr;
    QSpinBox *spnbox;
    QComboBox *qbox;
    int _style = 0;
    // QWidget interface
protected:
    void rightVerticalLayout();
    void leftVerticalLayout();
    void HorizontalLayout();
    void GridLayout();
//    void ComboLayout();


public:
    Lab3(QWidget *parent = 0);
    ~Lab3();
public slots:
    void slotToInt(QString str);
    void slotChangeLayout(int index);
    void makeDisable();
    void makeStyle();
 signals:
    void mySignal(int);
};

#endif // LAB3_H
