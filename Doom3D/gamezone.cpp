#include "gamezone.h"

GameZone::GameZone(QWidget *parent) : QWidget(parent)
{
    s.setWidth(1024);
    s.setHeight(512);
    setFixedSize(s);
    framebuffer.resize(win_w*win_h);
    framebuffer.fill(QColor(230, 230, 250));
    play = new Player;

}

void GameZone::StartGame()
{
    idTimer = startTimer(1000/60);
    gameOn = true;
    this->setFocus();
}

void GameZone::timerEvent(QTimerEvent *event)
{
    if(gameOn){
        for (size_t i = 0; i < win_w/2; i++) { // draw the visibility cone AND the "3D" view
            float angle = play->player_a - play->fov/ 2 + play->fov *i/ float(win_w / 2);
            for (float t = 0; t < 20; t += 0.05) {
                float cx = play->player_x + t * cos(angle);
                float cy = play->player_y + t * sin(angle);


                size_t pix_x = cx * rect_w;
                size_t pix_y = cy * rect_h;
//                qDebug() << pix_x << " " << pix_y << " " << pix_x + pix_y * win_w;
                framebuffer[pix_y + pix_x * win_w] = QColor(160, 160, 160);
                if (map[int(cx) + int(cy)*map_w] != ' '){
                    size_t column_height = win_h / t;
                    game.push_back(std::make_pair(QPoint(win_w/2+i,win_h/2-column_height/2),QPoint(win_w/2+i,win_h/2+column_height/2)));
                    break;
                }
            }
        }
    }
    repaint();
}

void GameZone::paintEvent(QPaintEvent *event)
{
    if(gameOn){
        QPainter pan(this);
        for(int i = 0; i < framebuffer.size()-1;i++){

            pan.fillRect(i/win_w,i%win_w-1,1,1, framebuffer[i]);
        }
        for (size_t j = 0; j < map_h; j++) { // draw the map
            for (size_t i = 0; i < map_w; i++) {
                if (map[i + j * map_w] == ' ') continue; // skip empty spaces
                rect_x = i * rect_w;
                rect_y = j * rect_h;
                pan.fillRect(i * rect_w,j * rect_h, rect_w, rect_h, QColor(0, 255, 255));
            }
        }
        QPainter pan2(this);
        pan2.setPen(Qt::darkCyan);
        for(auto&X:game){
            pan2.drawLine(X.first, X.second);
        }
    }
}


void GameZone::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W){
        play->move(0);
        game.clear();
    }
    else if(event->key()==Qt::Key_S){
        play->move(1);
        game.clear();
    }
    if(event->key()==Qt::Key_A){
        play->move(2);
        game.clear();
    }
    else if(event->key()==Qt::Key_D){
        play->move(3);
        game.clear();
    }
    repaint();

}
