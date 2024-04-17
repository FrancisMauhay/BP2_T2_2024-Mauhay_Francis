#pragma once

#include <string>
#include <vector>
#include "Character.h"

using namespace std;

class Team
{
public:
    string name;
    vector<Character*> characters; 
    Team(const string& name, const vector<Character*>& characters); 

    void printTeamMembers() const; 
    bool isTeamDepleted() const;
    vector<Character*> getCharacters() const {
        return characters;
    }
    string getName() const;

    Character* getCharacterByName(const string& characterName) const;
};


