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

void Board::fillBoard(int rows, int columns) {
    srand(time(NULL));
    float pieceWidth = shape.getSize().x / columns;
    float pieceHeight = shape.getSize().y / rows;
    float offsetX = shape.getPosition().x;
    float offsetY = shape.getPosition().y;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            float x = offsetX + j * pieceWidth;
            float y = offsetY + i * pieceHeight;

            // Generate a random letter
            char randomLetter = 'A' + rand() % 26;

            // Create a new Piece object with the random letter
            Piece piece(x, y, pieceWidth, pieceHeight, font, std::string(1, randomLetter), sf::Color::White, sf::Color::Red, sf::Color::Green);

            // Add the piece to the boardChars vector
            boardChars.push_back(piece);
        }
    }
}

void Board::render(sf::RenderTarget* target) {
    target -> draw(this -> shape);
    target -> draw(this -> text);


}
