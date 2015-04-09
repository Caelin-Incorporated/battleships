#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <SFML/Graphics.hpp>
#include "ShipSpr.hpp"
#include "../logic/logic.hpp"

class Board {
	private:
		Sea sea;
		ShipSpr ship_spr;
	public:
		void init();
		void update(float dt);
		void draw(sf::RenderWindow &screen);
};

#endif
