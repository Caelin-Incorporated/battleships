#ifndef SHIPSPR_HPP_
#define SHIPSPR_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>

class ShipSpr {
	private:
		sf::Sprite sSpr;
		sf::Texture sTex;
	public:
		bool setTexture(std::string texture);
		void updatePos(float x, float y, float angle);
		void draw(sf::RenderWindow &screen);
};

#endif
