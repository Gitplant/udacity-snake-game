#ifndef PLAYER_H
#define PLAYER_H

#include <memory>  // std::shared_ptr
#include "controller.h"
#include "snake.h"


class Player{

  public:
    Player(int&& player_id, int grid_width, int grid_height, float head_x);

    void SetPlayerId(int id);
    int GetPlayerId() const {return _player_id;};
    void UpdateScore(int score);
    int GetScore() const {return _score;};
    void IncreaseScore();
    bool CellIsOccupied(int x, int y) const;

    std::unique_ptr<Snake> snake;

    // Rule of five:
    ~Player();
    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;
    Player(Player&& other) noexcept ;
    Player& operator=(Player&& other) noexcept;


  private:
    int const _player_id;
    int _score;

};

#endif