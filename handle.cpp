#include <SFML/Graphics.hpp>

class Handle {
private:
    sf::RectangleShape handle;
    float positionX;
    float positionY;

public:
    Handle(float x, float y) {
        positionX = x;
        positionY = y;
        handle.setSize(sf::Vector2f(20, 40));
        handle.setFillColor(sf::Color::Red);
        handle.setPosition(positionX - handle.getSize().x * 0.5f, positionY - handle.getSize().y * 0.5f);
    }

    void setPosition(float x, float y) {
        positionX = x;
        positionY = y;
        handle.setPosition(positionX - handle.getSize().x * 0.5f, positionY - handle.getSize().y * 0.5f);
    }

    sf::RectangleShape getHandle() {
        return handle;
    }
};
