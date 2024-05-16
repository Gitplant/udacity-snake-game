#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  // Snake(int grid_width, int grid_height)
  Snake(int grid_width, int grid_height, float head_x)  // two-player
      : grid_width(grid_width),
        grid_height(grid_height),
        // head_x(grid_width / 2),
        // head_y(grid_height / 2) {}
        head_x(head_x),  // two-player
        head_y(grid_height / 2) {}  // two-player

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

  void ChangeDirection(Snake::Direction input, Snake::Direction opposite);  // pause-game
  void PrintDirection(Snake::Direction direction); // two-player

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif