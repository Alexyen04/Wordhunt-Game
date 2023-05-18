#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>

class Board {
    public:
        Board(float x, float y, float width, float height, 
        sf::Font* font, std::string text) ;
        ~Board();
        
        void drawBoard();


        //initialize in settings page
        void setRows(int);
        void setColumns(int);
        int getRows();
        int getColumns();

    private:
        int rows = 0; 
        int columns = 0;
        int score;
        piece matrixBoard [rows][columns];
        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text ;
};

#endif