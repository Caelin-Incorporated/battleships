#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Menu.hpp"
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
		Menu menu;
	public:
		bool init();
		void handleInput();
		void update(float dt);
		void render();
		int run();
};

#endif
