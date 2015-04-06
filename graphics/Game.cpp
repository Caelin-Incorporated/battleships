#include "Game.hpp"

bool Game::init(){
	screen.create(sf::VideoMode(800,600), title, sf::Style::Default);
	return false;
}

void Game::createBoard() {
	// TOOD create a board
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
	//TOOD Update code
}

void Game::render(){
	//TOOD rendering code
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
