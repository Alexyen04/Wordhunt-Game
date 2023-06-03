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
        if (font.loadFromFile("Poppins-Black.ttf"))
        {
            shape.setPosition(position);
            shape.setSize(sf::Vector2f(size, size));
            shape.setOutlineThickness(2.0f);
            shape.setOutlineColor(sf::Color::Black);

            text.setFont(font);
            text.setCharacterSize(static_cast<unsigned int>(size * 0.4f));
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold);

            updateText();
        }
    }

    void render(sf::RenderTarget& target) const
    {
        target.draw(shape);
        target.draw(text);
    }

    sf::FloatRect getGlobalBounds() const
    {
        return shape.getGlobalBounds();
    }

    void setRandomLetter()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis('A', 'Z');
        letter = static_cast<char>(dis(gen));
        updateText();
    }

    sf::Text getText() const
    {
        return text;
    }

private:
    sf::Vector2f position;
    float size;
    char letter;
    bool isHovered;
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

    void updateText()
    {
        text.setString(std::string(1, letter));
        text.setPosition(position.x + size / 2.0f, position.y + size / 2.0f);

        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
    }
};

#endif // PIECE_H
