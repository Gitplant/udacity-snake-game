#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "player.h"  // player-class

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  // void Render(Snake const snake, SDL_Point const &food);
  // void Render(std::vector<Snake> const snakes, SDL_Point const &food);  // two-player
  void Render(std::vector<Player> const players, SDL_Point const &food);  // two-player, player-class
  // void UpdateWindowTitle(int score, int fps);
  void UpdateWindowTitle(std::vector<Player> &players, int fps) const;  // player-class

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif