#ifndef __RANDOM_H__
#define __RANDOM_H__

#include "player.hpp"
#include <stdlib.h>
#include <time.h>

using namespace std;

class Random : public Player 
{
private:
protected:
	int index;
	vector <Move > moves;
public:
	Random(bool starts, int size);
	~Random();
	
	//This function shouldn't need to be used by the main program but builds a ship according to the properties of the inheriting class
	Ship buildShip(int size);

	//Currently, expect this to return a vector of 5 ships, of which:
	//   - one is of length 5 	(index 0)
	//	 - one is of length 4 	(index 1)
	//	 - one is of length 3 	(index 2)
	//	 - two are of length 2 	(indexes 3, 4)
	vector<Ship > makeShips();	

	//Expect to return a move which has not been made by the player yet.
	Move getMove(Move m);
};

#endif