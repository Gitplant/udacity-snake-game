#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

struct Color{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
  };

class Snake {
 public:
  Snake(int grid_width, int grid_height, float head_x, Color color = Color{255, 255, 255, 255});

  enum class Direction { kUp, kDown, kLeft, kRight };

  // Getters
  Color GetColor() const {return _color;};
  int GetSize() const {return _size;};
  bool IsAlive() const {return _alive;};
  float GetHeadX() const {return _head_x;};
  float GetHeadY() const {return _head_y;};
  std::vector<SDL_Point> GetBody() const {return _body;};

  void Update();
  void GrowBody();
  bool SnakeCell(int x, int y);
  void ChangeDirection(Snake::Direction input, Snake::Direction opposite);
  void PrintDirection(Snake::Direction direction) const;
  void KillSnake(){_alive = false;};
  void IncreaseSpeed(float speed_increase){_speed += speed_increase;};

 private:
  Color const _color;
  int const _grid_width;
  int const _grid_height;

  float _speed{0.1f};
  int _size{1};
  float _head_x;
  float _head_y;
  std::vector<SDL_Point> _body;

  Direction _direction = Direction::kUp;
  bool _growing{false};
  bool _alive{true};

  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

};

#endif