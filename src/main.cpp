#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

// two-player
int GetNrPlayers(){
  int nr_players;
  std::cout << "Are you playing with 1 or 2 players? [1/2]" << std::endl;
  std::cin >> nr_players;
  if (nr_players != 1 && nr_players != 2){
    std::cout << nr_players << " is not a valid answer. I will assume 1 player." << std::endl;
    nr_players = 1;
  }
  std::cout << "Starting game with " << nr_players << " player";
  if(nr_players>1){std::cout << "s";}
  std::cout << "!" << std::endl;

  return nr_players;
}

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  int nr_players = GetNrPlayers(); // two-player

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, nr_players);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}