#pragma once
#include "Character.h"
#include <string>
class LiLi : public Character {
public:
	LiLi()
		: Character("LiLi", "Attack", "Jug of Life", 30, 18, 11, 6, 12, 2) {}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};

class Kharazim : public Character {
public:
	Kharazim()
		: Character("Kharazim", "Attack", "Divine Palm", 30, 18, 11, 6, 12, 2) {}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};

