#include "renderer.h"
#include <iostream>
#include <string>
#include "player.h"  // player-class

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

// void Renderer::Render(Snake const snake, SDL_Point const &food) {
// void Renderer::Render(std::vector<Snake> const snakes, SDL_Point const &food) {  // two-player
void Renderer::Render(std::vector<Player> const &players, SDL_Point const &food) {  // two-player, player-class
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // for(Snake snake : snakes){  // two-player
  for(const Player& player : players){  // two-player, player-class
    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // for (SDL_Point const &point : snake.body) {
      for (SDL_Point const &point : player.snake->body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    // block.x = static_cast<int>(snake.head_x) * block.w;
    // block.y = static_cast<int>(snake.head_y) * block.h;
    // if (snake.alive) {
    block.x = static_cast<int>(player.snake->head_x) * block.w;
    block.y = static_cast<int>(player.snake->head_y) * block.h;
    if (player.snake->alive) {

      // SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
      SDL_SetRenderDrawColor(sdl_renderer, player.snake->color.r, player.snake->color.g, player.snake->color.b, player.snake->color.a);
    } else {
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);
  }  // two-player

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

// void Renderer::UpdateWindowTitle(int score, int fps) {
void Renderer::UpdateWindowTitle(std::vector<Player> &players, int fps) const {
  std::string title;
  for (const Player &player: players){  // player-class
    title += "Player " + std::to_string(player.GetPlayerId()) + ": " + std::to_string(player.GetScore()) + "   ";
  }
  title += "FPS: " + std::to_string(fps);
  // std::string title{"Player Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
