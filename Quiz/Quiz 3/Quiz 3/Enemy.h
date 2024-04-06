#pragma once
#include<iostream>
#include<string>

using namespace std;

class Enemy
{
public:
	string name;
	int hp;
	int pow;
	int vit;
	int agi;
	int dex;

	Enemy(const string _name, int _hp, int _pow, int _vit, int _agi, int _dex)
		:name(_name), hp(_hp), pow(_pow), vit(_vit), agi(_agi), dex(_dex) {}

	virtual void DisplayStats() = 0;

	virtual ~Enemy() {}
};
