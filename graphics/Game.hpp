#ifndef GAME_HPP_
#define GAME_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ShipSpr.hpp"
#include "../logic/logic.hpp"

class Program {
	public:
	private:

};

enum GameState {
	MENU,
	GAME,
};

class Game {
	private:
		std::string title = "Battle Ships";
		sf::RenderWindow screen;
		Sea sea;
		GameState state;
		ShipSpr ship_spr;
	public:
		bool init();
		void handleInput();
		void update(float dt);
		void createBoard();
		void render();
		int run();
};

#endif
