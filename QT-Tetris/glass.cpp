#include "glass.h"
#include <QPainter>
#include <qDebug>
#include <QKeyEvent>
#include <QMessageBox>

Glass::Glass(QWidget *parent) : QWidget(parent)
{

    QObject::connect(this,SIGNAL(signalGlassInit()), this, SLOT(slotGlassInit()),Qt::QueuedConnection);
    emit signalGlassInit();
    cur = new Figure(W-1);
    next = new Figure(W-1);
}

Glass::~Glass()
{
    delete cur;
    delete next;
}

void Glass::clearGlass()
{
    qDebug() << "clearGlass";

    for(auto&x:glassArray)
    {
        x.fill(emptyCell);
    }

}

void Glass::slotGlassInit()
{
    qDebug() << "slotGlassInit";

    glassArray.resize(m_rows);
    for(auto&x:glassArray)
    {
        x.resize(m_columns);
        x.fill(emptyCell);
    }
    s.setWidth(W*m_columns);
    s.setHeight(W*m_rows);
    setFixedSize(s);
}

void Glass::slotNewGame()
{
    qDebug() << "slotNewGame";

    if(gameOn){
        killTimer(idTimer);
        gameOn = false;
    }
    score = 0;
    emit setScore(score);
    //Clearing the glass
    clearGlass();
    cur->figureMove((s.width()-W)/2,0);
    cur->MakeRandomColors();
    next->MakeRandomColors();
    emit sendNextFigure(next);
    this->setFocus();
    idTimer = startTimer(normTime);
    gameOn = true;
    //countOn=4;//счетчик времени до старта
    //    idTimer = startTimer(300);
}

void Glass::pauseGame()
{
    if(gameOn){
        if(!PausePressed){
            killTimer(idTimer);
            PausePressed=true;
        }
        else {
            idTimer = startTimer(normTime);
            this->setFocus();
            PausePressed=false;
        }
        emit changePauseButton();
    }
}

void Glass::stopGame()
{
    if(gameOn){
        if(PausePressed){
            PausePressed=false;
            emit changePauseButton();
        }
        else {
            killTimer(idTimer);
        }
    }
    gameOn = false;
    clearGlass();
    emit stopNextFigure(&gameOn);
    score = 0;
    emit setScore(score);
    repaint();
}


void Glass::paintEvent(QPaintEvent *event)
{
    QPainter pain(this);
    qDebug() << "paintGLASSARRAY";

    for (uint i = 0; i < m_columns; i++)
    {
        for (uint j = 0; j<m_rows; j++)
        {
            pain.fillRect(i*W,j*W,W-1,W-1,glassArray[j][i]);
        }
    }
    if(gameOn){
        if(glassArray[2][cur->getIndex().x()/W]!=emptyCell)
        {
            qDebug() << "paintEvent NO OK";

            if(glassArray[1][cur->getIndex().x()/W]!=emptyCell)
            {
                if(glassArray[0][cur->getIndex().x()/W]!=emptyCell){}
                else {
                    glassArray[0][cur->getIndex().x()/W] = cur->getCol(2);
                }
            }
            else{
                glassArray[0][cur->getIndex().x()/W] = cur->getCol(1);
                glassArray[1][cur->getIndex().x()/W] = cur->getCol(2);
            }
        }
        else{
            qDebug() << "paintEvent OK";

            pain.fillRect(cur->getIndex().x(),cur->getIndex().y(),W-1,W-1,cur->getCol(0));
            pain.fillRect(cur->getIndex().x(),cur->getIndex().y()+20,W-1,W-1,cur->getCol(1));
            pain.fillRect(cur->getIndex().x(),cur->getIndex().y()+40,W-1,W-1,cur->getCol(2));
        }
    }
}


void Glass::keyPressEvent(QKeyEvent *event)
{
    if(gameOn)
    {
        switch(event->key()){//код нажатой клавиши
        case Qt::Key_Left: //если есть «куда», перемещаем фигурку влево
            if(cur->getIndex().x()>0)
            {
                if(glassArray[cur->getIndex().y()/W+2][cur->getIndex().x()/W-1]==emptyCell)
                {
                    cur->figureMove(cur->getIndex().x()-W, cur->getIndex().y());
                    repaint();
                }
            }
        break;
        case Qt::Key_Right:
            if(cur->getIndex().x()<s.width()-W)
            {
                if(glassArray[cur->getIndex().y()/W+2][cur->getIndex().x()/W+1]==emptyCell)
                {
                    cur->figureMove(cur->getIndex().x()+W, cur->getIndex().y());
                    repaint();
                }
            }
        break;
        case Qt::Key_Down:
        //циклически ”переливаем” цвета в фигурке сверху вниз
            cur->rotateColors(0);
        break;
        case Qt::Key_Up:
        //циклически ”переливаем” цвета в фигурке снизу вверх
            cur->rotateColors(1);
        break;
        case Qt::Key_Space:
        //«роняем» фигурку
            if(pressSpace){
                pushSpaceMoveFast();
            }
        break;
        default:
        QWidget::keyPressEvent(event); //при нажатии любых других клавиш вызываем базовую обработку события
        }
    }
}


void Glass::timerEvent(QTimerEvent *event)
{
    qDebug() << "timerEvent";

    if(gameOn)
    {
        if(cur->getIndex().y()<s.height()-60 && glassArray[cur->getIndex().y()/W+3][cur->getIndex().x()/W]==emptyCell)
        {
            cur->figureMove(cur->getIndex().x(), cur->getIndex().y()+W);
            repaint();
            pressSpace = true;
        }
        else if(glassArray[2][cur->getIndex().x()/W]!=emptyCell){
            qDebug() << "killTimer, gameOn = false";
            killTimer(idTimer);
            gameOn = false;
            QMessageBox::information(this,"Message", "GAME OVER");
        }
        else {
            AcceptColors(cur->getIndex().y()/W, cur->getIndex().x()/W);
            repaint();
            pressSpace = false;
        }
    }
    if(spreadGlass){
        if(countOn==2){
            repaint();
        }
        else {
            for(uint i = 0; i < m_columns; i++){
                for(uint j = m_rows-1;j>0; j--){
                    for(uint k = m_rows-1;k>1; k--){
                        if(glassArray[k][i]==emptyCell && glassArray[k-1][i]!=emptyCell){
                            std::swap(glassArray[k][i], glassArray[k-1][i]);
                        }
                    }
                }
            }
            repaint();
            emit setScore(score);
        }
        --countOn;
        if(countOn==0){
            CheckGlass();
        }
    }
}

void Glass::AcceptColors(int i, int j)
{
    qDebug() << "AcceptColors";

    glassArray[i][j]=cur->getCol(0);
    glassArray[i+1][j]=cur->getCol(1);
    glassArray[i+2][j]=cur->getCol(2);
    std::swap(cur,next);
    cur->figureMove((s.width()-W)/2,0);
    next->MakeRandomColors();
    emit sendNextFigure(next);
    CheckGlass();
}

void Glass::CheckGlass()
{
    qDebug() << "CheckGlass";

    gameOn = false;
    spreadGlass = true;
    bool match = false;
    QSet<QPair<uint,uint>> matchFind;
    for(uint i = 0; i<m_rows; i++)
    {
        for(uint j = 1; j<m_columns-1; j++)
        {
            if (glassArray[i][j] == glassArray[i][j-1] && glassArray[i][j]!=emptyCell)
            {
                if(glassArray[i][j] == glassArray[i][j+1]){
                    if(!match){
                        matchFind.insert(qMakePair(i,j-1));
                        matchFind.insert(qMakePair(i,j));
                        matchFind.insert(qMakePair(i,j+1));
                        match = true;
                    }
                    else{
                        matchFind.insert((qMakePair(i,j+1)));
                    }
                }
                else {
                    match = false;
                }
            }
        }
    }
    match = false;
    for(uint i = 0; i<m_columns; i++)
    {
        for(uint j = 1; j<m_rows-1; j++)
        {
            if (glassArray[j][i] == glassArray[j-1][i] && glassArray[j][i]!=emptyCell)
            {
                if(glassArray[j][i] == glassArray[j+1][i]){
                    if(!match){
                        matchFind.insert(qMakePair(j-1,i));
                        matchFind.insert(qMakePair(j,i));
                        matchFind.insert(qMakePair(j+1,i));
                        match = true;
                    }
                    else{
                        matchFind.insert((qMakePair(j+1,i)));
                    }
                }
                else {
                    match = false;
                }
            }
        }
    }
    for (auto&x:matchFind){
        glassArray[x.first][x.second] = emptyCell;
    }
    score += matchFind.size()*10;
    if(!matchFind.size())
    {
        gameOn = true;
        spreadGlass = false;
        matchCells=false;
    }
    else {
        countOn=2;
    }
    matchFind.clear();
}

void Glass::pushSpaceMoveFast()
{
    if(gameOn)
    {
        if(cur->getIndex().y()<s.height()-60 && glassArray[cur->getIndex().y()/W+3][cur->getIndex().x()/W]==emptyCell)
        {
            cur->figureMove(cur->getIndex().x(), cur->getIndex().y()+W);
            repaint();
        }
        else if(glassArray[2][cur->getIndex().x()/W]!=emptyCell)
                {
                    QPainter pain(this);
                    if(glassArray[1][cur->getIndex().x()/W]!=emptyCell)
                    {
                        if(glassArray[0][cur->getIndex().x()/W]!=emptyCell)
                        {
                            killTimer(idTimer);
                            gameOn = false;
                            QMessageBox::information(this,"Message", "GAME OVER");
                        }
                        else {
                            killTimer(idTimer);
                            gameOn = false;
                            pain.fillRect(cur->getIndex().x(),0,W-1,W-1,cur->getCol(2));
                            glassArray[0][cur->getIndex().x()/W]=cur->getCol(2);
                            QMessageBox::information(this,"Message", "GAME OVER");
                        }
                    }
                    else{
                        killTimer(idTimer);
                        gameOn = false;
                        pain.fillRect(cur->getIndex().x(),1,W-1,W-1,cur->getCol(2));
                        pain.fillRect(cur->getIndex().x(),0,W-1,W-1,cur->getCol(1));
                        glassArray[1][cur->getIndex().x()/W]=cur->getCol(2);
                        glassArray[0][cur->getIndex().x()/W]=cur->getCol(1);
                        QMessageBox::information(this,"Message", "GAME OVER");
                    }
                }
        else {
            AcceptColors(cur->getIndex().y()/W, cur->getIndex().x()/W);
            repaint();
             pressSpace = false;
        }
    }

}
