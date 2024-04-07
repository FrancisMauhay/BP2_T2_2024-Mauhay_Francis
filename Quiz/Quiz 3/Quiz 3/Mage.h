#pragma once
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>

class MagePlayer : public Player {
public:
    MagePlayer(const std::string& _name)
        : Player(_name, "Mage", 100, 10, 8, 8, 15) {}

    void DisplayStats() override;
};

class MageEnemy : public Enemy {
public:
    MageEnemy(const std::string& _name)
        : Enemy(_name, "Mage", 100, 10, 8, 8, 15) {}

    void DisplayStats() override;
};
