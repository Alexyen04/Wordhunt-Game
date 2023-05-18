#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>

class Piece {
    public: 
        Piece(float x, float y, float width, float height, 
        sf::Font* font, std::string text, 
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) ;

        ~Piece() ;
        
    private:
        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text ;
        char c; 


        sf::Color idleColor ;
        sf::Color hoverColor ;
        sf::Color activateColor ;
};

#endif  
