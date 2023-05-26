#include "Board.h"

Board::Board(float x, float y, float width, float height, 
        sf::Font* font, std::string text) 
{
    this -> shape.setPosition(sf::Vector2f(x, y)) ;
    this -> shape.setSize(sf::Vector2f(width, height)) ;
    this -> font = font ;
    this -> text.setFont(*this -> font) ;
    this -> text.setString(text) ;
    this -> text.setFillColor(sf::Color::Black) ;
    this -> text.setCharacterSize(150) ;
    this -> text.setPosition(
        this -> shape.getPosition().x + (width - this->text.getGlobalBounds().width) / 2.0f, 
        0.5*(this -> shape.getPosition().y) 
    ) ;
    this -> shape.setFillColor(sf::Color::White) ;
}

Board::~Board() { }

void Board::fillBoard(int rows, int columns){
    
}
void Board::render(sf::RenderTarget* target) {
    target -> draw(this -> shape);
    target -> draw(this -> text);


}
