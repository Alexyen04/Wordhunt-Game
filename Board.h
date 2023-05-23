#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable {
    public:
        Board(float x, float y, float width, float height, std::string text) ;
        ~Board();

        void drawBoard();
        void render(sf::RenderTarget* target);


    private:
        int score;
        //vector <Piece> boardChars;
        sf::RectangleShape shape ;
        sf::Font* font ;
        sf::Text text ;
        sf::Sprite m_sprite;    
        sf::Texture m_texture;
        sf::VertexArray m_vertices;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif