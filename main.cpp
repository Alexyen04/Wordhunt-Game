#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Text.h"
#include "WordPointCalc.h"

using namespace std;

void settingScreen(sf::RenderWindow& window) ;
void mainMenu(sf::RenderWindow& window) ;

// Function to get the mouse position relative to the window
sf::Vector2f getMousePosition(const sf::RenderWindow& window) {
    sf::Vector2i intVector = sf::Mouse::getPosition(window);
    sf::Vector2f floatVector(static_cast<float>(intVector.x), static_cast<float>(intVector.y));
    return floatVector;
}

// Function to render the main menu
void mainMenu(sf::RenderWindow& window) {
    // Clear the window
    window.clear(sf::Color::White);
    
    // Load the gif texture
    sf::Texture gifTexture;
    if (!gifTexture.loadFromFile("main_menu.gif")) {
        return;
    }

    // Create and configure the gif sprite
    sf::Sprite gifSprite(gifTexture);
    gifSprite.setScale(
        static_cast<float>(window.getSize().x) / gifSprite.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / gifSprite.getLocalBounds().height
    );

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }

    // Create the title text
    Text titleText(font, "Modified Word Hunt", 120, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(216.101875f, 50.0f));

    // Create the buttons
    Button playButton(550, 800, 190, 100, font, "Play", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button settingsButton(550, 1050, 325, 100, font, "Settings", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Update button states
            playButton.update(getMousePosition(window));
            settingsButton.update(getMousePosition(window));

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if play button is clicked
                    if (playButton.isPressed()) {
                        // Do something when "Play" button is clicked
                    }
                    // Check if settings button is clicked
                    if (settingsButton.isPressed()) {
                        settingScreen(window);
                    }
                }
            }
        }

        window.clear();
        window.draw(gifSprite);

        titleText.render(window);

        playButton.render(&window);
        settingsButton.render(&window);
        
        window.display();
    }
}

void settingScreen(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }

    // Create "Settings" text
    Text titleText(font, "Settings", 120, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(533.89875f, 50.0f));

    // Create buttons using the Button class
    Button soundeffectButton(1075, 300, 325, 100, font, "Back", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button scoreMultiplierButton(1075, 525, 325, 100, font, "Back", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button hintButton(1075, 750, 325, 100, font, "Back", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button powerupButton(1075, 975, 325, 100, font, "Back", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button backButton(1075, 1200, 325, 100, font, "Back", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Update button states
            backButton.update(getMousePosition(window));

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if play button is clicked
                    if (backButton.isPressed()) {
                        // Do something when "Play" button is clicked
                    }
                    // Check if settings button is clicked
                    if (backButton.isPressed()) {
                        mainMenu(window);
                    }
                }
            }
        }

        window.clear();

        titleText.render(window) ;

        soundeffectButton.render(&window);
        scoreMultiplierButton.render(&window);
        hintButton.render(&window);
        powerupButton.render(&window);
        backButton.render(&window);

        window.display();
    }
}


int main() {
    //promptAndCalculatePoints();
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");
    mainMenu(window);
    return EXIT_SUCCESS;
}