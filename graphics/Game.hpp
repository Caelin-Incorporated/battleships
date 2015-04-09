#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "../logic/logic.hpp"

enum GameState {
	MENU,
	GAME,
};

class Game {
	private:
		std::string title = "Battle Ships";
		sf::RenderWindow screen;
		GameState state;
		Board board;
	public:
		bool init();
		void handleInput();
		void update(float dt);
		void makeMenu();
		void render();
		int run();
};

#endif
