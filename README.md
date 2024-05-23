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
    * The `Game` constructor also takes and sets the number of players.
    * A getter for `_nr_players` (`GetNrPlayers()`) is defined in the `Game` class.
    * Inside `Controller::HandleInput`, the direction of the second snake is updated using the WASD keys.
    * A `SetSnakes` method is created inside `Game` that will initialize a vector of snakes called `_snakes`. In case of two snakes, their start positions are on 1/3 and 2/3 of the width of the screen, so that they won't overlap.
    * In `Game::Run` all snakes are rendered and updated.
    * A helper function for printing the snake's direction (`Snake::PrintDirection`) was introduced.

## Rubric criteria that were met

## README (All Rubric Points REQUIRED)
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|A README with instructions is included with the project |The README is included with the project and has instructions for building/running the project. <br> If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. <br> You can submit your writeup as markdown or pdf. | This markdown README is provided. |
|The README indicates the new features you added to the game. | The README indicates the new features you added to the game, along with the expected behavior or output of the program. ||
|The README includes information about each rubric point addressed. | The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.| This is done in this section "Rubric criteria that were met"|

## Compiling and Testing (All Rubric Points REQUIRED)
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| The submission must compile and run without errors on the Udacity project workspace. | We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must be compiled on the Udacity project workspace. | The project can be built using cmake and make.|

## Object Oriented Programming - meet at least 3 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| One or more classes are added to the project with appropriate access specifiers for class members. | Classes are organized with attributes to hold data and methods to perform tasks. <br> All class data members are explicitly specified as public, protected, or private. <br> Member data that is subject to an invariant is hidden from the user and accessed via member methods. |The class `Player` was added to the project.|
| Class constructors utilize member initialization lists. | All class members that are set to argument values are initialized through member initialization lists.||
|Classes abstract implementation details from their interfaces. | All class member functions document their effects, either through function names, comments, or formal documentation. <br> Member functions do not change the program state in undocumented ways. ||
| Overloaded functions allow the same function to operate on different parameters. | One function is overloaded with different signatures for the same function name.||
| Classes follow an appropriate inheritance hierarchy with virtual and override functions. | Inheritance hierarchies are logical. One member function in an inherited class overrides a virtual base class member function. ||
|Templates generalize functions or classes in the project. | One function or class is declared with a template that allows it to accept a generic parameter.||

## Memory Management - meet at least 3 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| The project makes use of references in function declarations. | At least two variables are defined as references, or two functions use pass-by-reference in the project code. |1. In `void Game::ChangeSnakeDirection(int&& player_nr, Snake::Direction input, Snake::Direction opposite)`, the `player_nr` is passed as an r-value reference.|
|The project uses destructors appropriately. | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. ||
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. ||
| The project follows the Rule of 5. | For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined. ||
| The project uses move semantics to move data instead of copying it, where possible. | The project relies on the move semantics, instead of copying the object. ||
| The project uses smart pointers instead of raw pointers. | The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. | The `snake` attribute of the `Player` class is a unique pointer.|


### Loops, Functions, I/O - meet at least 2 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|The project demonstrates an understanding of C++ functions and control structures. | A variety of control structures are added to the project. <br> The project code is clearly organized into functions.||
|The project reads data from a file and process the data, or the program writes data to a file.| The project reads data from an external file or writes data to a file as part of the necessary operation of the program.||
|The project accepts user input and processes the input.|	In addition to controlling the snake, the game can also receive new types of input from the player. | 1. The game will pause when the user presses the space-bar. <br> 2. The user is prompted to enter the number of players (1 or 2).|
|The project uses data structures and immutable variables.|The project uses arrays or vectors and uses constant variables.|The attribute `_nr_players` of class `Game` is defined as a const.|

### Concurrency - meet at least 2 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|The project uses multithreading.| The project uses multiple threads or async tasks in the execution.| The project uses threads when increasing the score, placing food and growing the body in `Game::Update`.|
|  promise and future is used in the project. | A promise and future is used to pass data from a worker thread to a parent thread in the project code. ||
|A mutex or lock is used in the project. | A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. |Mutexes and locks are used in: <br> * `Game::PlaceFood` (`std::unique_lock`) <br> * `Snake::GrowBody` <br> * `Player::IncreaseScore`|
| A condition variable is used in the project. | A `std::condition_variable`` is used in the project code to synchronize thread execution. ||
