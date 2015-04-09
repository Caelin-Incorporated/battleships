#include "ShipSpr.hpp"
using namespace std;

bool ShipSpr::setTexture(string texture){
	if(sTex.loadFromFile(texture) == false){
		return false;
	}
	sSpr.setTexture(sTex);
	sf::Vector2u s = sSpr.getTexture()->getSize();
	sSpr.setOrigin(s.x/2.0, s.y/2.0);
	return true;
}

void ShipSpr::updatePos(float x, float y, float angle){
	sSpr.setPosition(x,y);
	sSpr.setRotation(angle);
}

void ShipSpr::draw(sf::RenderWindow &screen){
	screen.draw(sSpr);
}
