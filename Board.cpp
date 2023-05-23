#include "Board.h"
#include "Piece.h"

Board::Board(float x, float y, float width, float height, std::string text) 
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }


    this -> shape.setPosition(sf::Vector2f(x, y)) ;
    this -> shape.setSize(sf::Vector2f(width, height)) ;
    this -> font = font ;
    this -> text.setFont(*this -> font) ;
    this -> text.setString(text) ;
    this -> text.setFillColor(sf::Color::White) ;
    this -> text.setCharacterSize(12) ;
    this -> text.setPosition(
        this -> shape.getPosition().x / 2.f - this -> text.getGlobalBounds().width / 2.f,
        this -> shape.getPosition().y / 2.f - this -> text.getGlobalBounds().height / 2.f
    ) ;

}

Board::~Board() { }


void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_text, states);
}

void Board::render(sf::RenderTarget* target) {
    target -> draw(this -> shape);
}
