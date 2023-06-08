#include "Button.h"

Button::Button(float x, float y, float width, float height, 
    sf::Font font, std::string text, 
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) 
{
    this->buttonState = BTN_IDLE;
    this -> shape.setPosition(sf::Vector2f(x, y)) ;
    this -> shape.setSize(sf::Vector2f(width, height)) ;
    this -> font = font ;
    this -> text.setFont(this -> font) ;
    this -> text.setString(text) ;
    this -> text.setFillColor(sf::Color::White) ;
    this -> text.setCharacterSize(height * 0.8) ;
    this -> text.setPosition(
        this -> shape.getPosition().x + (this -> shape.getGlobalBounds().width / 2.f) - this -> text.getGlobalBounds().width / 2.f ,
        this -> shape.getPosition().y + (this -> shape.getGlobalBounds().height / 2.f) - this -> text.getGlobalBounds().height / 2.f - (height * .12)
    ) ;

    this -> idleColor = idleColor ;
    this -> hoverColor = hoverColor ;
    this -> activeColor = activeColor ;

    this -> shape.setFillColor(this -> idleColor) ;
}

Button::~Button() {}

const bool Button::isPressed() const { 
    if (this->buttonState == BTN_ACTIVE) {
        return true;
    }
    return false;
}

void Button::update(const sf::Vector2f mousePos) {
    //update the booleans for hover and pressed

    //Idle
    this->buttonState = BTN_IDLE;

    if (this -> shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;
 
        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(sf::Color::White);
            break;

        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(sf::Color::Black);
            break;

        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;

        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::render(sf::RenderTarget* target) 
{
    target -> draw(this -> shape) ;
    target -> draw(this->text); 
}

sf::Color Button::getIdleColor() const {
    return idleColor;
}

void Button::setIdleColor(sf::Color color) {
    idleColor = color;
    if (buttonState == BTN_IDLE) {
        shape.setFillColor(idleColor);
    }
}

sf::Color Button::getHoverColor() const {
    return hoverColor;
}

void Button::setHoverColor(sf::Color color) {
    hoverColor = color;
    if (buttonState == BTN_HOVER) {
        shape.setFillColor(hoverColor);
    }
}

sf::Color Button::getActiveColor() const {
    return activeColor;
}

void Button::setActiveColor(sf::Color color) {
    activeColor = color;
    shape.setFillColor(activeColor);
}

std::string Button::getText() const {
    return text.getString();
}

void Button::setText(const std::string& text) {
    this->text.setString(text);
    // Adjust the position of the text based on the new text size
    this->text.setPosition(
        shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f - (shape.getSize().y * .12)
    );
}