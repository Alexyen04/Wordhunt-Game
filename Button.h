#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button
{
    private: 
        short unsigned buttonState;

        sf::RectangleShape shape;
        sf::Font font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

    public:
        Button(float x, float y, float width, float height, 
            sf::Font font, std::string text, 
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        ~Button();

        // Accessors
        const bool isPressed() const;

        sf::Color getIdleColor() const;
        void setIdleColor(sf::Color color);

        sf::Color getHoverColor() const;
        void setHoverColor(sf::Color color);

        sf::Color getActiveColor() const;
        void setActiveColor(sf::Color color);

        std::string getText() const;
        void setText(const std::string& text);

        // Functions
        void update(sf::Vector2f mousePos);
        void render(sf::RenderTarget* target);
};

#endif
