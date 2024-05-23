#ifndef PLAYER_H
#define PLAYER_H

#include "snake.h"
#include "controller.h"
#include <memory>  // std::shared_ptr


class Player{

    public:
    Player(int&& player_id, int grid_width, int grid_height, float head_x);

    void SetPlayerId(int id);
    int GetPlayerId() const {return _player_id;};
    void UpdateScore(int score);
    int GetScore() const {return _score;};
    void IncreaseScore();
    // Snake snake;
    std::unique_ptr<Snake> snake;

    // Rule of five:
    ~Player();
    Player(const Player& other);
    Player& operator=(const Player& other);
    Player(Player&& other) noexcept ;
    Player& operator=(Player&& other) noexcept;


    private:
        // Controller _controller;
        int const _player_id;
        int _score;

};

#endif