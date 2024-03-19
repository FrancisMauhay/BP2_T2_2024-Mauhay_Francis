#include "Spell.h"
#include "Wizard.h"
#include <iostream>

using namespace std;

void Spell::Activate(Wizard* caster, Wizard* target)
{
    srand(time(0));

    if (caster->mp < this->MpCost)
    {
        cout << caster->name << " cannot cast this... move has been waated..." << endl;

    }
    else if (caster->mp >= this->MpCost)
    {
        int MagicDmg = minDmg + rand() % (maxDmg - minDmg) +1;

        cout << caster->name << " casts " << spellname << "!" << endl;
        cout << target->name << " takes " << MagicDmg << " damage." << endl;


        target->hp -= MagicDmg;
        caster->mp -= MpCost;
    }
}

