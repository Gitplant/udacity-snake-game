#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "player.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int nr_players);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  void PauseGame();
  int GetNrPlayers() const;
  void SetPlayers(int grid_width, int grid_height);
  void PrintResults() const;
  std::string Bool2Answer(bool input) const;

 private:
  SDL_Point food;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  void PlaceFood();
  void Update();

  bool _paused{false};
  int const _nr_players;
  std::vector<Player> _players;
  bool _finished{false};
};

#endif