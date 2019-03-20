#ifndef GRAPHICREDACTOR_H
#define GRAPHICREDACTOR_H

#include <QMainWindow>
#include "myscene.h"

namespace Ui {
class GraphicRedactor;
}

class GraphicRedactor : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphicRedactor(QWidget *parent = nullptr);
    ~GraphicRedactor();

private:
    Ui::GraphicRedactor *ui;
};

#endif // GRAPHICREDACTOR_H
