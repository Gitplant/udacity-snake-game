#ifndef PLAYER_H
#define PLAYER_H

#include "snake.h"
#include "controller.h"

class Player{

    public:
    Player(int&& player_id, Snake snake, Controller controller)
      : _player_id(player_id),
        _snake(snake),
        _controller(controller),
        _score(0) {}

    void SetPlayerId(int id);
    int GetPlayerId();
    void UpdateScore(int score);
    int GetScore();

    private:
        Snake _snake;
        Controller _controller;
        int _player_id;
        int _score;

};

#endif