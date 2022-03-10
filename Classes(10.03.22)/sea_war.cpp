#include <vector>

using namespace std;

class Cell {
	int x;
	int y;

	Cell(int x, int y, Ship* ship):
		x(x),
		y(y),
		ship(ship)
	{}

public:
	bool attacked = false;
	Ship* ship;
};

class Ship {
public:
	bool isdead = false;

	Ship(int health):
		health(health)
	{}

	void hit() {
		if (isdead = false)
			health--;
		if (health == 0)
			isdead = true;
	}

private:
	int health;
};	

class Player {
	vector <Ship> ship;

	Player() {
		int i = 0;
		for (int len = 1; len < 5; len++)
			for (int k = 1; k < 6 - len; k++, i++)
				ship.push_back(Ship(len));
	}
	
};

class Field {
	Cell field[10][10];
};
