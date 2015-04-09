#include <cmath>
#include "Game.hpp"
using namespace std;

bool Game::init(){
	screen.create(sf::VideoMode(800,600), title, sf::Style::Default);
	state = GAME; // TODO swtich to menu when it's done
	ship_spr.setTexture("./data/textures/ship.png");
	createBoard();
	return false;
}

void Game::createBoard() {
	Ship s(0, 10, 10); // TODO add sea add ship function
	s.updateHitboxes(100,100, M_PI);
	sea.ships.push_back(s);
}

void Game::handleInput(){
	sf::Event e;
	while(screen.pollEvent(e)){
		if(e.type == sf::Event::Closed){
			screen.close();
		}
	}
}

void Game::update(float dt){
	float angle = sea.ships[0].getRot();
	sea.ships[0].updateHitboxes(100,100,angle+90*dt);
}

void Game::render(){
	if(state == GAME){
		// TODO call board.draw instead
		for(Ship &s : sea.ships){
			vec2 pos = s.getPos();
			ship_spr.updatePos(pos.x, pos.y, s.getRot());
			ship_spr.draw(screen);
		}
	} else if(state == MENU){
	}
}

int Game::run(){
	float dt = 0;
	sf::Clock dtTimer;
	while(screen.isOpen()){
		handleInput();
		update(dt);
		screen.clear(sf::Color::Black);
		render();
		screen.display();
		dt = dtTimer.restart().asSeconds();
	}
	return 0;
}
