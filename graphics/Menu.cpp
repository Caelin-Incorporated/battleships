#include "Menu.hpp"
#include <iostream>

using namespace::std;


bool Menu::setStart(string texture){
	if(startTex.loadFromFile(texture) == false){
		return false;
	}
	start.setTexture(startTex);
	sf::Vector2u s = start.getTexture()->getSize();
	start.setOrigin(s.x/2.0, s.y/2.0);
	return true;
}

bool Menu::setQuit(string texture){
	if(quitTex.loadFromFile(texture) == false){
		return false;
	}
	quit.setTexture(quitTex);
	sf::Vector2u s = quit.getTexture()->getSize();
	quit.setOrigin(s.x/2.0, s.y/2.0);
	return true;
}

void Menu::drawMenu() {

}



Menu::Menu() {
    if (!setStart("./data/textures/start.png")) {
        cout << "Error: couldn't find start button\n";
    }
    if (!setQuit("./data/textures/quit.png")) {
        cout << "Error: couldn't find quit button\n";
    }
}
