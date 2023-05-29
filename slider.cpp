#include <SFML/Graphics.hpp>
#include "handle.cpp"

class Slider {
private:
    sf::RectangleShape slider;
    Handle handle;
    sf::Text valueText;
    float sliderMin;
    float sliderMax;
    float handleWidth;
    bool isDragging;
    int sliderValue;

public:
    Slider(sf::Font& font) {
        slider.setSize(sf::Vector2f(200, 20));
        slider.setFillColor(sf::Color::White);
        slider.setPosition(300, 280);

        handle = Handle(slider.getPosition().x, slider.getPosition().y);

        valueText.setFont(font);
        valueText.setCharacterSize(30);
        valueText.setFillColor(sf::Color::White);
        valueText.setPosition(400, 400);

        sliderMin = slider.getPosition().x;
        sliderMax = slider.getPosition().x + slider.getSize().x;
        handleWidth = handle.getHandle().getSize().x;
        isDragging = false;

        sliderValue = 50;
        handle.setPosition(sliderMin + sliderValue * (sliderMax - sliderMin) / 100.0f - handleWidth * 0.5f, handle.getPosition().y);
    }

    void update() {
        // Update slider logic here
    }

    void draw(sf::RenderWindow& window) {
        window.draw(slider);
        window.draw(handle.getHandle());
        window.draw(valueText);
    }
};
