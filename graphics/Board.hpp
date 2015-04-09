#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <SFML/Graphics.hpp>
#include "ShipSpr.hpp"
#include "State.hpp"
#include "../logic/logic.hpp"

class Board {
	private:
		Sea sea;
		ShipSpr ship_spr;
		sf::Sprite water_spr;
		sf::Texture water_tex;
		sf::IntRect water_box;
		float water_time;
		int water_frame;
	public:
		void init();
		GameState update(float dt);
		void draw(sf::RenderWindow &screen);
};

#endif
