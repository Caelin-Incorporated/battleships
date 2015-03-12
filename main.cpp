#include <iostream>
#include "graphics/Game.hpp"
using namespace std;

int main(){
	cout << "Hello World!" << endl;
	Game game;
	game.init();
	return game.run();
}
