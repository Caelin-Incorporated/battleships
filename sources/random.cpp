#include "../headers/random.hpp"

Random::Random(bool starts, int size) : Player(starts, size) 
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++) 
	{
		moves.push_back(make_pair(rand() % board_size, rand() % board_size));
	}
}

Ship Random::buildShip(int size) 
{
	//TODO: build a random ship conforming to ship restrictions
}

vector<Ship > Random::makeShips() 
{
	Ship ship1, ship2, ship3, ship4, ship5;

	ship1 = buildShip(5);
	ships.push_back(ship1);

	ship2 = buildShip(4);
	ships.push_back(ship2);

	ship3 = buildShip(3);
	ships.push_back(ship3);

	ship4 = buildShip(2);
	ships.push_back(ship4);

	ship5 = buildShip(2);
	ships.push_back(ship5);

	return ships;
}


Move Random::getMove(Move m) 
{
	game.push_back(m);
	Move next;
	do 
	{
		if ((index % 100) == 99) 
		{
			srand(time(NULL));
			for (int i = 0; i < 100; i++) 
			{
				moves.push_back(make_pair(rand() % board_size, rand() % board_size));
			}
		}

		next = moves[index];
		index++;
	} while (movesMade.find(next) != movesMade.end());

	movesMade[next] = (index - 1);

	return next;	
}