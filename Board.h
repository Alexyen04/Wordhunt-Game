#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "piece.h"

class Board
{
public:
    Board(unsigned int dimensions);

    void update(const sf::Vector2f& mousePosition);
    void handleEvent(const sf::Event& event);
    void render(sf::RenderTarget& target) const;
    void initializeRandomLetters();

private:
    unsigned int dimensions;
    sf::RectangleShape board;
    std::vector<Piece> pieces;
    std::vector<bool> pieceSelected;
    const Piece* hoverPiece;
    bool isMousePressed;
};

#endif
