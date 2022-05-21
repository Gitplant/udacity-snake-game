#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screenWidth_(screen_width),
      screenHeight_(screen_height),
      gridWidth_(grid_width),
      gridHeight_(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdlWindow_ = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdlWindow_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdlRenderer_ = SDL_CreateRenderer(sdlWindow_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdlRenderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdlWindow_);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screenWidth_ / gridWidth_;
  block.h = screenHeight_ / gridHeight_;

  // Clear screen
  SDL_SetRenderDrawColor(sdlRenderer_, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdlRenderer_);

  // Render food
  SDL_SetRenderDrawColor(sdlRenderer_, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdlRenderer_, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdlRenderer_, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body_) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdlRenderer_, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.headX_) * block.w;
  block.y = static_cast<int>(snake.headY_) * block.h;
  if (snake.alive_) {
    SDL_SetRenderDrawColor(sdlRenderer_, 0x00, 0x7C, 0xFC, 0x00);
  } else {
    SDL_SetRenderDrawColor(sdlRenderer_, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdlRenderer_, &block);

  // Update Screen
  SDL_RenderPresent(sdlRenderer_);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdlWindow_, title.c_str());
}
