#include "Team.h"

Team::Team(const string& name, const vector<Character*>& characters)
    : name(name), characters(characters) {}

void Team::printTeamMembers() const
{
    for (const Character* character : this->characters) { 
        if (character->hp <= 0)
        {
            cout << character->name << " [DEAD]" << endl;
        }
        else if (character->hp > 0)
        {
            cout << character->name << " [HP: " << character->hp << "]" << endl;
        }
    }
    cout << endl;
}

bool Team::isTeamDepleted() const {
    for (const Character* character : characters) {
        if (character->isAlive()) {
            return false;
        }
    }
    return true;
}

string Team::getName() const {
    return name;
}

Character* Team::getCharacterByName(const string& characterName) const {
    size_t startPos = characterName.find(']');
    if (startPos != string::npos) {
        string nameWithoutTeam = characterName.substr(startPos + 2);
        for (Character* character : characters) {
            if (character->name == nameWithoutTeam) {
                return character;
            }
        }
    }
    return nullptr;
}


