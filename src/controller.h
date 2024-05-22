#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Game; // pause-game: Forward declaration
class Player;  // player-class: Forward declaration

class Controller {
 public:
//   void HandleInput(bool &running, Snake &snake) const;
// void HandleInput(bool &running, Snake &snake, Game* game) const;
  void HandleInput(bool &running, std::vector<Player> &players, Game* game) const;


 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif