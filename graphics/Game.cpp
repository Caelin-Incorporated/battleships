#include <cmath>
#include "Game.hpp"
using namespace std;

bool Game::init(){
	screen.create(sf::VideoMode(800,600), title, sf::Style::Default);
	state = MENU; // TOOD swtich to menu when it's done
	board.init();
	return false;
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
	if(state == GAME){
		state = board.update(dt);
	} else if(state == MENU){
		state = menu.update(dt);
	}
}

void Game::render(){
	if(state == GAME){
		board.draw(screen);
	} else if(state == MENU){
		menu.draw(screen);
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
