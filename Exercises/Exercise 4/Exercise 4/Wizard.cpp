#include "Wizard.h"
#include <iostream>

using namespace std;

void Wizard::Attack(Wizard* who)
{
	srand(time(0));

	int AtkPwr = minAtk + rand() % (maxAtk - minAtk + 1);
	int ManaGen = 10 + rand() % (20 - 10 + 1);

	cout << this->name << " attacked " << who->name << endl;
	cout << this->name << " dealt " << AtkPwr << endl;
	cout << this->name << " generated " << ManaGen << endl;

	who->hp -= AtkPwr;
	this->mp += ManaGen;
}
