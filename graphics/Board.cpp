#include "Board.hpp"

#define WATER_X 9

void Board::init(){
	ship_spr.setTexture("./data/textures/ship.png");
	water_tex.loadFromFile("./data/textures/water.png");
	water_spr.setTexture(water_tex);

	water_box.width = 32;
	water_box.height = 32;
	water_box.top = 0;
	water_box.left = 0;
	water_time = 0;
	water_frame = 0;

	water_spr.setTextureRect(water_box);

	Ship s(0, 10, 10); // TODO add sea add ship function
	sea.ships.push_back(s);
}

void Board::update(float dt){
	float angle = sea.ships[0].getRot();
	sea.ships[0].updateHitboxes(100,100,angle+90*dt);
	if(water_time > 0.1){
		water_frame = (water_frame+1) % WATER_X;
		water_time = 0;
		water_box.left = water_frame*32;
		water_spr.setTextureRect(water_box);
	}
	water_time += dt;
}

void Board::draw(sf::RenderWindow &screen){
	for(int y=0; y<19; ++y){
		for(int x=0; x<25; ++x){
			water_spr.setPosition(x*32, y*32);
			screen.draw(water_spr);
		}
	}

	for(Ship &s : sea.ships){
		vec2 pos = s.getPos();
		ship_spr.updatePos(pos.x, pos.y, s.getRot());
		ship_spr.draw(screen);
	}
}
