#include "Character.h"

void Character::Attack(const vector<Character*>& targets)
{
    for (Character* target : targets)
    {
        int damage;
        int hitrate = (dex / target->agi) * 100;
        hitrate = std::max(20, std::min(hitrate, 80));

        int randomNum = rand() % 100 + 1;

        if (randomNum >= hitrate)
        {
            damage = (pow - target->vit);

            if (damage < 1)
            {
                damage = 1;
            }

            target->hp -= damage;
            cout << name << " attacks " << target->name << "! " << target->name << " takes " << damage << " damage." << endl;
        }
        else
        {
            cout << name << " attacks " << target->name << ", but misses!" << endl;
        }
    }
}

bool Character::isAlive() const
{
    return hp > 0;
}
