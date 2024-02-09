#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

//ok
void slvDeck(vector<string>& pDeck, vector<string>& aiDeck)
{
	pDeck.push_back("Slave Card");
	for (int s = 0; s < 4; s++)
	{
		pDeck.push_back("Civilian Card");
	}

	aiDeck.push_back("Emperor Card");
	for (int i = 0; i < 4; i++)
	{
		aiDeck.push_back("Civilian Card");
	}
}

//ok
void empDeck(vector<string>& pDeck, vector<string>& aiDeck)
{
	pDeck.push_back("Emperor Card");
	for (int s = 0; s < 4; s++)
	{
		pDeck.push_back("Civilian Card");
	}

	aiDeck.push_back("Slave Card");
	for (int i = 0; i < 4; i++)
	{
		aiDeck.push_back("Civilian Card");
	}
}

//ok
void DeckBuild(vector<string>& pDeck, vector<string>& aiDeck, int& round)
{
	pDeck.clear();
	aiDeck.clear();

	if (round <= 3 || round > 6 && round <= 9)
	{
		empDeck(pDeck, aiDeck);
	}
	else
	{
		slvDeck(pDeck, aiDeck);
	}

}

void remove(vector<string>& pDeck, int choice)
{
	pDeck.erase(pDeck.begin() + choice);
}

//ok
void print(vector<string>& pDeck)
{
	for (int i = 0; i < pDeck.size(); i++)
	{
		cout << pDeck[i] << endl;
	}
}

// needs some tweaking
void wager(int& mmLeft, int& bet)
{
	while (true) {
		cout << "How much mm do you want to wager: ";
		cin >> bet;

		if (bet < 1) {
			cout << "Sorry, you must wager an amount..." << endl;
		}
		else if (bet > mmLeft) {
			cout << "Sorry, you don't have that much to wager..." << endl;
		}
		else {
			cout << "Bet Accepted: " << bet << endl << endl;
			mmLeft -= bet;
			break;
		}
	}
}

// ok
string playerTurn(vector<string>& pDeck)
{
	int choice;
	string card;
	cout << "Play a card: " << endl;
	cout << "1 - " << pDeck.size() << endl;
	cin >> choice;

	while (choice<1 || choice>pDeck.size())
	{
		cout << "ERROR" << endl << endl;
		cout << "Play a card: " << endl;
		cout << "1 - " << pDeck.size() << endl << endl;
		cin >> choice;
	}
	choice -= 1;
	card = pDeck[choice];
	cout << "Player Move: " << card << endl;
	remove(pDeck, choice);

	return card;
}

//ok
string aiTurn(vector<string>& aiDeck)
{
	int aiChoice = rand() % aiDeck.size();
	string card = aiDeck[aiChoice];

	cout << "Enemy Move: " << card << endl;

	remove(aiDeck, aiChoice);

	return card;
}

//ok
void ending(int round, int& mmLeft, int& moneyEarned)
{
	if (round >= 12 && moneyEarned >= 20000000)
	{
		cout << "You Survived and won a lot of money!! LETS GO!!!!" << endl;
	}
	else if (round >= 12 && moneyEarned < 20000000)
	{
		cout << "You Survived, but at what cost..." << endl;
	}
	else if (mmLeft <= 0)
	{
		cout << "Goodbye..." << endl;
	}
}

// ok
void playRound(int round, int& mmLeft, int& moneyEarned, int& bet, int prize, vector<string>& pDeck, vector<string>& aiDeck)
{
	bool continueRound = true;
	string player, ai;

	cout << "Round: " << round << endl;
	cout << "You have " << mmLeft << " mm Left." << endl;
	cout << "Money Earned: " << moneyEarned << endl << endl;

	wager(mmLeft, bet);
	DeckBuild(pDeck, aiDeck, round);

	while (continueRound) {
		print(pDeck);
		player = playerTurn(pDeck);
		ai = aiTurn(aiDeck);

		if (ai == "Emperor Card" && player == "Slave Card")
		{
			prize = bet * 500000;
			cout << "You win!! Collect your Prize!!" << endl;
			cout << "Prize: " << prize << endl;

			mmLeft += bet;
			moneyEarned += prize;
			continueRound = false;
		}
		else if (ai == "Slave Card" && player == "Civilian Card")
		{
			prize = bet * 100000;
			cout << "You win!! Collect your Prize!!" << endl;
			cout << "Prize: " << prize << endl;

			mmLeft += bet;
			moneyEarned += prize;
			continueRound = false;
		}
		else if (ai == "Civilian Card" && player == "Emperor Card")
		{
			prize = bet * 100000;
			cout << "You win!! Collect your Prize!!" << endl;
			cout << "Prize: " << prize << endl;

			mmLeft += bet;
			moneyEarned += prize;
			continueRound = false;
		}
		else if (ai == player)
		{
			cout << "Draw" << endl;
		}
		else
		{
			cout << "You lose this bet..." << endl;
			continueRound = false;
		}
	}

	system("pause");
	system("CLS");

	ending(round, mmLeft, moneyEarned);
}

int main()
{
	srand(time(0));

	int round = 1;
	int mmLeft = 30;
	int moneyEarned = 0;
	int bet = 0;
	int prize = 0;
	vector<string> pDeck;
	vector<string> aiDeck;

	while (round <= 12 || mmLeft > 0)
	{
		playRound(round, mmLeft, moneyEarned, bet, prize, pDeck, aiDeck);

		round++;

		if (round > 12 || mmLeft <= 0)
		{
			break;
		}
	}

	cout << endl;

	return 0;
}