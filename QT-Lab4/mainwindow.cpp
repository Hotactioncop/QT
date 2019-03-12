#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypicture.h"
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStatusBar(int index)
{
    QString str("Picture scale equal ");
    str+= QString().setNum(index);
    str+="/";
    str+= QString().setNum(100);
    ui->statusBar->showMessage(str, 0);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::aboutQt(this,"Have you read this?");
}
