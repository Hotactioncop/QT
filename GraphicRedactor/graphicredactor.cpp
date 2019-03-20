#include "graphicredactor.h"
#include "ui_graphicredactor.h"

GraphicRedactor::GraphicRedactor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicRedactor)
{
    ui->setupUi(this);
    MyScene* scene=new MyScene();
    ui->graphicsView->setScene(scene);

}

GraphicRedactor::~GraphicRedactor()
{
    delete ui;
}
