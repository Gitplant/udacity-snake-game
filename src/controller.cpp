#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "game.h" // pause-game

// comment for pause-game
// void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
//                                  Snake::Direction opposite) const {
//   if (snake.direction != opposite || snake.size == 1) snake.direction = input;
//   return;
// }

// void Controller::HandleInput(bool &running, Snake &snake) const {
void Controller::HandleInput(bool &running, Game* game) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        // PLAYER 1 uses arrows
        case SDLK_UP:
          // ChangeDirection(snake, Snake::Direction::kUp,
          //                 Snake::Direction::kDown);
          // game->ChangeSnakeDirection(Snake::Direction::kUp, Snake::Direction::kDown);  // pause-game
          game->ChangeSnakeDirection(1, Snake::Direction::kUp, Snake::Direction::kDown);  // pause-game, two-player
          break;

        case SDLK_DOWN:
          // ChangeDirection(snake, Snake::Direction::kDown,
          //                 Snake::Direction::kUp);
          // game->ChangeSnakeDirection(Snake::Direction::kDown, Snake::Direction::kUp);  // pause-game
          game->ChangeSnakeDirection(1, Snake::Direction::kDown, Snake::Direction::kUp);  // pause-game, two-player
          break;

        case SDLK_LEFT:
          // ChangeDirection(snake, Snake::Direction::kLeft,
          //                 Snake::Direction::kRight);
          // game->ChangeSnakeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);  // pause-game
          game->ChangeSnakeDirection(1, Snake::Direction::kLeft, Snake::Direction::kRight);  // pause-game, two-player
          break;

        case SDLK_RIGHT:
          // ChangeDirection(snake, Snake::Direction::kRight,
          //                 Snake::Direction::kLeft);
          // game->ChangeSnakeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);  // pause-game
          game->ChangeSnakeDirection(1, Snake::Direction::kRight, Snake::Direction::kLeft);  // pause-game, two-player
          break;
        case SDLK_a:
          if (game->GetNrPlayers() == 2){
            game->ChangeSnakeDirection(2, Snake::Direction::kLeft, Snake::Direction::kRight);  // two-player
          }
          break;
        case SDLK_SPACE:
          game->PauseGame();

      }
      if (game->GetNrPlayers() == 2){  // two-player
        switch (e.key.keysym.sym) {
        // PLAYER 2 uses WASD
        case SDLK_w:
          game->ChangeSnakeDirection(2, Snake::Direction::kUp, Snake::Direction::kDown);  // two-player
          break;

        case SDLK_s:
          game->ChangeSnakeDirection(2, Snake::Direction::kDown, Snake::Direction::kUp);  // two-player
          break;

        case SDLK_a:
          game->ChangeSnakeDirection(2, Snake::Direction::kLeft, Snake::Direction::kRight);  // two-player
          break;

        case SDLK_d:
          game->ChangeSnakeDirection(2, Snake::Direction::kRight, Snake::Direction::kLeft);  // two-player
          break;
      }
      }
    }
  }
}