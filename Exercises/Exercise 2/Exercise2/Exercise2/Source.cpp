#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;

string Items[4] = { "Red Potion", "Elixir", "Empty Bottle", "Blue Potion" };

// Ex 2-1

void InventoryFill(vector<string>& items)
{
	for (int i = 0; i < 10; i++)
	{
		items.push_back(Items[rand() % 4]);
	}

}

// Ex 2-2		

void DisplayInventory(const vector<string> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		cout << items[i] << endl;
	}
}

// Ex 2-3

void Count(const vector<string>& items)
{
	int ItemCount[4] = { 0,0,0,0 };
	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (items[i] == Items[j])
			{
				ItemCount[j] += 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		cout << Items[i] << ": " << ItemCount[i] << endl;
	}
}

// Ex 2-4

void Remove(vector<string>& items)
{
	string removed = "Empty Bottle";
	for (int i = items.size()-1; i >= 0; i--)
	{
		if (items[i] == "Empty Bottle")
		{
			items.erase(items.begin() + i);
		}
	}

	cout << "Some items were removed, here's a new list: " << endl << endl;
	DisplayInventory(items);
}


// Main

int main()
{
	srand(time(NULL));

	vector<string>items;

	InventoryFill(items);

	cout << "Inventory: " << endl << endl;;

	DisplayInventory(items);

	cout << endl <<  "Amount per Item: " << endl;

	Count(items);
	Remove(items);

	return 0;
}