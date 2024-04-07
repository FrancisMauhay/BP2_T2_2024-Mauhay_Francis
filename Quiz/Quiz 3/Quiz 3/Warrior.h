#pragma once
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <string>

class WarriorPlayer : public Player {
public:
    WarriorPlayer(const std::string& _name)
        : Player(_name, "Warrior", 100, 15, 10, 8, 8) {}

    void DisplayStats() override;
};

class WarriorEnemy : public Enemy {
public:
    WarriorEnemy(const std::string& _name)
        : Enemy(_name, "Warrior", 100, 15, 10, 8, 8) {}

    void DisplayStats() override;
};

