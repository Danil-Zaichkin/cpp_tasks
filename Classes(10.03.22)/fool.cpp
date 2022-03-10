#include <iostream>
#include <vector>

using namespace std;

struct Card {
public:
	Card(int suit, int value):
		suit(suit),
		value(value)
	{}

private:
	int suit;
	int value;
};

class Bank {
	vector <Card> bank;
	Bank() {}

public:
	Card take() {
		Card card = bank.front();
		bank.erase(bank.begin());
		return card;
	}
};

class Player {
	
	Player(Bank bank) {
		for (int i = 0; i < 6; i++) {
			hand.push_back(bank.take());
		}
	}
public:
	vector <Card> hand;
};

class Game {
	Game() {};

	void round(Player attak, Player defense) {};
};
