#ifndef TETRIS_H
#define TETRIS_H

#include <QMainWindow>
#include <QTime>
namespace Ui {
class Tetris;
}

class Tetris : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tetris(QWidget *parent = nullptr);
    ~Tetris();

private:
    Ui::Tetris *ui;
public slots:
    void changeButtonPause();
};

#endif // TETRIS_H
