#pragma once
#include "Character.h"
#include <string>

class ETC : public Character {
public:
	ETC()
		: Character("E.T.C", "Axe Smash", "Face Melt",45,15,10,2,10,6){}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};

class Johanna : public Character {

	static Johanna* instance;

public:
	Johanna()
		: Character("Johanna","Piercing slash","Falling Sword",45,15,10,2,10,6){}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};

