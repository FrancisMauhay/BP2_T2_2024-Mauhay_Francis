#pragma once
#include<iostream>
#include<string>

using namespace std;

class Enemy;

class Player
{
	public:
		string name;
		string pc;
		int hp;
		int pow;
		int vit;
		int agi;
		int dex;

	Player(const string _name, string _pc,int _hp,int _pow, int _vit, int _agi,int _dex)
		:name(_name), pc(_pc), hp(_hp), pow(_pow), vit(_vit), agi(_agi), dex(_dex) {}

	virtual void Attack(Enemy* who);

	virtual void DisplayStats() = 0;

	virtual ~Player() {}
};

