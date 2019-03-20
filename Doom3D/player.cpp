#include "player.h"

Player::Player()
{
    float player_x = 3.456; // player x position
    float player_y = 2.345; // player y position
    float player_a = 1.523; // player view direction (in radians equal 90 gradus)
    float angle = player_a - fov / 2;
}

void Player::move(uint direction)
{
    switch (direction){
    case 0:
        player_x += cos(player_a);
        player_y += sin(player_a);
        break;
    case 1:
        player_x -= cos(player_a);
        player_y -= sin(player_a);
        break;
    case 2:
        player_a -= 0.1;
        break;
    case 3:
        player_a += 0.1;
        break;
    }
}
