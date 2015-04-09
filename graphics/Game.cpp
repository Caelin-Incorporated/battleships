#include <cmath>
#include "Game.hpp"
using namespace std;

bool Game::init(){
	screen.create(sf::VideoMode(800,600), title, sf::Style::Default);
	state = GAME; // TODO swtich to menu when it's done
	board.init();
	return false;
}

void Game::makeMenu() {
	float dt = 0;
	sf::Clock dtTimer;
	while(screen.isOpen()){
		handleInput();
		update(dt);
		screen.clear(sf::Color(50, 50, 170));
		render();
		screen.display();
		dt = dtTimer.restart().asSeconds();
	}
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
		board.update(dt);
	} else if(state == MENU){
	}
}

void Game::render(){
	if(state == GAME){
		board.draw(screen);
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
