#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Board.h"
#include "piece.h"
#include "Text.h"
#include "WordPointCalc.h"
#include "Settings.h"

using namespace std;

void settingScreen(sf::RenderWindow& window, Settings &userSettings) ;
void mainMenu(sf::RenderWindow& window, Settings &userSettings) ;

// Function to get the mouse position relative to the window
sf::Vector2f getMousePosition(const sf::RenderWindow& window) {
    sf::Vector2i intVector = sf::Mouse::getPosition(window);
    sf::Vector2f floatVector(static_cast<float>(intVector.x), static_cast<float>(intVector.y));
    return floatVector;
}

// Function to render the main menu
void mainMenu(sf::RenderWindow& window, Settings &userSettings) {
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
                        settingScreen(window, userSettings);
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

void settingScreen(sf::RenderWindow& window, Settings &userSettings) {
    window.clear(sf::Color::White);

    // Load font for the text
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }

    // Create "Settings" text
    Text titleText(font, "Settings", 120, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(533.89875f, 50.0f));

    Text soundText(font, "Sound", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 270.0f));
    Text effectText(font, "Effects", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 340.0f));

    Text scoremultiplierText(font, "Score Multiplier", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 525.0f));
    Text hintText(font, "Hints", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 760.0f));
    Text powerupText(font, "Powerups", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 985.0f));
    Text backText(font, "Back", 60, sf::Color::White, sf::Color::Black, 6.0f, sf::Vector2f(800.0f, 1210.0f));

    // Initialize button labels based on user settings
    sf::Color soundButtonColor = userSettings.areEffectsEnabled() ? sf::Color::Green : sf::Color::Red;
    sf::Color scoreMultiplierButtonColor = userSettings.isScoreMultiplierEnabled() ? sf::Color::Green : sf::Color::Red;
    sf::Color hintButtonColor = userSettings.areHintsEnabled() ? sf::Color::Green : sf::Color::Red;
    sf::Color powerupButtonColor = userSettings.arePowerupsEnabled() ? sf::Color::Green : sf::Color::Red;

    // Initialize button labels based on user settings
    std::string soundButtonText = userSettings.areEffectsEnabled() ? "On" : "Off";
    std::string scoreMultiplierButtonText = userSettings.isScoreMultiplierEnabled() ? "On" : "Off";
    std::string hintButtonText = userSettings.areHintsEnabled() ? "On" : "Off";
    std::string powerupButtonText = userSettings.arePowerupsEnabled() ? "On" : "Off";

    // Create buttons using the Button class
    Button soundeffectButton(1075, 300, 325, 100, font, soundButtonText, soundButtonColor , soundButtonColor, soundButtonColor);
    Button scoreMultiplierButton(1075, 525, 325, 100, font, scoreMultiplierButtonText, scoreMultiplierButtonColor, scoreMultiplierButtonColor, scoreMultiplierButtonColor);
    Button hintButton(1075, 750, 325, 100, font, hintButtonText, hintButtonColor, hintButtonColor, hintButtonColor);
    Button powerupButton(1075, 975, 325, 100, font, powerupButtonText, powerupButtonColor, powerupButtonColor, powerupButtonColor);
    Button backButton(1075, 1200, 325, 100, font, "->", sf::Color::White, sf::Color::White, sf::Color(70, 70, 70, 200));

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Update button states
            backButton.update(getMousePosition(window));
            soundeffectButton.update(getMousePosition(window));
            scoreMultiplierButton.update(getMousePosition(window));
            hintButton.update(getMousePosition(window));
            powerupButton.update(getMousePosition(window));

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if settings button is clicked
                    if (backButton.isPressed()) {
                        mainMenu(window, userSettings);
                    }
                    if (soundeffectButton.isPressed()) {
                        if (userSettings.areEffectsEnabled())
                        {
                            userSettings.setEffectsEnabled(false) ;
                        }
                        else 
                        {
                            userSettings.setEffectsEnabled(true) ;
                        }

                        if (userSettings.areEffectsEnabled())
                        {
                            soundeffectButton.setText("On") ;
                            soundeffectButton.setIdleColor(sf::Color::Green) ;
                            soundeffectButton.setHoverColor(sf::Color::Green) ;
                        }
                        else
                        {
                            soundeffectButton.setText("Off") ;
                            soundeffectButton.setIdleColor(sf::Color::Red) ;
                            soundeffectButton.setHoverColor(sf::Color::Red) ;
                        }
                    }
                    if (scoreMultiplierButton.isPressed()) {
                        if (userSettings.isScoreMultiplierEnabled())
                        {
                            userSettings.setScoreMultiplierEnabled(false) ;
                        }
                        else 
                        {
                            userSettings.setScoreMultiplierEnabled(true) ;
                        }

                        if (userSettings.isScoreMultiplierEnabled())
                        {
                            scoreMultiplierButton.setText("On") ;
                            scoreMultiplierButton.setIdleColor(sf::Color::Green) ;
                            scoreMultiplierButton.setHoverColor(sf::Color::Green) ;
                        }
                        else
                        {
                            scoreMultiplierButton.setText("Off") ;
                            scoreMultiplierButton.setIdleColor(sf::Color::Red) ;
                            scoreMultiplierButton.setHoverColor(sf::Color::Red) ;
                        }
                    }
                    if (hintButton.isPressed()) {
                        if (userSettings.areHintsEnabled())
                        {
                            userSettings.setHintsEnabled(false) ;
                        }
                        else 
                        {
                            userSettings.setHintsEnabled(true) ;
                        }

                        if (userSettings.areHintsEnabled())
                        {
                            hintButton.setText("On") ;
                            hintButton.setIdleColor(sf::Color::Green) ;
                            hintButton.setHoverColor(sf::Color::Green) ;
                        }
                        else
                        {
                            hintButton.setText("Off") ;
                            hintButton.setIdleColor(sf::Color::Red) ;
                            hintButton.setHoverColor(sf::Color::Red) ;
                        }
                    }
                    if (powerupButton.isPressed()) {
                        if (userSettings.arePowerupsEnabled())
                        {
                            userSettings.setPowerupsEnabled(false) ;
                        }
                        else 
                        {
                            userSettings.setPowerupsEnabled(true) ;
                        }

                        if (userSettings.arePowerupsEnabled())
                        {
                            powerupButton.setText("On") ;
                            powerupButton.setIdleColor(sf::Color::Green) ;
                            powerupButton.setHoverColor(sf::Color::Green) ;
                        }
                        else
                        {
                            powerupButton.setText("Off") ;
                            powerupButton.setIdleColor(sf::Color::Red) ;
                            powerupButton.setHoverColor(sf::Color::Red) ;
                        }
                    }
                }
            }
        }

        window.clear();

        titleText.render(window) ;
        soundText.render(window) ;
        effectText.render(window) ;
        scoremultiplierText.render(window) ;
        hintText.render(window) ;
        powerupText.render(window) ;
        backText.render(window) ;

        soundeffectButton.render(&window);
        scoreMultiplierButton.render(&window);
        hintButton.render(&window);
        powerupButton.render(&window);
        backButton.render(&window);

        
        // Display the window
        window.display();
    }
}


int main() {
    //promptAndCalculatePoints();
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");
    Settings userSettings;
    mainMenu(window, userSettings);
    return EXIT_SUCCESS;
}