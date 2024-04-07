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
    srand(time(0));

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

                if (player->agi >= enemy->agi)
                {
                    cout << "Player will attack now..." << endl << endl;
                    system("pause");

                    player->Attack(enemy);

                    system("pause");

                    cout << endl << "Enemy will attack now..." << endl << endl;

                    enemy->AttackPlayer(player);

                    system("pause");
                    system("CLS");
                }
                else if( player->agi <= enemy->agi)
                {
                    cout << "Enemy will attack now..." << endl << endl;
                    system("pause");

                    enemy->AttackPlayer(player);

                    cout << "Player will attack now..." << endl << endl;

                    player->Attack(enemy);

                    system("pause");
                    system("CLS");
                }
            }
            if (enemy->hp <= 0)
            {
                if (dynamic_cast<WarriorEnemy*>(enemy))
                {   
                    player->hp += 30;
                    if (player->hp > 100)
                    {
                        player->hp = 100;
                    }

                    player->pow += 3;
                    player->vit += 3;

                    enemy = nullptr;
                }
                else if (dynamic_cast<AssassinEnemy*>(enemy))
                {
                    player->hp += 30;
                    if (player->hp > 100)
                    {
                        player->hp = 100;
                    }

                    player->agi += 3;
                    player->dex += 3;

                    enemy = nullptr;
                }
                else if (dynamic_cast<MageEnemy*>(enemy))
                {
                    player->hp += 30;
                    if (player->hp > 100)
                    {
                        player->hp = 100;
                    }

                    player->pow += 5;

                    enemy = nullptr;
                }
                else
                {
                    enemy = nullptr;
                }
            }
        }
    }

    cout << "==================GAME OVER====================" << endl;
    cout << "You only reached floor " << floor << endl;

    delete player;
    delete enemy;

    return 0;
}
