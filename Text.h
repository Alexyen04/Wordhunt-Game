#include <SFML/Graphics.hpp>

class Text {
private:
    sf::Text text;

public:
    Text(sf::Font& font, const std::string& string, unsigned int characterSize, const sf::Color& fillColor,
         const sf::Color& outlineColor = sf::Color::Transparent, float outlineThickness = 0.0f,
         const sf::Vector2f& position = sf::Vector2f(0.0f, 0.0f))
    {
        text.setFont(font);
        text.setString(string);
        text.setCharacterSize(characterSize);
        text.setFillColor(fillColor);
        text.setOutlineColor(outlineColor);
        text.setOutlineThickness(outlineThickness);
        text.setPosition(position);
    }

    void setPosition(const sf::Vector2f& position) {
        text.setPosition(position);
    }

    void setString(const std::string& string) {
        text.setString(string);
    }

    void setCharacterSize(unsigned int characterSize) {
        text.setCharacterSize(characterSize);
    }

    void setFillColor(const sf::Color& fillColor) {
        text.setFillColor(fillColor);
    }

    void setOutlineColor(const sf::Color& outlineColor) {
        text.setOutlineColor(outlineColor);
    }

    void setOutlineThickness(float outlineThickness) {
        text.setOutlineThickness(outlineThickness);
    }

    sf::Vector2f getPosition() const {
        return text.getPosition();
    }

    std::string getString() const {
        return text.getString();
    }

    unsigned int getCharacterSize() const {
        return text.getCharacterSize();
    }

    sf::Color getFillColor() const {
        return text.getFillColor();
    }

    sf::Color getOutlineColor() const {
        return text.getOutlineColor();
    }

    float getOutlineThickness() const {
        return text.getOutlineThickness();
    }

    void render(sf::RenderTarget& target) {
        target.draw(text);
    }
};