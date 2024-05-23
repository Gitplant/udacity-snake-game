#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "game.h" // pause-game
#include "player.h"  // player-class

// comment for pause-game
// void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
//                                  Snake::Direction opposite) const {
//   if (snake.direction != opposite || snake.size == 1) snake.direction = input;
//   return;
// }

// void Controller::HandleInput(bool &running, Snake &snake) const {
// void Controller::HandleInput(bool &running, Game* game) const {
  void Controller::HandleInput(bool &running, std::vector<Player> &players, Game* game) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
          case SDLK_SPACE:
            game->PauseGame();  // pause-game
            break;
          // PLAYER 1 uses arrows
          case SDLK_UP:
            // ChangeDirection(snake, Snake::Direction::kUp,
            //                 Snake::Direction::kDown);
            // game->ChangeSnakeDirection(Snake::Direction::kUp, Snake::Direction::kDown);  // pause-game
            // game->ChangeSnakeDirection(1, Snake::Direction::kUp, Snake::Direction::kDown);  // pause-game, two-player
            players[0].snake.ChangeDirection(Snake::Direction::kUp, Snake::Direction::kDown);  // pause-game, two-player, player-class
            break;

          case SDLK_DOWN:
            // ChangeDirection(snake, Snake::Direction::kDown,
            //                 Snake::Direction::kUp);
            // game->ChangeSnakeDirection(Snake::Direction::kDown, Snake::Direction::kUp);  // pause-game
            // game->ChangeSnakeDirection(1, Snake::Direction::kDown, Snake::Direction::kUp);  // pause-game, two-player
            players[0].snake.ChangeDirection(Snake::Direction::kDown, Snake::Direction::kUp);  // pause-game, two-player
            break;

          case SDLK_LEFT:
            // ChangeDirection(snake, Snake::Direction::kLeft,
            //                 Snake::Direction::kRight);
            // game->ChangeSnakeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);  // pause-game
            players[0].snake.ChangeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);  // pause-game, two-player
            break;

          case SDLK_RIGHT:
            // ChangeDirection(snake, Snake::Direction::kRight,
            //                 Snake::Direction::kLeft);
            // game->ChangeSnakeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);  // pause-game
            players[0].snake.ChangeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);  // pause-game, two-player
            break;
        // case SDLK_SPACE:
        //   game->PauseGame();

        // PLAYER 2 uses WASD
        case SDLK_w:
      //     // game->ChangeSnakeDirection(2, Snake::Direction::kUp, Snake::Direction::kDown);  // two-player
          players[1].snake.ChangeDirection(Snake::Direction::kUp, Snake::Direction::kDown);
          break;

        case SDLK_s:
      //     // game->ChangeSnakeDirection(2, Snake::Direction::kDown, Snake::Direction::kUp);  // two-player
          players[1].snake.ChangeDirection(Snake::Direction::kDown, Snake::Direction::kUp);  // two-player
          break;

        case SDLK_a:
          // game->ChangeSnakeDirection(2, Snake::Direction::kLeft, Snake::Direction::kRight);  // two-player
          players[1].snake.ChangeDirection(Snake::Direction::kLeft, Snake::Direction::kRight);  // two-player
          break;

        case SDLK_d:
      //     // game->ChangeSnakeDirection(2, Snake::Direction::kRight, Snake::Direction::kLeft);  // two-player
          players[1].snake.ChangeDirection(Snake::Direction::kRight, Snake::Direction::kLeft);  // two-player
          break;
      }
    }
  }
}

// temp
// Controller::Controller(const Controller& other) {
//     std::cout << "  -------------------------   Controller copy constructor called." << std::endl;
//     }