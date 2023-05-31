#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <random>

class Piece
{
public:
    Piece(float x, float y, float size, char letter)
        : position(sf::Vector2f(x, y)), size(size), letter(letter), isHovered(false)
    {
        shape.setPosition(position);
        shape.setSize(sf::Vector2f(size, size));
        shape.setOutlineThickness(2.0f);
        shape.setOutlineColor(sf::Color::Black);

        text.setCharacterSize(static_cast<unsigned int>(size * 0.4f)); // Adjust the character size based on the piece size
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
        text.setPosition(position.x + size / 2.0f, position.y + size / 2.0f);
    }

    void render(sf::RenderTarget& target) const
    {
        target.draw(shape);
        target.draw(text);

        // If the piece is being hovered over, change its fill color to green
        if (isHovered)
        {
            sf::RectangleShape highlight(shape.getSize());
            highlight.setPosition(position);
            highlight.setFillColor(sf::Color::Green);
            target.draw(highlight);
        }
    }

    sf::FloatRect getGlobalBounds() const
    {
        return shape.getGlobalBounds();
    }

    bool getIsHovered() const
    {
        return isHovered;
    }

    void setIsHovered(bool hovered)
    {
        isHovered = hovered;
    }

    char getLetter() const
    {
        return letter;
    }

    void setLetter(char newLetter)
    {
        letter = newLetter;
        text.setString(std::string(1, letter));

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
        text.setPosition(position.x + size / 2.0f, position.y + size / 2.0f);
    }

private:
    sf::Vector2f position;
    float size;
    char letter;
    bool isHovered;
    sf::RectangleShape shape;
    sf::Text text;
};

#endif
