#include "Button.h"

Button::Button(float x, float y, float width, float height, 
        sf::Font* font, std::string text, 
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) 
{
    this -> shape.setSize(sf::Vector2f(width, height)) ;
}