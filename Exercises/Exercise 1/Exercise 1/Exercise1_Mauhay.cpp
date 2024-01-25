#include <iostream>
#include <ctime>

using namespace std;

//EX 1-1

void bet(int& gold, int stakes)
{
    gold -= stakes;
}

int Bet(int& gold, int stakes)
{
    gold -= stakes;

    return (gold - stakes);
    
}

// EX 1-2
void diceRoll(int dice[])
{
    cout << "Are you ready to roll?" << endl;
    system("pause");
    system("cls");

    for (int i = 0; i < 4; i++)
    {
        dice[i] = rand() % 1 + 1;
    }
    cout << "Dice 1: " << dice[0] << endl;
    cout << "Dice 2: " << dice[1] << endl << endl;

    cout << "Opponent will roll now" << endl;
    system("pause");

    cout << "Dice 1: " << dice[2] << endl;
    cout << "Dice 2: " << dice[3] << endl;
    
    

}

// EX 1-3
int payout(int& gold, int dice[], int stakes)
{
    if (dice[0] + dice[1] > dice[2] + dice[3])
    {
        stakes *= 2;
        cout << "You win: " << stakes << endl << endl;
        system("pause");
        system("CLS");
        
        gold += stakes;
    }
    else if (dice[0] && dice[1] == 1)
    {
        stakes *= 3;
        cout << "Snake Eyes!! You win:  " << stakes << endl << endl;
        system("pause");
        system("CLS");

        gold += stakes;
    }
    else if (dice[0]+dice[1]<dice[2]+dice[3])
    {
        cout << "YOU LOSE HAHA" << endl;
        system("pause");
        system("CLS");
    }
    else
    {
        cout << "DRAW" << endl;

        gold += stakes;
    }

    return 0;
}

// EX 1-4
void playRound(int& gold, int stakes, int dice[])
{
  cout << "Gold: " << gold << endl;
  cout << "Place your bets: " << endl;
  cin >> stakes;
  cout << endl;

  if (stakes > gold || stakes < 0)
  {
      cout << "ERROR" << endl;
      system("pause");
      system("CLS");
      return;
  }
  else
  {
      system("CLS");
  }


  Bet(gold, stakes);

  cout << "Gold left: " << gold << endl;
  cout << "You bet: " << stakes << endl;


  diceRoll(dice);
  payout(gold, dice, stakes);

}

int main()
{
    srand(time(0));

    int gold = 1000;
    int stakes = 0;
    int dice[4];

    while (gold > 0)
    {
        playRound(gold, stakes, dice);
    }
    cout << "GG you're in debt now" << endl;
    return 0;

}