#include "TurnOrder.h"

int TurnOrder::turnCounter = 1;


TurnOrder::TurnOrder()
    : current(nullptr) {}

TurnOrder::~TurnOrder()
{
    Node* temp = current;
    if (temp != nullptr) {
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != current);
    }
}

void TurnOrder::addCharacter(Character* character, const string& team)
{
    Node* newNode = new Node(character, team);
    if (current == nullptr) {
        current = newNode;
        current->next = current;
    }
    else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void TurnOrder::nextTurn()
{
    if (current != nullptr) {
        current = current->next;
    }
}


void TurnOrder::removeDefeated(Character* who)
{
    if (current != nullptr) {
        Node* prev = current;
        while (prev->next != current) {
            if (prev->next->character == who) {
                Node* temp = prev->next;
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = prev->next;
        }
        if (prev->next->character == who) {
            Node* temp = prev->next;
            prev->next = prev->next->next;
            delete temp;
            if (current->character == who) {
                current = prev->next;
            }
        }
    }
}

void TurnOrder::displayAllCharacters() const {
    Node* temp = current;
    int turnNumber = 1;
    cout << "=========== TURN ORDER ===========" << endl;
    do {
        cout << "#" << turnNumber++ << " [" << temp->team << "] " << temp->character->name << endl;
        temp = temp->next;
    } while (temp != current);
    cout << "=========== TURN ORDER ===========" << endl;
}


string TurnOrder::getCurrentCharacter() const
{
    if (current != nullptr) {
        return " [" + current->team + "] " + current->character->name;
    }
    return "";
}
