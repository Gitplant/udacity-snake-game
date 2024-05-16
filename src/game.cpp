#include "game.h"
#include "controller.h" // concurrency
#include <iostream>
#include <thread>  // concurrency
#include "SDL.h"

// Game::Game(std::size_t grid_width, std::size_t grid_height)
Game::Game(std::size_t grid_width, std::size_t grid_height, int nr_players)  // two-player
    // : snake(grid_width, grid_height),
    : snake(grid_width, grid_height, grid_width / 2),  // two-player
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      _nr_players(nr_players) {  // two-player
  PlaceFood();
  SetSnakes(grid_width, grid_height);
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
    // controller.HandleInput(running, snake);
    controller.HandleInput(running, this);  // pause-game

    // Allow both players to give input at the same time
    if (_nr_players == 2){  // concurrency
      // Use multi-threading
      // std::thread t(Controller::HandleInputPlayer2, controller, running, this);  // concurrency
      std::thread t([&controller, &running, this]() {controller.HandleInputPlayer2(running, this);});  // concurrency
      std::cout << "Thread id = " << t.get_id() << std::endl;  // concurrency
      std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;  // concurrency
      t.join();  // concurrency
    }  // concurrency
    if (!_paused){  // pause-game
    Update();
    }  // pause-game
    // renderer.Render(snake, food);
    renderer.Render(_snakes, food);  // two-player

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
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
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  for (Snake& snake : _snakes){  // two-player
    if (!snake.alive) return;

    snake.Update();

    int new_x = static_cast<int>(snake.head_x);
    int new_y = static_cast<int>(snake.head_y);

    // Check if there's food over here
    if (food.x == new_x && food.y == new_y) {
      score++;
      PlaceFood();
      // Grow snake and increase speed.
      snake.GrowBody();
      snake.speed += 0.02;
    }
  }  // two-player
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

// pause-game
void Game::ChangeSnakeDirection(int&& player_nr, Snake::Direction input, Snake::Direction opposite) {
  _snakes[player_nr - 1].ChangeDirection(input, opposite);
  return;
}

// pause-game
void Game::PauseGame(){
  if (_paused == true){
    _paused = false;
  }
  else{
    _paused = true;
  }
}

// two-player
void Game::SetSnakes(int grid_width, int grid_height){
  for (int i = 0; i < _nr_players; i++)
  {
    float head_x = grid_width * (i+1) / (_nr_players + 1);
    Snake snake(grid_width, grid_height, head_x);
    _snakes.push_back(snake);
  }
}

int Game::GetNrPlayers() const {  // two-player
  return _nr_players;
}  // two-player