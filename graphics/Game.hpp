#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../logic/logic.hpp"


class Game {
	private:
		std::string title = "Battle Ships";
		sf::RenderWindow screen;
	public:
		bool init();
		void handleInput();
		void update(float dt);
		void createBoard();
		void makeMenu();
		void render();
		int run();
};

#endif
