#pragma once
#include<iostream>
#include<string>

using namespace std;

class Wizard;

class Spell
{
public:
	string spellname;
	int minDmg;
	int maxDmg;
	int MpCost;

	Spell(string _spell, int _min, int _max, int _cost)
	{
		spellname = _spell;
		minDmg = _min;
		maxDmg = _max;
		MpCost = _cost;
	}

	void Activate(Wizard* caster, Wizard* target);
};

