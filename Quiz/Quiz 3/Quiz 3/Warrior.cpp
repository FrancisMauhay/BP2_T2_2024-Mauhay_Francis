#include "Warrior.h"

using namespace std;


void WarriorPlayer::DisplayStats()
{
	cout << "Class: Warrior" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "POW: " << pow << endl;
	cout << "VIT: " << vit << endl;
	cout << "AGI: " << agi << endl;
	cout << "DEX: " << dex << endl;
}

void WarriorEnemy::DisplayStats()
{
	cout << "Class: Warrior" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "POW: " << pow << endl;
	cout << "VIT: " << vit << endl;
	cout << "AGI: " << agi << endl;
	cout << "DEX: " << dex << endl;
}
