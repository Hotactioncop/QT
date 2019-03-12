#ifndef GLASS_H
#define GLASS_H
#define emptyCell QColor(150,150,150)

#include <QWidget>

class Glass : public QWidget
{
    Q_OBJECT
    static const uint W=20;
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ rows WRITE setColumns)
    bool gameOn;
    uint score;
    uint m_rows = 20;
    uint m_columns = 8;
    QSize s;
    uint timerInterval;

    QVector<QVector<QColor>>glassArray;

public:
    explicit Glass(QWidget *parent = nullptr);

    uint rows() const
    {
        return m_rows;
    }
    void clearGlass();


public slots:
    void setRows(uint rows)
    {
       m_rows = rows;
    }
    void setColumns(uint columns)
    {
        m_columns = columns;
    }
    void slotGlassInit();
signals:
    void signalGlassInit();


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // GLASS_H
