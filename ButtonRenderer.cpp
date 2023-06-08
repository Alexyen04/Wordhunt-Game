#include "ButtonRenderer.h"
#include "ButtonCustom.h"

ButtonRenderer::ButtonRenderer(ButtonCustom& button) : m_button(button) {}

void ButtonRenderer::render(sf::RenderWindow& window)
{
    window.draw(m_button.getShape());
    window.draw(m_button.getText());
}
