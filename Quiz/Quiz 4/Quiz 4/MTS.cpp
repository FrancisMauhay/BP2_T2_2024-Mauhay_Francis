#include "MTS.h"

void ETC::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		int damage;
		double Multiplier = 0.9;

		damage = (pow - target->vit) * Multiplier;

		if (damage < 1)
		{
			damage = 1;
		}

		target->hp -= damage;
		cout << name << " uses " << ability << " and attacks " << target->name << "! " << target->name << " takes " << damage << " damage." << endl;
	}
}

void ETC::DisplayStats()
{
	int maxHp = 45;
	int maxMp = 15;

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
	cout << "[2] " << ability << " (MP Cost: 4)" << endl;
}

void Johanna::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		int damage;
		double Multiplier = 0.9;

		damage = (pow - target->vit) * Multiplier;

		if (damage < 1)
		{
			damage = 1;
		}

		target->hp -= damage;
		cout << name << " uses " << ability << " and attacks " << target->name << "! " << target->name << " takes " << damage << " damage." << endl;
	}
}

void Johanna::DisplayStats()
{
	return;
}
