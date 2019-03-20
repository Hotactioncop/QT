#include "gamezone.h"

GameZone::GameZone(QWidget *parent) : QWidget(parent)
{
    s.setWidth(1024);
    s.setHeight(512);
    setFixedSize(s);
    framebuffer.resize(win_w*win_h);
    framebuffer.fill(QColor(230, 230, 250));
    for (size_t j = 0; j < map_h; j++) { // draw the map
        for (size_t i = 0; i < map_w; i++) {
            if (map[i + j * map_w] == ' ') continue; // skip empty spaces
            rect_x = i * rect_w;
            rect_y = j * rect_h;
            for(int x = rect_y; x<rect_y+32; x++){
                for (int y = rect_x;y<rect_x+32;y++){
                    framebuffer[x+y*win_w]=color[map[i+j*map_h]-'0'].second;
                }
            }
        }
    }
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
            play->angle = play->player_a - play->fov/ 2 + play->fov *i/ float(win_w / 2);
            for (float t = 0; t < 20; t += 0.01) {
                float cx = play->player_x + t * cos(play->angle);
                float cy = play->player_y + t * sin(play->angle);


                size_t pix_x = cx * rect_w;
                size_t pix_y = cy * rect_h;
                my_ray.push_back(QPoint(pix_x,pix_y));
                if (map[int(cx) + int(cy)*map_w] != ' '){
                    size_t column_height = win_h/(t*cos(play->angle-play->player_a));
                    game.push_back(std::make_pair(std::make_pair(QPoint(win_w/2+i,win_h/2-column_height/2),QPoint(win_w/2+i,win_h/2+column_height/2)),color[map[int(cx) + int(cy)*map_w]-'0'].second));

                    break;
                }
            }
        }
        this->show();
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
        pan.setPen(Qt::lightGray);
        for(auto&X:my_ray){
            pan.drawPoint(X);
        }
        QPainter pan2(this);
        for(auto&X:game){
            pan2.setPen(QColor(X.second));
            pan2.drawLine(X.first.first, X.first.second);
        }
    }
}


void GameZone::keyPressEvent(QKeyEvent *event)
{
    this->hide();
    if(event->key()==Qt::Key_W){
        play->move(0);
    }
    else if(event->key()==Qt::Key_S){
        play->move(1);
    }
    if(event->key()==Qt::Key_A){
        play->move(2);
    }
    else if(event->key()==Qt::Key_D){
        play->move(3);
    }
    game.clear();
    my_ray.clear();
    repaint();

}
