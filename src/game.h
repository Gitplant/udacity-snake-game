#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  // Game(std::size_t grid_width, std::size_t grid_height);
  Game(std::size_t grid_width, std::size_t grid_height, int nr_players);  // two-player
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  // void ChangeSnakeDirection(Snake::Direction input, Snake::Direction opposite);  // pause-game
  void ChangeSnakeDirection(int&& snake_nr, Snake::Direction input, Snake::Direction opposite);  // pause-game, two-player
  void PauseGame();  // pause-game
  void SetSnakes(int grid_width, int grid_height);  // two-player

 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();

  // Added:
  bool _paused{false};  // pause-game
  int const _nr_players; // two-player
  std::vector<Snake> _snakes;  //two-player
};

#endif