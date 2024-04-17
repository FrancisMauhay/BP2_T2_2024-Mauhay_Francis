#pragma once

#include <string>
#include "Character.h"

using namespace std;

class TurnOrder {
public:
    struct Node {
        Character* character;
        string team;
        Node* next;

        Node(Character* _character, const string& _team) : character(_character), team(_team), next(nullptr) {}
    };

    Node* current;
    static int turnCounter; 

    TurnOrder();
    ~TurnOrder();

    void addCharacter(Character* character, const string& team);
    void nextTurn();
    void removeDefeated(Character* character);
    void displayAllCharacters() const;
    string getCurrentCharacter() const;
};




