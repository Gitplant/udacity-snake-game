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
The following features were added as part of the assignment:
1. **Pause:** The game will pause when the space-bar is pressed and unpause when the space bar is pressed again. <br>
2. **Two-player mode** Optionally play the game with two players. <br>
  a. Ask the user if they are playing with 1 or 2 players <br>
  b. In case of 2 players:
    - Player 2 uses the WASD keys
    - The snake will die if it collides either with its own or the other snake's body
    - The game continues untill all snakes have died
    - The player with the highest score wins (regardless of how long the snake survived).
    - The score and winner are printed to the screen

## Rubric criteria that were met

## README (All Rubric Points REQUIRED)
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|A README with instructions is included with the project |The README is included with the project and has instructions for building/running the project. <br> If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. <br> You can submit your writeup as markdown or pdf. | This markdown README is provided. |
|The README indicates the new features you added to the game. | The README indicates the new features you added to the game, along with the expected behavior or output of the program. | See the section "_New features_"|
|The README includes information about each rubric point addressed. | The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.| This is done in the current section "_Rubric criteria that were met_"|

## Compiling and Testing (All Rubric Points REQUIRED)
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| The submission must compile and run without errors on the Udacity project workspace. | We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must be compiled on the Udacity project workspace. | The project can be built using cmake and make.|

## Object Oriented Programming - meet at least 3 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| One or more classes are added to the project with appropriate access specifiers for class members. | Classes are organized with attributes to hold data and methods to perform tasks. <br> All class data members are explicitly specified as public, protected, or private. <br> Member data that is subject to an invariant is hidden from the user and accessed via member methods. |The class `Player` was added to the project. The attributes `_player_id` and `_score` are specified as private with the required getters and setters. The `_player_id` is also `const`. The attribute `snake` is public so that it can be accessed from within `controller`, `game` and `renderer`.|
| Class constructors utilize member initialization lists. | All class members that are set to argument values are initialized through member initialization lists.| The constructors of the `Game`, `Renderer`, `Snake` and `Player` class use initialization lists. The `Render` class uses the default constructor.|
|Classes abstract implementation details from their interfaces. | All class member functions document their effects, either through function names, comments, or formal documentation. <br> Member functions do not change the program state in undocumented ways. | All class member functions have names that describe their effect. In cases where this was considered insufficient, an extra comment was added.|
| Overloaded functions allow the same function to operate on different parameters. | One function is overloaded with different signatures for the same function name.| N/A|
| Classes follow an appropriate inheritance hierarchy with virtual and override functions. | Inheritance hierarchies are logical. One member function in an inherited class overrides a virtual base class member function. | N/A|
|Templates generalize functions or classes in the project. | One function or class is declared with a template that allows it to accept a generic parameter.| N/A|

## Memory Management - meet at least 3 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
| The project makes use of references in function declarations. | At least two variables are defined as references, or two functions use pass-by-reference in the project code. | The following functions use pass-by-reference: <br> 1. `void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration)` <br> 2. `void Renderer::Render(std::vector<Player> const &players, SDL_Point const &food)` <br> 3. `void Renderer::UpdateWindowTitle(std::vector<Player> &players, int fps) const` <br> 4. `void Snake::UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell)` <br> 5. `void Controller::HandleInput(bool &running, std::vector<Player> &players, Game* game) const` <br> 6. `Player(int&& player_id, int grid_width, int grid_height, float head_x)` <br> 7. `Player(const Player& other)` <br> 8. `Player& operator=(const Player& other)` <br> 9. `Player(Player&& other)` <br> 10. `Player& operator=(Player&& other)`|
|The project uses destructors appropriately. | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. |N/a|
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. ||
| The project follows the Rule of 5. | For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined. | The class `Player` has the rule of five implemented. Copying an instance of `Player` is not allowed in this implementation.|
| The project uses move semantics to move data instead of copying it, where possible. | The project relies on the move semantics, instead of copying the object. | An object of class `Player` cannot by copied by definition and is moved at several places in the code. Also objects of class `Snake` are being moved around, for example in the move constructor and the move assignment operator of the `Player` class. |
| The project uses smart pointers instead of raw pointers. | The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. | The `snake` attribute of the `Player` class is a unique pointer.|


### Loops, Functions, I/O - meet at least 2 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|The project demonstrates an understanding of C++ functions and control structures. | A variety of control structures are added to the project. <br> The project code is clearly organized into functions.| The code contains conditional statements, loops and clearly organized functions. For example in `Game::Update`: <br> 1. A for-loop is started to loop over all players <br> 2. An if-statement checks if that player's snake is still alive <br> 3. Another if-statement checks if that player's snake has moved to a new block <br> 4. A nested for-loop is started to loop over all players again <br> 5. Another nested for-loop loops over all body-elements of the player's snake <br> 6. An if-statement is used to check if the head of the first snake collides with a body element of either of the snakes.|
|The project reads data from a file and process the data, or the program writes data to a file.| The project reads data from an external file or writes data to a file as part of the necessary operation of the program.| N/a |
|The project accepts user input and processes the input.|	In addition to controlling the snake, the game can also receive new types of input from the player. | 1. The game will pause when the user presses the space-bar. <br> 2. The user is prompted to enter the number of players (1 or 2).|
|The project uses data structures and immutable variables.|The project uses arrays or vectors and uses constant variables.|The project uses vectors (`_players`, `player_colors` and `_body`) and structs (`Color` and `FPoint`).  The project also defines several variables as const (`_nr_players`, `_player_id`, `_color`).|

### Concurrency - meet at least 2 criteria
|Criteria|	Submission Requirements| Implementation|
|--------|---------------|----------|
|The project uses multithreading.| The project uses multiple threads or async tasks in the execution.| The project uses threads when increasing the score, placing food and growing the body in `Game::Update`.|
|  promise and future is used in the project. | A promise and future is used to pass data from a worker thread to a parent thread in the project code. | N/a |
|A mutex or lock is used in the project. | A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. |Mutexes and locks are used in: <br> * `Game::PlaceFood` (`std::unique_lock`) <br> * `Snake::GrowBody` <br> * `Player::IncreaseScore`|
| A condition variable is used in the project. | A `std::condition_variable`` is used in the project code to synchronize thread execution. | N/a |
