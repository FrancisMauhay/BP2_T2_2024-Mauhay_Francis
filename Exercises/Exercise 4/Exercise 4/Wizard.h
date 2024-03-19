#pragma once
#include <iostream>
#include <string>

using namespace std;

class Spell;

class Wizard
{
	public:
		string name;
		string title;
		int hp = 250;
		int mp = 0;
		int minAtk = 10;
		int maxAtk = 15;

	Wizard(string _name, string _title)
	{
		name = _name;
		title = _title;

		cout << "I am " << this->name << " the " << this->title << ". I am a wizard" << endl;
	}
	
	void Attack(Wizard* who);
};

