#include <iostream>
#include "Wizard.h"
#include "Spell.h"

using namespace std;

int main()
{
	srand(time(0));

	Wizard* wizard1 = new Wizard("Riela", "Cunt");
	Wizard* wizard2 = new Wizard("Saruman", "Wise");

	Spell* FireBall = new Spell("FireBall", 15, 30, 20);
	Spell* Explosion = new Spell("Explosion", 30, 60, 50);
	Spell* IronCoffin = new Spell("Iron Coffin", 50, 100, 100);

	int round = 1;
	int choice;
	int choiceAi;
	int SpellChoice;
	int SpellChoiceAi;

	while (wizard1->hp > 0 && wizard2->hp > 0)
	{
		cout << "Round " << round << "!" << endl << endl;

		cout << wizard1->name << ": " << endl;
		cout << "HP: " << wizard1->hp << endl;
		cout << "MP: " << wizard1->mp << endl << endl;

		cout << wizard2->name << ": " << endl;
		cout << "HP: " << wizard2->hp << endl;
		cout << "MP: " << wizard2->mp << endl << endl;

		cout << wizard1->name << " will now make a move..." << endl << endl;
		cout << "1: Attack" << endl;
		cout << "2: Spell" << endl;
		cin >> choice;

		system("CLS");

		switch (choice)
		{
		case 1:
			wizard1->Attack(wizard2);
			break;
		case 2:
			cout << "Choose a spell to cast: " << endl;
			cout << "1: Fireball" << endl;
			cout << "2: Explosion" << endl;
			cout << "3: Iron Coffin" << endl;
			cin >> SpellChoice;

			switch (SpellChoice)
			{
			case 1:
				FireBall->Activate(wizard1, wizard2);
				break;
			case 2:
				Explosion->Activate(wizard1, wizard2);
				break;
			case 3:
				IronCoffin->Activate(wizard1, wizard2);
				break;
			default:
				cout << "ERROR" << endl;
			}
			break;
		default:
				cout << "ERROR" << endl;
		}

		system("pause");
		system("CLS");

		cout << wizard2->name << " is making their move..." << endl;
		choiceAi = rand() % 2 + 1;

		switch (choiceAi)
		{
		case 1:
			wizard2->Attack(wizard1);
			break;
		case 2:

			SpellChoiceAi = rand() % 3 + 1;

			switch (SpellChoiceAi)
			{
			case 1:
				FireBall->Activate(wizard2, wizard1);
				break;
			case 2:
				Explosion->Activate(wizard2, wizard1);
				break;
			case 3:
				IronCoffin->Activate(wizard2, wizard1);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		round++;
		system("pause");
		system("CLS");
	}

	if (wizard1->hp < 0)
	{
		cout << wizard1->name << " has been defeated..." << endl;

		delete wizard1;
		delete wizard2;
		delete FireBall;
		delete Explosion;
		delete IronCoffin;

		system("pause");
	}
	else
	{
		cout << wizard2->name << " has been defeated !!" << endl;

		delete wizard1;
		delete wizard2;
		delete FireBall;
		delete Explosion;
		delete IronCoffin;

		system("pause");
	}

	return 0;
}