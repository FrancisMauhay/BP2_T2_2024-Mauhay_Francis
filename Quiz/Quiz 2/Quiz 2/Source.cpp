#include <iostream>
#include "Node.h"

using namespace std;

Node* Register(int soldiers)
{
	string name;
	Node* head = nullptr;
	Node* current = nullptr;

	for (int i = 0; i < soldiers; i++)
	{
		cout << "What is your name Soldier: ";
		cin >> name;

		Node* next = new Node;
		next->name = name;

		if (head == nullptr)
		{
			head = next;
			current = next;
			next->next = head;
		}
		else
		{
			next->next = current->next;
			current->next = next;
			current = next;
		}
	}

	return head;
}


Node* Cycle(int& soldiers, Node* head)
{
	if (head == nullptr)
	{
		cout << "Error: The list is empty!" << endl;
		return nullptr;
	}

	Node* curSol = head;
	for (int i = 0; i < rand() % soldiers + 1; i++)
	{
		curSol = curSol->next;
	}
	return curSol;
}

Node* Remove(Node*& head, int& soldiers)
{
	if (head == nullptr)
	{
		cout << "The list is empty!" << endl;
		return nullptr;
	}

	Node* current = head;
	Node* previous = nullptr;
	int steps = rand() % (soldiers - 1) + 1; 
	for (int i = 0; i < steps; i++)
	{
		previous = current;
		current = current->next;
	}

	cout << head->name << " has drawn " << steps << endl;

	if (current == head) 
	{
		if (head->next == head) 
		{
			cout << head->name << " has been eliminated" << endl;
			delete head;
			head = nullptr;
		}
		else 
		{
			previous->next = head->next; 
			head = head->next; 
			cout << current->name << " has been eliminated" << endl;
			delete current; 
		}
	}
	else 
	{
		previous->next = current->next; 
		cout << current->name << " has been eliminated" << endl;
		delete current; 
	}

	soldiers--; 
	return head;
}



void Print(Node* head)
{
	if (head == nullptr)
	{
		cout << "The list is empty!" << endl;
		return;
	}

	Node* current = head;
	do
	{
		cout << "    " << current->name << endl;
		current = current->next;
	} while (current != head);
}

int main()
{
	Node* head = nullptr;
	Node* next = nullptr;
	Node* current = nullptr;

	int round = 0;
	int soldiers = 0;

	cout << "How many soldiers do we need: ";
	cin >> soldiers;

	if (soldiers < 1)
	{
		cout << "Request for more backup" << endl;
		
		system("pause");
		return soldiers;
	}
	else
	{
		head = Register(soldiers);
	}

	while (soldiers > 1)
	{
		round++;

		cout << "=================================================================" << endl;
		cout << "ROUND " << round << endl;
		cout << "=================================================================" << endl;
		
		Print(head);
		Remove(head, soldiers);

		system("pause");
		head = Cycle(soldiers, head);


		if (soldiers <= 1)
		{
			cout << "=================================================================" << endl;
			cout << "FINAL RESULT" << endl;
			cout << "=================================================================" << endl;

			cout << head->name << " will go seek for reinforcements... " << endl;

			system("pause");
			return 0;
		}
	}

}