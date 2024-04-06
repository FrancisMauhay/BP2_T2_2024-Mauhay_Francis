#include "Assassin.h"

using namespace std;

void AssassinPlayer::DisplayStats()
{
	cout << "Class: Assassin" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "POW: " << pow << endl;
	cout << "VIT: " << vit << endl;
	cout << "AGI: " << agi << endl;
	cout << "DEX: " << dex << endl;
}

void AssassinEnemy::DisplayStats()
{
	cout << "Class: Assassin" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "POW: " << pow << endl;
	cout << "VIT: " << vit << endl;
	cout << "AGI: " << agi << endl;
	cout << "DEX: " << dex << endl;
}
