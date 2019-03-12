#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
#include <iostream>
#include <mypicture.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public slots:
    void setStatusBar(int);
    void slotToInt(QString str)
    {
        int i = str.toInt();
        emit mySignal(i);
    }

signals:
    void mySignal(int);
private slots:
    void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
