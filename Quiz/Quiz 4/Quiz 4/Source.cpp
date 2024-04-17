#include <iostream>
#include <string>
#include <algorithm>
#include "Character.h"
#include "Team.h"
#include "MTS.h"
#include "STS.h"
#include "Heal.h"
#include "TurnOrder.h"

using namespace std;

int main()
{
	srand(time(0));

	Character* etc = new ETC();
	Character* illidan = new Illidan();
	Character* lili = new LiLi();

	vector<Character*> warcraftCharacters = { etc, illidan , lili };

	Character* johanna = new Johanna();
	Character* valla = new Valla();
	Character* kharazim = new Kharazim();

	vector<Character*> diabloCharacters = { johanna, valla , kharazim };

	Team warcraft("Warcraft", warcraftCharacters);
	Team diablo("Diablo", diabloCharacters);

	vector<Character*> allCharacters;
	allCharacters.reserve(warcraft.getCharacters().size() + diablo.getCharacters().size());

	for (Character* character : warcraft.getCharacters()) {
		allCharacters.push_back(character);
	}
	for (Character* character : diablo.getCharacters()) {
		allCharacters.push_back(character);
	}

	sort(allCharacters.begin(), allCharacters.end(), [](Character* a, Character* b)
		{return a->getAgility() > b->getAgility();
		});

	TurnOrder turnOrder;

	for (Character* character : warcraft.getCharacters())
	{
		turnOrder.addCharacter(character, warcraft.getName());
	}

	for (Character* character : diablo.getCharacters())
	{
		turnOrder.addCharacter(character, diablo.getName());
	}


	while (!warcraft.isTeamDepleted() && !diablo.isTeamDepleted())
	{
		cout << "=====================================================================" << endl;
		cout << "Team: Warcraft " << endl;
		cout << "=====================================================================" << endl;

		warcraft.printTeamMembers();

		cout << "=====================================================================" << endl;
		cout << "Team: Diablo " << endl;
		cout << "=====================================================================" << endl;

		diablo.printTeamMembers();
		
		turnOrder.displayAllCharacters();

		string currentCharacter = turnOrder.getCurrentCharacter();
		cout << "Current Turn: " << currentCharacter << endl;

		system("pause");
		system("cls");

		if (currentCharacter.find("Warcraft") != string::npos)
		{
			Character* currentCharacterObj = warcraft.getCharacterByName(currentCharacter);
			if (currentCharacterObj != nullptr)
			{
				int choice;
				int randTgt = rand() % diabloCharacters.size();
				int randTgtHeal = rand() % warcraftCharacters.size();
				vector<Character*> targetVector = { diabloCharacters[randTgt] };
				vector<Character*> targetVectorHeal = { warcraftCharacters[randTgtHeal] };

				currentCharacterObj->DisplayStats();

				cin >> choice;

				switch (choice)
				{
				case 1:
					currentCharacterObj->Attack(targetVector);
					break;
				case 2:
					if (currentCharacterObj == etc)
					{
						currentCharacterObj->mp -= 4;
						currentCharacterObj->SpecialAbility(diabloCharacters);
					}
					else if (currentCharacterObj == lili)
					{
						currentCharacterObj->mp -= 3;
						currentCharacterObj->SpecialAbility(targetVectorHeal);
					}
					else
					{
						currentCharacterObj->mp -= 5;
						currentCharacterObj->SpecialAbility(targetVector);
					}
					break;
				default:
					cout << " ERROR" << endl;
					break;
				}

				system("pause");
				system("CLS");
			}
		}
		else if (currentCharacter.find("Diablo") != string::npos)
		{

			Character* currentCharacterObj = diablo.getCharacterByName(currentCharacter);
			if (currentCharacterObj != nullptr)
			{
				int randchoice = (rand() % 2) + 1;
				int randTgt = rand() % warcraftCharacters.size();
				int randTgtHeal = rand() % diabloCharacters.size();
				vector<Character*> targetVector = { warcraftCharacters[randTgt] };
				vector<Character*> targetVectorHeal = { diabloCharacters[randTgtHeal] };
				
				switch (randchoice)
				{
				case 1:
					currentCharacterObj->Attack(targetVector);
					break;
				case 2:
					if (currentCharacterObj == johanna)
					{
						currentCharacterObj->mp -= 4;
						currentCharacterObj->SpecialAbility(warcraftCharacters);
					}
					else if (currentCharacterObj == kharazim)
					{
						currentCharacterObj->mp -= 3;
						currentCharacterObj->SpecialAbility(targetVectorHeal);
					}
					else
					{
						currentCharacterObj->mp -= 5;
						currentCharacterObj->SpecialAbility(targetVector);
					}
					break;
				default:
					cout << " ERROR" << endl;
					break;
				}

				system("pause");
				system("CLS");
			}
		}

		turnOrder.nextTurn();
	}

	delete etc;
	delete illidan;
	delete lili;
	delete johanna;
	delete valla;
	delete kharazim;

	return 0;
}