#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
    Game();
    virtual ~Game();

    void updateSFMLevents();
    void update();
    void run();
    void render();

private:
    void initWindow();
    sf::RenderWindow* window; // Added 'window' member variable
    sf::Event sfEvent; // Added 'sfEvent' member variable
};

#endif
