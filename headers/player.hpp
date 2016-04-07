#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <map>

using namespace std;

typedef std::pair<int, int> Move; 
typedef vector<Move > Ship; // Specifically moves which are contiguous along a single axis of length between 2 and 5.

class Player {
private:
protected:
	bool start; 		 		// Did this player start the game?
	int board_size, hitCount;	// What are the dimensions of the board? How many hits have I made so far?
	vector <Move > game; 		// sequence of moves so far
	map <Move, int> movesMade;	// sequence of moves so far
	vector <Ship > ships;		// My set of ships
	int* hits;
public:
	Player(bool start, int size) 
	{
		this->start = start;
		board_size = size;
		hitCount = 0;
		hits = new int[board_size * board_size];
		for (int i = 0; i < board_size * board_size; i++) 
		{
			hits[i] = 0;
		}
	}
	~Player() 
	{
		delete[] hits;
	}

	// This provides a way for the eventual analysis to know from this side where the hits were
	int addHit(Move m) 
	{
		hits[m.second + m.first * 10] = ++hitCount;
		return hits[m.second + m.first * 10];
	}

	//This function shouldn't need to be used by the main program but builds a ship according to the properties of the inheriting class
	virtual Ship buildShip(int size) = 0;

	//Currently, expect this to return a vector of 5 ships, of which:
	//   - one is of length 5 	(index 0)
	//	 - one is of length 4 	(index 1)
	//	 - one is of length 3 	(index 2)
	//	 - two are of length 2 	(indexes 3, 4)
	virtual vector<Ship > makeShips() = 0;	

	//Expect to return a move which has not been made by the player yet.
	virtual Move getMove(Move m) = 0;		
};

#endif