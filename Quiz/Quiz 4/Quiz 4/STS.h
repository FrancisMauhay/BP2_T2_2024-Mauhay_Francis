#pragma once
#include "Character.h"
#include <string>
class Illidan : public Character{
public:
	Illidan()
		: Character("Illidan", "Attack", "The Hunt", 30, 17, 14, 5, 12, 5){}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};

class Valla : public Character {
public:
	Valla()
		: Character("Valla", "Attack", "Puncturing Arrow", 30, 17, 14, 5, 12, 5) {}

	void SpecialAbility(const vector<Character*>& who) override;
	void DisplayStats() override;

	int getAgility() const override {
		return agi;
	}
};