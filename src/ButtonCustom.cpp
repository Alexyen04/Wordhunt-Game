#include "../include/ButtonCustom.h"

ButtonCustom::ButtonCustom(float x, float y, float width, float height, const sf::Font& font, const std::string& buttonText,
                           const sf::Color& idleColor, const sf::Color& hoverColor, const sf::Color& activeColor)
    : buttonState(ButtonState::Idle), idleColor(idleColor), hoverColor(hoverColor), activeColor(activeColor)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    text.setString(buttonText);
    text.setFont(font);
    text.setCharacterSize(static_cast<unsigned int>(height * 0.8));
    text.setPosition(sf::Vector2f(x, y));
}

ButtonCustom::~ButtonCustom()
{
    // Destructor implementation
}

bool ButtonCustom::isPressed() const
{
    return buttonState == ButtonState::Active;
}

sf::Color ButtonCustom::getIdleColor() const
{
    return idleColor;
}

void ButtonCustom::setIdleColor(const sf::Color& color)
{
    idleColor = color;

    if (buttonState == ButtonState::Idle)
    {
        shape.setFillColor(idleColor);
    }
}

sf::Color ButtonCustom::getHoverColor() const
{
    return hoverColor;
}

void ButtonCustom::setHoverColor(const sf::Color& color)
{
    hoverColor = color;

    if (buttonState == ButtonState::Hover)
    {
        shape.setFillColor(hoverColor);
    }
}

sf::Color ButtonCustom::getActiveColor() const
{
    return activeColor;
}

void ButtonCustom::setActiveColor(const sf::Color& color)
{
    activeColor = color;

    if (buttonState == ButtonState::Active)
    {
        shape.setFillColor(activeColor);
    }
}

sf::Text ButtonCustom::getText() const
{
    return text; 
}

void ButtonCustom::setText(const std::string& buttonText)
{
    text.setString(buttonText);
    text.setPosition(shape.getPosition().x, shape.getPosition().y);
}

void ButtonCustom::setPosition(float x, float y)
{
    shape.setPosition(sf::Vector2f(x, y));
    text.setPosition(sf::Vector2f(x, y));
}

void ButtonCustom::setSize(float width, float height)
{
    shape.setSize(sf::Vector2f(width, height));
    text.setCharacterSize(static_cast<unsigned int>(height * 0.8));
}

void ButtonCustom::setFont(const sf::Font& font)
{
    text.setFont(font);
}

void ButtonCustom::setFillColor(const sf::Color& color)
{
    shape.setFillColor(color);
}

void ButtonCustom::setTextColor(const sf::Color& color)
{
    text.setFillColor(color);
}

sf::RectangleShape& ButtonCustom::getShape()
{
    return shape;
}

const sf::RectangleShape& ButtonCustom::getShape() const
{
    return shape;
}

sf::FloatRect ButtonCustom::getTextGlobalBounds() const
{
    return text.getGlobalBounds();
}

sf::Vector2f ButtonCustom::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f ButtonCustom::getSize() const
{
    return shape.getSize();
}

void ButtonCustom::update(const sf::Vector2f& mousePos)
{
    buttonState = ButtonState::Idle;

    if (shape.getGlobalBounds().contains(mousePos))
    {
        buttonState = ButtonState::Hover;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            buttonState = ButtonState::Active;
        }
    }

    switch (buttonState)
    {
        case ButtonState::Idle:
            shape.setFillColor(idleColor);
            text.setFillColor(sf::Color::White);
            break;

        case ButtonState::Hover:
            shape.setFillColor(hoverColor);
            text.setFillColor(sf::Color::Black);
            break;

        case ButtonState::Active:
            shape.setFillColor(activeColor);
            break;

        default:
            shape.setFillColor(sf::Color::Red);
            break;
    }
}

