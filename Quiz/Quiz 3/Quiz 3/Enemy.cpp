#include "Enemy.h"
#include "Player.h"
#include <cstdlib>

void Enemy::AttackPlayer(Player* who)
{
    int damage;
    int hitrate = (dex / who->agi) * 100;

    hitrate = std::max(20, std::min(hitrate, 80));

    int randomNum = rand() % 100 + 1;
    int Multiplier = 1;

    if (ec == "Warrior")
    {
        if (who->pc == "Assassin")
        {
            Multiplier = 1.5;
        }
        else
        {
            Multiplier = 1;
        }
    }
    else if (ec == "Assassin")
    {
        if (who->pc == "Mage")
        {
            Multiplier = 1.5;
        }
        else
        {
            Multiplier = 1;
        }
    }
    else if (ec == "Mage")
    {
        if (who->pc == "Warrior")
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
        damage = (pow - who->vit) *Multiplier;

        if (damage < 1)
        {
            damage = 1;
        }

        who->hp -= damage;
        cout << "Attack hits! You take " << damage << " damage." << endl;
    }
    else
    {
        cout << "Attack misses!" << endl;
    }
}
