#include <iostream>
#include <mutex>
#include <thread>

#include "player.h"
#include "snake.h"

std::vector<Color> const player_colors = {Color{0x00, 0x7A, 0xCC, 0xFF}, Color{0x7F, 0x00, 0x7F, 0xFF}};

Player::Player(int&& player_id, int grid_width, int grid_height, float head_x)
: _player_id(std::move(player_id)),
snake(std::make_unique<Snake>(grid_width, grid_height, head_x, player_colors[_player_id])),
_score(0) {}

void Player::IncreaseScore(){
    std::mutex _mutex;
    std::lock_guard<std::mutex> lck(_mutex);
    _score++;
}

/* Rule of five */

// Destructor
Player::~Player() {};

// Move constructor
Player::Player(Player&& other) noexcept : _player_id(std::move(other._player_id)), _score(std::move(other._score)){
    snake = std::move(other.snake);
}

// Move assignment operator
Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) {
        snake = std::move(other.snake);
        _score = std::move(other._score);
    }
    return *this;
}

// Check if any object of Player is occupying the cell
bool Player::CellIsOccupied(int x, int y) const {
    return snake->SnakeCell(x, y);
}