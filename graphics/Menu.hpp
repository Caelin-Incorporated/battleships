#ifndef MENU_HPP_
#define MENU_HPP_
#include <SFML/Graphics.hpp>


class Menu {
    private:
        std::string startLoc;
        std::string quitLoc;

        sf::Sprite start;
        sf::Texture startTex;
        sf::Sprite quit;
        sf::Texture quitTex;

        bool setQuit(std::string Texture);
        bool setStart(std::string Texture);
    public:
        Menu();
		void draw(sf::RenderWindow &screen);
};

#endif
