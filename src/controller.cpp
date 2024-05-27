#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "game.h"
#include "player.h"

// Handle the keyboard input from the user
void Controller::HandleInput(bool &running, std::vector<Player> &players, Game* game) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
      }
    else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        // Pause the game
        case SDLK_SPACE:
          game->PauseGame();
          break;

        // PLAYER 1 uses arrows
        case SDLK_UP:
          players[0].snake->ChangeDirection(Snake::Direction::kUp, Snake::Direction::kDown);
          break;
        case SDLK_DOWN:
          players[0].snake->ChangeDirection(Snake::Direction::kDown, Snake::Direction::kUp);
          break;
        case SDLK_LEFT:
          players[0].snake->ChangeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);
          break;
        case SDLK_RIGHT:
          players[0].snake->ChangeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);
          break;

        // PLAYER 2 uses WASD keys
        case SDLK_w:
          players[1].snake->ChangeDirection(Snake::Direction::kUp, Snake::Direction::kDown);
          break;
        case SDLK_s:
          players[1].snake->ChangeDirection(Snake::Direction::kDown, Snake::Direction::kUp);
          break;
        case SDLK_a:
          players[1].snake->ChangeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);
          break;
        case SDLK_d:
          players[1].snake->ChangeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);
          break;
      }
    }
  }
}