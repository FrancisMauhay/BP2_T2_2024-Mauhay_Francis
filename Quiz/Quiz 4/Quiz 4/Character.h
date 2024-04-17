#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Character
{
public:
	string name;
	string attackName;
	string ability;
	int hp;
	int mp;
	int pow;
	int vit;
	int agi;
	int dex;

	Character(const string _name, const string _attackName, const string _ability, int _hp, int _mp, int _pow, int _vit, int _agi, int _dex)
		:name(_name), attackName(_attackName), ability(_ability), hp(_hp), mp(_mp), pow(_pow), vit (_vit), agi ( _agi), dex ( _dex) {}
	
	virtual void Attack(const vector<Character*>& who);

	virtual void SpecialAbility(const vector<Character*>& who) = 0;

	virtual void DisplayStats() = 0;

	virtual int getAgility() const = 0;

	bool isAlive() const;

	virtual ~Character() {}

};

