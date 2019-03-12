#include "lab3.h"

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QFrame>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QIntValidator>
#include <string>
#include <iostream>
#include <QComboBox>
#include <QDebug>
#include <QGridLayout>
#include <QStyleFactory>
#include <QApplication>

Lab3::Lab3(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags flags;
    flags|=Qt::CustomizeWindowHint;
    flags|=Qt::WindowTitleHint;
    setWindowFlags(flags);

    buttonExit = new QPushButton(QObject::tr("Exit"), this);
    buttonEnable = new QPushButton(QObject::tr("Disable"), this);
    buttonStyle = new QPushButton(QObject::tr("Windows style"), this);

    QObject::connect(buttonExit,SIGNAL(clicked()),this, SLOT(close()));

    fram = new QFrame(this);

    labl = new QLabel("10",this);
    labl->setFixedSize(labl->sizeHint());
    labl->setFrameStyle(7);

    ledit = new QLineEdit(this);
    ledit->setFixedSize(ledit->sizeHint());
    ledit->setMaxLength(2);

    QIntValidator *ival = new QIntValidator(this);
    ival->setRange(0,99);
    ledit->setValidator(ival);

    slidr = new QSlider(Qt::Horizontal,this);
    slidr->setTickInterval(1);
    slidr->setRange(0,99);
    slidr->setSingleStep(1);
    slidr->setMinimumWidth(300);

    spnbox = new QSpinBox(this);
    spnbox->setMinimum(0);
    spnbox->setMaximum(99);
    spnbox->setFixedSize(spnbox->sizeHint());

    //sinchonizing widgets
    QObject::connect(slidr,SIGNAL(valueChanged(int)),spnbox,SLOT(setValue(int)));
    QObject::connect(spnbox,SIGNAL(valueChanged(int)),slidr,SLOT(setValue(int)));
    QObject::connect(spnbox,SIGNAL(valueChanged(QString)),ledit,SLOT(setText(QString)));
    QObject::connect(ledit,SIGNAL(textChanged (QString)),labl,SLOT(setText(QString)));
    QObject::connect(ledit,SIGNAL(textChanged (QString)),this,SLOT(slotToInt(QString)));
    QObject::connect(this,SIGNAL(mySignal(int)), spnbox,SLOT(setValue(int)));
    spnbox->setValue(10);

    qbox = new QComboBox();
    qbox->addItem("Vertical layout");
    qbox->addItem("Horizontal layout");
    qbox->addItem("Column layout");

    //call for methods to create layouts
    rightVerticalLayout();
    leftVerticalLayout();
    fram->setLayout(lvbox);

    //creating parent layout
    main = new QHBoxLayout(this);//without parent
    main->setObjectName("Main");
    main->addWidget(fram);
    main->addLayout(rvbox);

    //connecting bottons with actions
    QObject::connect(qbox,SIGNAL(activated(int)), this, SLOT(slotChangeLayout(int)));
    QObject::connect(buttonEnable,SIGNAL(clicked()), this, SLOT(makeDisable()));
    QObject::connect(buttonStyle,SIGNAL(clicked()), this, SLOT(makeStyle()));

    this->dumpObjectTree();
}

Lab3::~Lab3()
{

}

void Lab3::slotToInt(QString str)
{
    //connecting lineEdit and spinbox. lineEdit works with string, Spinbox with int
    int i = str.toInt();
    emit mySignal(i);
}

void Lab3::makeDisable()
{
    //making frame disabled or enabled
    if(fram->isEnabled()){
        fram->setDisabled(true);
        buttonEnable->setText("Enable");
    }
    else{
        fram->setEnabled(true);
        buttonEnable->setText("Disable");
    }
}

void Lab3::makeStyle()
{
    //setting application style according to queue(Windows, Fusion or Vista style)
    qDebug()<<QStyleFactory::keys();
    if(_style==0){
             QApplication::setStyle(QStyleFactory::create("Windows"));
             buttonStyle->setText("Fusion style");
             _style=1;
    }
    else if(_style==1){
        QApplication::setStyle(QStyleFactory::create("Fusion"));
        buttonStyle->setText("Vista style");
        _style=2;
    }
    else{
        QApplication::setStyle(QStyleFactory::create("windowsvista"));
        buttonStyle->setText("Windows style");
        _style=0;
    }
}

void Lab3::slotChangeLayout(int index)
{
    /*Changing the layout by the combobox;
     * choosing, which one is active now and deleting;
     * by the index getting the number of needed layout, creating it by method and setting into frame*/
    this->hide();
    if(fram->layout()==lvbox){
        delete lvbox;
    }
    else if(fram->layout()==hbox){
        delete hbox;
    }
    else if(fram->layout()==gbox){
        delete gbox;
    }
    if(index==0){
        leftVerticalLayout();
        fram->setLayout(lvbox);
    }
    else if(index==1){
        HorizontalLayout();
        fram->setLayout(hbox);
    }
    else if(index==2){
        GridLayout();
        fram->setLayout(gbox);
    }
    this->show();
}

void Lab3::rightVerticalLayout(){
    //creating child vertical layout including widgets
    rvbox = new QVBoxLayout();
    rvbox->setObjectName("vert but");
    rvbox->addWidget(qbox);
    rvbox->addWidget(buttonExit);
    rvbox->addWidget(buttonEnable);
    rvbox->addWidget(buttonStyle);
}
void Lab3::leftVerticalLayout(){
    //creating child vertical layout including widgets
    lvbox = new QVBoxLayout();
    lvbox->setObjectName("vert");
    lvbox->addWidget(spnbox);
    lvbox->addWidget(slidr);
    lvbox->addWidget(ledit);
    lvbox->addWidget(labl);
}
void Lab3::HorizontalLayout(){
    //creating child horizontal layout including widgets
    hbox = new QHBoxLayout();
    hbox->setObjectName("hor");
    hbox->addWidget(spnbox);
    hbox->addWidget(slidr);
    hbox->addWidget(ledit);
    hbox->addWidget(labl);
}
void Lab3::GridLayout(){
    //creating child grid layout including widgets
    gbox = new QGridLayout();
    gbox->setObjectName("grid");
    gbox->addWidget(spnbox,1,1);
    gbox->addWidget(slidr,1,2);
    gbox->addWidget(ledit,2,1);
    gbox->addWidget(labl,2,2);
}
