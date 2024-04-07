#include "Player.h"
#include "Enemy.h"
#include <cstdlib> 

void Player::Attack(Enemy* who)
{
    int damage;
    int hitrate = (dex / who->agi) * 100;

    hitrate = std::max(20, std::min(hitrate, 80));

    int randomNum = rand() % 100 + 1;
    double Multiplier = 1;

    if (pc == "Warrior")
    {
        if (who->ec == "Assassin")
        {
            Multiplier = 1.5;
        }
        else
        {
            Multiplier = 1;
        }
    }
    else if (pc == "Assassin")
    {
        if (who->ec == "Mage")
        {
            Multiplier = 1.5;
        }
        else
        {
            Multiplier = 1;
        }
    }
    else if (pc == "Mage")
    {
        if (who->ec == "Warrior")
        {
            Multiplier = 1.5;
        }
        else
        {
            Multiplier = 1;
        }
    }

    if (randomNum <= hitrate)
    {
        damage = (pow - who->vit) * Multiplier;

        if (damage < 1)
        {
            damage = 1;
        }

        who->hp -= damage;
        cout << "Attack hits! Enemy takes " << damage << " damage." << endl;
    }
    else
    {
        cout << "Attack misses!" << endl;
    }
}

