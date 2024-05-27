#include <iostream>
#include <mutex>
#include <thread>
#include "SDL.h"
#include "controller.h"
#include "game.h"
#include "player.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, int nr_players)
  : engine(dev()),
  random_w(0, static_cast<int>(grid_width - 1)),
  random_h(0, static_cast<int>(grid_height - 1)),
  _nr_players(nr_players)
  {
    PlaceFood();
    SetPlayers(grid_width, grid_height);
    }

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, _players, this);

    if (!_paused){
      Update();
      }

    renderer.Render(_players, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(_players, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  std::mutex _mutex;

  std::unique_lock<std::mutex> lck(_mutex);
  lck.unlock();

  int x, y;
  bool _empty_spot;
  while (true) {
    _empty_spot = true;
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    for (const Player& player : _players){
      if (player.CellIsOccupied(x, y)) {
        lck.lock();
        _empty_spot = false;
        lck.unlock();
      }
    }
    if (_empty_spot){
      lck.lock();
      food.x = x;
      food.y = y;
      lck.unlock();
      return;
    }
  }
}

void Game::Update() {
  for (const Player& player : _players){
    if (!player.snake->IsAlive()) return;
  }
  for (Player& player : _players){
    player.snake->Update();

    SDL_Point new_head_int = player.snake->GetHeadInt();


    // Check if there's food over here
    if (food.x == new_head_int.x && food.y == new_head_int.y) {
      std::thread tIncreaseScore(&Player::IncreaseScore, &player);
      std::thread tPlaceFood(&Game::PlaceFood, this);
      // Grow snake and increase speed and score.
      std::thread tGrowBody(&Snake::GrowBody, std::ref(*player.snake));
      player.snake->IncreaseSpeed(0.02);
      tIncreaseScore.join();
      tPlaceFood.join();
      tGrowBody.join();
    }
  }
}

void Game::PauseGame(){
  if (_paused == true){
    _paused = false;
  }
  else{
    _paused = true;
  }
}

int Game::GetNrPlayers() const {
  return _nr_players;
}

void Game::SetPlayers(int grid_width, int grid_height){
  for (int i = 0; i < _nr_players; i++)
  {
    float head_x = grid_width * (i+1) / (_nr_players + 1);
    Player player(i+1, grid_width, grid_height, head_x);
    _players.emplace_back(std::move(player));
  }
}

// clean-up
void Game::PrintResults() const{

  for (const Player& player : _players){
    std::cout << "Player " << player.GetPlayerId() << "  -  score: " << player.GetScore() << "  -  snake length: " << player.snake->GetSize() << "  -  snake survived: " << Bool2Answer(player.snake->IsAlive()) << "\n";
  }
}

std::string Game::Bool2Answer(bool input) const{
  if (input){
    return "yes";
  }
  else{
    return "no";
  }
}
