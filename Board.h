#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "piece.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Board {
    public:
        Board (float x, float y, float width, float height, 
        sf::Font* font, std::string text) ;

        ~Board();

        void fillBoard(int, int);
        
        void render(sf::RenderTarget* target);


    private:
        int score;
        std::vector <Piece> boardChars;
        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text ;

};

#endif