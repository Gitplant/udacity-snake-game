#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : gridWidth_(grid_width),
        gridHeight_(grid_height),
        headX_(grid_width / 2),
        headY_(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction_{Direction::kUp};

  float speed_{0.1f};
  int size_{1};
  bool alive_{true};
  float headX_;
  float headY_;
  std::vector<SDL_Point> body_;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing_{false};
  int gridWidth_;
  int gridHeight_;
};

#endif