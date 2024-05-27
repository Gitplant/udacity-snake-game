#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include "snake.h"

Snake::Snake(int grid_width, int grid_height, float head_x, Color color) :
_grid_width(grid_width),
_grid_height(grid_height),
_color(color),
_head_x(head_x),
_head_y(grid_height / 2) {}

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(_head_x),
      static_cast<int>(
          _head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (_direction) {
    case Direction::kUp:
      _head_y -= _speed;
      break;

    case Direction::kDown:
      _head_y += _speed;
      break;

    case Direction::kLeft:
      _head_x -= _speed;
      break;

    case Direction::kRight:
      _head_x += _speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  _head_x = fmod(_head_x + _grid_width, _grid_width);
  _head_y = fmod(_head_y + _grid_height, _grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  _body.push_back(prev_head_cell);

  if (!_growing) {
    // Remove the tail from the vector.
    _body.erase(_body.begin());
  } else {
    _growing = false;
    _size++;
  }

  // Check if the snake has died.
  for (auto const &item : _body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      KillSnake();
    }
  }
}

void Snake::GrowBody() {
  std::mutex _mutex;
  std::lock_guard<std::mutex> lock(_mutex);
  _growing = true;}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(_head_x) && y == static_cast<int>(_head_y)) {
    return true;
  }
  for (auto const &item : _body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}

// Change the snake's direction based on the input.
void Snake::ChangeDirection(Snake::Direction input, Snake::Direction opposite){
  if (_direction != opposite || GetSize() == 1) _direction = input;
}

// Helper function to print the snake's direction (for debugging).
void Snake::PrintDirection(Snake::Direction direction) const {
  switch (direction) {
    case Direction::kUp:
      std::cout << "kUp" << std::endl;
      break;
    case Direction::kDown:
      std::cout << "kDown" << std::endl;
      break;
    case Direction::kLeft:
      std::cout << "kLeft" << std::endl;
      break;
    case Direction::kRight:
      std::cout << "kRight" << std::endl;
      break;
  }
}