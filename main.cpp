#include <iostream>
#include "graphics/Game.hpp"
using namespace std;

int main(){
	cout << "Hello World!" << endl;
	Game mainFrame;
	mainFrame.init();
	return mainFrame.run();
}
