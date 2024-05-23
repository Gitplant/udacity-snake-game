#include "player.h"
#include "snake.h"

#include <iostream>

std::vector<Color> const player_colors = {Color{0x00, 0x7A, 0xCC, 0xFF}, Color{0x7F, 0x00, 0x7F, 0xFF}};

Player::Player(int&& player_id, int grid_width, int grid_height, float head_x, std::shared_ptr<Controller> controller)
    : _player_id(player_id),
    // _controller(controller),
    snake(Snake(grid_width, grid_height, head_x, player_colors[player_id-1])),
    _controller(controller),
      _score(0) {
}
void Player::IncreaseScore(){
    _score++;
}