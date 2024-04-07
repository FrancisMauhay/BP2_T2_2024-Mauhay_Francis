#pragma once
#include<iostream>
#include<string>

using namespace std;

class Player;

class Enemy
{
public:
	string name;
	string ec;
	int hp;
	int pow;
	int vit;
	int agi;
	int dex;

	Enemy(const string _name, string _ec, int _hp, int _pow, int _vit, int _agi, int _dex)
		:name(_name), ec(_ec), hp(_hp), pow(_pow), vit(_vit), agi(_agi), dex(_dex) {}

	void AttackPlayer(Player* who);

	virtual void DisplayStats() = 0;

	virtual ~Enemy() {}
};
