#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Game; // Forward declaration
class Player;  // Forward declaration

class Controller {
 public:
  void HandleInput(bool &running, std::vector<Player> &players, Game* game) const;

 private:
};

#endif