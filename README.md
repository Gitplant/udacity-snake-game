# CPPND: Capstone Snake Game Example

This is the assignment submission for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## New features
1. **Pause:** The game will pause when the space-bar is pressed and unpause when the space bar is pressed again. <br>
Involved code changes:<br>
    *  The method `Controller::HandleInput`:<br>
        a. now takes `Game* game` as an input instead of `Snake &snake`.<br>
        b. calls `game->PauseGame()` when space bar is pressed. <br>
    *  The method `Controller::ChangeDirection(Snake &snake, Snake::Direction input, Snake::Direction opposite)` is moved to the `Game` class and renamed `Game::ChangeSnakeDirection(Snake::Direction input, Snake::Direction opposite)`.
    *  A new function `void ChangeDirection(Snake::Direction input, Snake::Direction opposite)` is added to the `Snake` class.
    *  The method `Game::PauseGame()` sets the attribute `_paused` to either `true` or `false`.
    *  `Game::Run` won't call `Update()` if `_paused` is false.
2. **Two-player mode** Optionally play the game with two players. <br>
Involved code changes:<br>
    * Get the number of players from the user:<br>
      a. The function `GetNrPlayers()` is defined in main, which asks the user to enter the number of players and returns an `int` accordingly.<br>
      b. Inside `main()`, the `nr_players` is set.

## Rubric criteria that were met
### Loops, Functions, I/O - meet at least 2 criteria
|Criteria| Implementation|
|--------|---------------|
|The project accepts user input and processes the input.| 1. The game will pause when the user presses the space-bar. <br> 2. The user is prompted to enter the number of players (1 or 2).|
