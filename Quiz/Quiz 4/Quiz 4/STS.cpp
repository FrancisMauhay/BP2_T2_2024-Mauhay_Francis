#include "STS.h"

void Illidan::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		double Multiplier = 2.2;
		int damage;

		damage = (pow - target->vit) * Multiplier;

		if (damage < 1)
		{
			damage = 1;
		}

		target->hp -= damage;
		cout << name << " uses " << ability << " and attacks " << target->name << "! " << target->name << " takes " << damage << " damage." << endl;
	}
}

void Illidan::DisplayStats()
{
	int maxHp = 30;
	int maxMp = 17;

	cout << "Name: " << name << endl;
	cout << "HP: " << hp << "/" << maxHp << endl;
	cout << "MP: " << mp << "/" << maxMp << endl;
	cout << "POW: " << pow << endl;
	cout << "VIT: " << vit << endl;
	cout << "DEX: " << dex << endl;
	cout << "AGI: " << agi << endl << endl;

	cout << "Choose an action..." << endl;
	cout << "===============================" << endl << endl;
	cout << "[1] " << attackName << " (MP Cost: 0)" << endl;
	cout << "[2] " << ability << " (MP Cost: 5)" << endl;
}

void Valla::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		double Multiplier = 2.2;
		int damage;

		damage = (pow - target->vit) * Multiplier;

		if (damage < 1)
		{
			damage = 1;
		}

		target->hp -= damage;
		cout << name << " uses " << ability << " and attacks " << target->name << "! " << target->name << " takes " << damage << " damage." << endl;
	}
}

void Valla::DisplayStats()
{
}
