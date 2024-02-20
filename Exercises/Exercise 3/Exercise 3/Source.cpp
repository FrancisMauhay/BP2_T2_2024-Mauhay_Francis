#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

// 3.1
struct Item
{
	string name;
	int gold;
};

void Generate(Item items[], int& gold, int& multiplier)
{
	int randomIndex = rand() % 5;

	cout << "Looting... " << endl << endl;

	system("pause");
	system("cls");

	Item* randomItem = &items[randomIndex];

	if (items[randomIndex].name == "Cursed Stone")
	{
		cout << "Oh no, you are being drained by the Cursed Stone..." << endl;
		cout << "You gain 0 Gold" << endl;

		multiplier = 0;

		system("pause");
		system("cls");
	}
	else
	{
		cout << "You looted " << randomItem->name << ", You gain " << randomItem->gold << " gold multiplied by " << multiplier << endl;

		system("pause");
		system("cls");

		gold += randomItem->gold * multiplier;
	}

}

// 3.2 
void EnterDungeon(Item items[], int& gold, int& multiplier)
{
	gold -= 25;
	
	Generate(items, gold, multiplier);

}

// 3.3
void Condition(int& gold)
{
	if (gold >= 500)
	{
		cout << "You have reached 500 gold!! you have cleared the dungeon :>" << endl;
		
		system("pause");
		exit;
	}
	else if (gold < 25 )
	{
		cout << "You Have Lost..." << endl;

		system("pause");
		exit;
	}
}

void Play(Item items[] , int& gold, int choice, int& multiplier)
{
	cout << "Gold: " << gold << endl;
	cout << "Multiplier: " << multiplier << endl;
	cout << "Entering the Dungeon... " << endl << endl;
	
	system("Pause");
	system("CLS");

	EnterDungeon(items, gold, multiplier);
	multiplier++;

	while (gold > 0 && gold < 500)
	{
		cout << "Remaining Gold: " << gold << endl;
		cout << "Multiplier: " << multiplier << endl;
		cout << "Do you want to enter the dungeon again? " << endl << endl;
		cout << "1 = Yes" << endl;
		cout << "2 = No" << endl << endl;
		cin >> choice;

		if (choice == 1 && gold >= 25)
		{
			system("cls");
			EnterDungeon(items, gold, multiplier);
			multiplier++;
		}
		else if (choice == 2)
		{
			cout << "How sad ..." << endl;
			multiplier = 1;
			system("pause");
			system("cls");
		}
		else if (gold < 25)
		{
			cout << "you don't have enough gold... your quest is over" << endl;
			break;
		}
		else
		{
			cout << "ERROR" << endl << endl;
			system("pause");
			system("cls");
		}
	}

	Condition(gold);
}

int main()
{
	srand(time(0));

	const int ItemAmount = 5;
	int choice = 0;
	int multiplier = 1;
	Item items[ItemAmount];

	items[0] = {"Mithril Ore" , 100};
	items[1] = {"Sharp Talon" , 50};
	items[2] = {"Thick Leather" , 25};
	items[3] = {"Jellopy" , 5};
	items[4] = {"Cursed Stone" , 0};

	int gold = 24;

	Play(items,gold,choice,multiplier);
}