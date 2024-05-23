#ifndef PLAYER_H
#define PLAYER_H

#include "snake.h"
#include "controller.h"
#include <memory>  // concurrency2


class Player{

    public:
    // Player(int&& player_id, int grid_width, int grid_height, float head_x);
    Player(int&& player_id, int grid_width, int grid_height, float head_x, std::shared_ptr<Controller> controller);

    void SetPlayerId(int id);
    int GetPlayerId() const {return _player_id;};
    void UpdateScore(int score);
    int GetScore() const {return _score;};
    void IncreaseScore();
    Snake snake;

    private:
        // Controller _controller;
        int const _player_id;
        int _score;
        std::shared_ptr<Controller> _controller; // concurrency2

};

#endif