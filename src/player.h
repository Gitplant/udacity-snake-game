#ifndef PLAYER_H
#define PLAYER_H

#include "snake.h"
#include "controller.h"


class Player{

    public:
    Player(int&& player_id, int grid_width, int grid_height, float head_x);

    void SetPlayerId(int id);
    int GetPlayerId(){return _player_id;};
    void UpdateScore(int score);
    int GetScore(){return _score;};
    void IncreaseScore();
    Snake snake;
    void HandleInput(bool &running);

    private:
        // Controller _controller;
        int _player_id;
        int _score;

};

#endif