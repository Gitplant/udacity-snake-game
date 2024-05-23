#include "player.h"
#include "snake.h"

#include <iostream>
#include <thread>
#include <mutex>

std::vector<Color> const player_colors = {Color{0x00, 0x7A, 0xCC, 0xFF}, Color{0x7F, 0x00, 0x7F, 0xFF}};

Player::Player(int&& player_id, int grid_width, int grid_height, float head_x)
    : _player_id(std::move(player_id)),
    // _controller(controller),
    snake(std::make_unique<Snake>(Snake(grid_width, grid_height, head_x, player_colors[player_id-1]))),
      _score(0) {
}
void Player::IncreaseScore(){
    std::mutex _mutex;
    std::lock_guard<std::mutex> lck(_mutex);
    _score++;
}

// temp
// Player::Player(const Player& other) : _player_id(other._player_id), _score(other._score), snake(other.snake){
//     std::cout << "  -------------------------   Player copy constructor called." << std::endl;
//     }