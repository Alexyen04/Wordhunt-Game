#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "piece.h"
#include <vector>
#include <iostream>

class Board
{
public:
    Board(unsigned int dimensions);

    void initializeRandomLetters();
    void update(const sf::Vector2f& mousePosition, bool isMousePressed);
    void handleEvent(const sf::Event& event);
    void render(sf::RenderTarget& target) const;
    void printWord();

private:
    unsigned int dimensions;
    std::vector<Piece> pieces;
    std::vector<bool> pieceSelected;
    std::vector<char> characters;
    const Piece* hoverPiece;
    bool isMousePressed;
    sf::RectangleShape board;
};

#endif // BOARD_H
