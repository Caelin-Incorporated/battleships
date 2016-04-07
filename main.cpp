#include <iostream>
#include "headers/random.hpp"
//#include "headers/fixed.hpp"
//#include "headers/human.hpp"
//#include "headers/neural.hpp"

#define boardsize 10
#define numPlayers 2

using namespace std;

bool *toBoardformat(vector<Ship > ships) 
{
	//TODO: assuming 'ships' is valid, make a corresponding array of bools
}

bool hasWinner(bool **board) 
{
	bool winner;
	bool miss;
	for (int i = 0; i < numPlayers; ++i) 
	{
		winner = true;
	  	for (int j = 0; j < boardsize * boardsize; ++j) 
	  	{
	    	miss = board[i][j] && !board[i + numPlayers][j];
	    	winner = !miss && winner;
	  	}
	  	if (winner) return true;
	}
	return false;
}

int main(int argc, char ** argv)
{
	cout << "Hello World!" << endl;

	//call the constructors for Random, first argument says who starts and second is board size
	Player *player1 = new Random(true, 10);
	Player *player2 = new Random(false, 10);

	// Create 2D array of pointers tracking 4 "boards" - two for each player. The first is their ships, the second their :
	bool** board = new bool*[2 * numPlayers];
	for (int i = 0; i < 2 * numPlayers; ++i) 
	{
	  	board[i] = new bool[boardsize * boardsize];
	}

	for (int i = 0; i < 2 * numPlayers; ++i) 
	{
	  	for (int j = 0; j < boardsize * boardsize; ++j) 
	  	{
	    	board[i][j] = false;
	  	}
	}

	board[0] = toBoardformat(player1->makeShips());
	board[1] = toBoardformat(player2->makeShips());

	while (!hasWinner(board)) 
	{

	}

	delete player1;
	delete player2;
	return 0;
}
