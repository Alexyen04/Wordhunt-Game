#include <SFML/Graphics.hpp>

class Slider
{
public:
    Slider(float width, float height, float xPos, float yPos)
    {
        sliderBar.setSize(sf::Vector2f(width, height));
        sliderBar.setPosition(xPos, yPos);

        sliderHandle.setSize(sf::Vector2f(height, height));
        sliderHandle.setPosition(xPos, yPos);
    }

    void update(sf::RenderWindow& window)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f newPosition = window.mapPixelToCoords(mousePosition);

        if (isSliderPressed)
        {
            newPosition.x = std::max(newPosition.x, sliderBar.getPosition().x);
            newPosition.x = std::min(newPosition.x, sliderBar.getPosition().x + sliderBar.getSize().x - sliderHandle.getSize().x);
            sliderHandle.setPosition(newPosition);
        }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sliderBar);
        window.draw(sliderHandle);
    }

    void handleEvent(const sf::Event& event, sf::RenderWindow& window)
    {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (sliderHandle.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                isSliderPressed = true;
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            isSliderPressed = false;
        }
    }

    float getValue() const
    {
        float sliderWidth = sliderBar.getSize().x - sliderHandle.getSize().x;
        float handlePosition = sliderHandle.getPosition().x - sliderBar.getPosition().x;
        float percentage = handlePosition / sliderWidth;
        return percentage * 100.f;
    }

private:
    sf::RectangleShape sliderBar;
    sf::RectangleShape sliderHandle;
    bool isSliderPressed = false;
};