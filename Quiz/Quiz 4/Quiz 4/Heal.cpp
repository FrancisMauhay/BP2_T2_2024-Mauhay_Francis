#include "Heal.h"

void LiLi::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		double healMultiplier = 0.3;
		int heal;

		heal = target->hp * healMultiplier;

		if (heal < 1)
		{
			heal = 1;
		}

		target->hp += heal;
		cout << name << " heals " << target->name << "! " << target->name << " heals " << heal << " hp." << endl;
	}
}

void LiLi::DisplayStats()
{
	int maxHp = 30;
	int maxMp = 18;

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
	cout << "[2] " << ability << " (MP Cost: 3)" << endl;
}

void Kharazim::SpecialAbility(const vector<Character*>& targets)
{
	for (Character* target : targets)
	{
		int healMultiplier = 0.3;
		int heal;

		heal = target->hp * healMultiplier;

		if (heal < 1)
		{
			heal = 1;
		}

		target->hp += heal;
		cout << name << " heals " << target->name << "! " << target->name << " heals " << heal << " hp." << endl;
	}
}

void Kharazim::DisplayStats()
{
}
