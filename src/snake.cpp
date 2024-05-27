#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include "snake.h"

Snake::Snake(int grid_width, int grid_height, float head_x, Color color) :
_grid_width(grid_width),
_grid_height(grid_height),
_color(color),
_head({head_x, static_cast<float>(grid_height) / 2}) {;
}

void Snake::Update() {

  SDL_Point prev_cell = GetHeadInt();  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell = GetHeadInt();  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    _has_moved = true;
    UpdateBody(current_cell, prev_cell);
  }
  else{
    _has_moved = false;
  }
}

void Snake::UpdateHead() {
  switch (_direction) {
    case Direction::kUp:
      _head.y -= _speed;
      break;

    case Direction::kDown:
      _head.y += _speed;
      break;

    case Direction::kLeft:
      _head.x -= _speed;
      break;

    case Direction::kRight:
      _head.x += _speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  _head.x = fmod(_head.x + _grid_width, _grid_width);
  _head.y = fmod(_head.y + _grid_height, _grid_height);
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
}

void Snake::GrowBody() {
  std::mutex _mutex;
  std::lock_guard<std::mutex> lock(_mutex);
  _growing = true;}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(_head.x) && y == static_cast<int>(_head.y)) {
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

SDL_Point Snake::GetHeadInt() const {
  SDL_Point head;
  head.x = static_cast<int>(_head.x);
  head.y = static_cast<int>(_head.y);
  return head;
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