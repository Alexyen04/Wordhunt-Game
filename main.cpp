#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Menu Screen");

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    // Create "Play" button
    sf::Text playText;
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(32);
    playText.setFillColor(sf::Color::White);
    playText.setOutlineColor(sf::Color::Black);
    playText.setOutlineThickness(2);
    playText.setPosition(350, 300);

    // Create "Settings" button
    sf::Text settingsText;
    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(32);
    settingsText.setFillColor(sf::Color::White);
    settingsText.setOutlineColor(sf::Color::Black);
    settingsText.setOutlineThickness(2);
    settingsText.setPosition(325, 350);

    // Load background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

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

        // Clear the window
        window.clear();

        // Draw the background
        window.draw(backgroundSprite);

        // Draw the buttons
        window.draw(playText);
        window.draw(settingsText);

        // Display the window
        window.display();
    }

    return EXIT_SUCCESS;
}
