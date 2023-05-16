#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Button
{
    private: 
        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text ;

        sf::Color idleColor ;
        sf::Color hoverColor ;
        sf::Color activateColor ;

    public:
        Button(float x, float y, float width, float height, 
        sf::Font* font, std::string text, 
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) ;
        ~Button() ;

        //functions
        void update(sf::Vector2f mousePos) ;
        void render(sf::RenderTarget* target) ;

} ;

#endif