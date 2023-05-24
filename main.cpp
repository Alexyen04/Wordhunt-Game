#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace std;

sf::Vector2f getMousePosition(const sf::RenderWindow& window);
void settingScreen(sf::RenderWindow& window);
void mainMenu(sf::RenderWindow& window);

sf::Vector2f getMousePosition(const sf::RenderWindow& window) {
    sf::Vector2<int> intVector = sf::Mouse::getPosition(window);
    sf::Vector2<float> floatVector;
    floatVector.x = static_cast<float>(intVector.x);
    floatVector.y = static_cast<float>(intVector.y);
    return floatVector;
}

void mainMenu(sf::RenderWindow& window) {
    //testing gif features
    sf::Texture gifTexture;
    if (!gifTexture.loadFromFile("main_menu.gif")) {
        // Error handling if the image cannot be loaded
        return;
    }

    sf::Sprite gifSprite(gifTexture);
    gifSprite.setScale(
        static_cast<float>(window.getSize().x) / gifSprite.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / gifSprite.getLocalBounds().height
    );

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
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

    // Create buttons using the Button class
    Button playButton(550, 800, 190, 100, font, "Play", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button settingsButton(550, 1050, 325, 100, font, "Settings", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        sf::Vector2f mousePos = getMousePosition(window);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Tracking of mouse
            sf::Vector2f mousePos = getMousePosition(window);
            cout << "Mouse position: X = " << mousePos.x << ", Y = " << mousePos.y << endl;

            playButton.update(mousePos) ;
            settingsButton.update(mousePos) ;

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if play button is clicked
                    if (playButton.isPressed()) {
                        // Do something when "Play" button is clicked
                    }
                    // Check if settings button is clicked
                    if (settingsButton.isPressed()) {
                        settingScreen(window) ;
                    }
                }
            }
        }

        window.clear();
        window.draw(gifSprite);

        // Draw the title
        window.draw(titleText);

        // Draw the buttons
        playButton.update(mousePos);
        playButton.render(&window);

        settingsButton.update(mousePos);
        settingsButton.render(&window);

        // Display the window
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
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Settings");
    titleText.setCharacterSize(120);
    titleText.setFillColor(sf::Color::White);
    titleText.setOutlineColor(sf::Color::Black);
    titleText.setOutlineThickness(6);
    titleText.setPosition(225, 50);

    // Create buttons using the Button class
    Button playButton(550, 800, 190, 100, font, "Play", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));
    Button settingsButton(550, 1050, 325, 100, font, "Settings", sf::Color::White, sf::Color::Black, sf::Color(70, 70, 70, 200));

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        sf::Vector2f mousePos = getMousePosition(window);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Tracking of mouse
            sf::Vector2f mousePos = getMousePosition(window);
            cout << "Mouse position: X = " << mousePos.x << ", Y = " << mousePos.y << endl;

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if play button is clicked
                    if (playButton.isPressed()) {
                        // Do something when "Play" button is clicked
                    }
                    // Check if settings button is clicked
                    if (settingsButton.isPressed()) {
                        // Do something when "Settings" button is clicked
                    }
                }
            }
        }

        window.clear();

        // Draw the title
        window.draw(titleText);

        // Draw the buttons
        playButton.update(mousePos);
        playButton.render(&window);

        settingsButton.update(mousePos);
        settingsButton.render(&window);

        // Display the window
        window.display();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");
    mainMenu(window);
    return EXIT_SUCCESS;
}
