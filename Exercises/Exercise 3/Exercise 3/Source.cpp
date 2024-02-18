#include <iostream>
#include <string>

using namespace std;

struct
{
	string name;
	int gold;
};

void Generate()
{

}

void EnterDungeon(int& gold)
{
	gold -= 25;

}

void Condition(int& gold)
{
	if (gold >= 500)
	{
		cout << "You have reached 500 gold!! you have cleared the dungeon :>" << endl;

	}
	else if (gold <= 0)
	{
		cout << "You Have Lost..." << endl;
	}
}

void Play(int& gold)
{
	while (gold > 0)
	{
		cout << "Remaining Gold: " << gold << endl;
		cout << "Do you want to enter the dungeon? " << endl << endl;

		system("pause");
		EnterDungeon(gold);
		Condition(gold);

		system("pause");
		system("CLS");
	}
}

int main()
{
	int gold = 50;

	Play(gold);
}