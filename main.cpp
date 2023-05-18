#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Board.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");

    // Change the background color to green
    window.clear(sf::Color::Green);

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    // Create "Modified Word Hunt" text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Modified Word Hunt");
    titleText.setCharacterSize(120);
    titleText.setFillColor(sf::Color::White);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(6);
    titleText.setPosition(225, 50);

    // Create "Play" button
    sf::Text playText;
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(80);
    playText.setFillColor(sf::Color::White);
    playText.setOutlineColor(sf::Color::Black);
    playText.setOutlineThickness(6);
    playText.setPosition(550, 800);

    // Create "Settings" button
    sf::Text settingsText;
    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(80);
    settingsText.setFillColor(sf::Color::White);
    settingsText.setOutlineColor(sf::Color::Black);
    settingsText.setOutlineThickness(6);
    settingsText.setPosition(550, 1050);
    
    // Game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if "Play" button is clicked
                    if (playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Do something when "Play" button is clicked
                    }
                    // Check if "Settings" button is clicked
                    if (settingsText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Do something when "Settings" button is clicked
                    }
                }
            }
        }

        // Clear the window with green color
        window.clear(sf::Color::Green);

        // Draw the title
        window.draw(titleText);

        // Draw the buttons
        window.draw(playText);
        window.draw(settingsText);
  
        // Display the window
        window.display();
    }

    return EXIT_SUCCESS;
}
