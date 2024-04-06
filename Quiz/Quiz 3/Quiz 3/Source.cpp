#include <iostream>
#include <string>
#include "Warrior.h"
#include "Assassin.h"
#include "Mage.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
    Player* player = nullptr;
    Enemy* enemy = nullptr;

    string _name;
    int floor = 0;
    int classNum;
    int enemyNum;

    cout << "Input player name: ";
    cin >> _name;

    cout << "Choose a class: " << endl;
    cout << "1: Warrior" << endl;
    cout << "2: Assassin" << endl;
    cout << "3: Mage" << endl;

    cin >> classNum;

    switch (classNum)
    {
    case 1:
        player = new WarriorPlayer(_name);
        break;
    case 2:
        player = new AssassinPlayer(_name);
        break;
    case 3:
        player = new MagePlayer(_name);
        break;
    default:
        cout << "Invalid class number. Please choose again." << endl;
        return 1;
    }
    while (player->hp > 0)
    {
        if (enemy == nullptr)
        {
            enemyNum = (rand() % 3) + 1;
            switch (enemyNum)
            {
            case 1:
                enemy = new WarriorEnemy("Geralt");
                break;
            case 2:
                enemy = new AssassinEnemy("Akali");
                break;
            case 3:
                enemy = new MageEnemy("Freiren");
                break;
            default:
                break;
            }
            floor++;
        }
        else
        {
            while (enemy->hp > 0)
            {
                player->DisplayStats();
                enemy->DisplayStats();

                cout << endl << "Floor: " << floor << endl;

                // Insert battle functions here

                enemy->hp -= 10;

                system("pause");
                system("CLS");
            }
            if (enemy->hp <= 0)
            {
                enemy = nullptr;
            }
        }
    }

    cout << "==================GAME OVER====================" << endl;
    cout << "You only reached floor " << floor << endl;

    // Clean up allocated memory
    delete player;
    delete enemy;

    return 0;
}
