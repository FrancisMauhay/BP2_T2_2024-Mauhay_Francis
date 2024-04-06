#pragma once
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>

class AssassinPlayer : public Player {
public:
    AssassinPlayer(const std::string& _name)
        : Player(_name, 100, 8, 8, 15, 10) {}

    void DisplayStats() override;
};


class AssassinEnemy : public Enemy {
public:
    AssassinEnemy(const std::string& _name)
        : Enemy(_name, 100, 8, 8, 15, 10) {}

    void DisplayStats() override;
};
