#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Game; // pause-game: Forward declaration

class Controller {
 public:
//   void HandleInput(bool &running, Snake &snake) const;
void HandleInput(bool &running, Game* game) const;  // pause-game
void HandleInputPlayer2(bool &running, Game* game) const;  // concurrency

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif