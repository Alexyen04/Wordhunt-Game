#include "Board.h"
#include "Piece.h"

Board::Board(float x, float y, float width, float height, 
        sf::Font* font, std::string text) 
{
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
void Board::setRows(int r) {
    rows = r;
}

void Board::setColumns(int c) {
    columns = c;
}

int Board::getRows() {
    return rows;
}

int Board::getColumns() {
    return columns;
}

void drawBoard() {
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");
    window.clear(sf::Color::Green);

    sf::Font font;
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        return EXIT_FAILURE;
    }
}