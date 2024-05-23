#include "player.h"
#include "snake.h"

#include <iostream>
#include <thread>
#include <mutex>

std::vector<Color> const player_colors = {Color{0x00, 0x7A, 0xCC, 0xFF}, Color{0x7F, 0x00, 0x7F, 0xFF}};

Player::Player(int&& player_id, int grid_width, int grid_height, float head_x)
    : _player_id(std::move(player_id)),
    // _controller(controller),
    // snake(std::make_unique<Snake>(Snake(grid_width, grid_height, head_x, player_colors[player_id-1]))),
    snake(std::make_unique<Snake>(grid_width, grid_height, head_x, player_colors[_player_id])),
      _score(0) {
}
void Player::IncreaseScore(){
    std::mutex _mutex;
    std::lock_guard<std::mutex> lck(_mutex);
    _score++;
}

/* Rule of five */

// Destructor
Player::~Player() {};

// // Copy constructor
// Player::Player(const Player& other) : _player_id(other._player_id), _score(other._score){
//     snake = std::make_unique<Snake>(*other.snake);
//     std::cout << "  -------------------------   Player copy constructor called." << std::endl;
// }

// Copy assignment operator
// Player& Player::operator=(const Player& other) {
//     std::cout << "  -------------------------   Player copy assignment operator called." << std::endl;
//     if (this != &other) {
//         snake = std::make_unique<Snake>(*other.snake);
//         _score = other._score;
//     }
//     return *this;
// }

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

// temp
// Player::Player(const Player& other) : _player_id(other._player_id), _score(other._score), snake(other.snake){
//     std::cout << "  -------------------------   Player copy constructor called." << std::endl;
//     }