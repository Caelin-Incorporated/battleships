#include "Board.hpp"

void Board::init(){
	ship_spr.setTexture("./data/textures/ship.png");

	Ship s(0, 10, 10); // TODO add sea add ship function
	sea.ships.push_back(s);
}

void Board::update(float dt){
	float angle = sea.ships[0].getRot();
	sea.ships[0].updateHitboxes(100,100,angle+90*dt);
}

void Board::draw(sf::RenderWindow &screen){
	for(Ship &s : sea.ships){
		vec2 pos = s.getPos();
		ship_spr.updatePos(pos.x, pos.y, s.getRot());
		ship_spr.draw(screen);
	}
}
