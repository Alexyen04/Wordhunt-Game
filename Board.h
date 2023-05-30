#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "piece.h"

class Board
{
public:
    Board(unsigned int dimensions)
        : dimensions(dimensions), hoverPiece(nullptr)
    {
        // Set the window size to 1500x1500
        int windowSize = 1500;

        // Calculate the total size of the board
        board.setSize(sf::Vector2f(windowSize, windowSize));
        board.setFillColor(sf::Color(200, 200, 200)); // Light gray color

        // Create the grid of pieces
        pieces.reserve(dimensions * dimensions);
        float pieceSize = static_cast<float>(windowSize) / dimensions;
        for (unsigned int row = 0; row < dimensions; ++row)
        {
            for (unsigned int col = 0; col < dimensions; ++col)
            {
                float x = col * pieceSize;
                float y = row * pieceSize;
                pieces.emplace_back(x, y, pieceSize, 'A' + (row * dimensions + col));
            }
        }
    }

    void handleEvent(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseMoved)
        {
            // Get the mouse position relative to the board
            sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - board.getPosition();

            // Find the piece under the mouse position
            hoverPiece = nullptr;
            for (auto& piece : pieces)
            {
                if (piece.getGlobalBounds().contains(mousePosition))
                {
                    hoverPiece = &piece;
                    break;
                }
            }
        }
    }

    void render(sf::RenderTarget& target) const
    {
        target.draw(board);
        for (const auto& piece : pieces)
        {
            piece.render(target);

            // If a piece is being hovered over, change its color to green
            if (&piece == hoverPiece)
            {
                sf::FloatRect bounds = piece.getGlobalBounds();
                sf::RectangleShape highlight;
                highlight.setSize(sf::Vector2f(bounds.width, bounds.height));
                highlight.setPosition(bounds.left, bounds.top);
                highlight.setFillColor(sf::Color::Green);
                target.draw(highlight);
            }
        }
    }

private:
    unsigned int dimensions;
    sf::RectangleShape board;
    std::vector<Piece> pieces;
    const Piece* hoverPiece;
};

#endif
