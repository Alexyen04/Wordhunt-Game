#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <iostream>
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
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        return;
    }

    // Calculate relative positions and sizes based on window size
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);
    sf::Vector2f titlePosition(windowWidth * 0.100f, windowHeight * 0.033f);
    sf::Vector2f playButtonPosition(windowWidth * 0.3667f, windowHeight * 0.5333f);
    sf::Vector2f settingsButtonPosition(windowWidth * 0.3667f, windowHeight * 0.7f);

    // Create the title text
    Text titleText(font, "Modified Word Hunt", static_cast<int>(windowHeight * 0.08f), sf::Color::White, sf::Color::Black, 6.0f, titlePosition);
   
    // Create the buttons
    Button playButton(
        static_cast<int>(playButtonPosition.x),
        static_cast<int>(playButtonPosition.y),
        static_cast<int>(windowWidth * 0.15f),
        static_cast<int>(windowHeight * 0.0667f),
        font,
        "Play",
        sf::Color::Black, 
        sf::Color::White,
        sf::Color(70, 70, 70, 200)
    );
    Button settingsButton(
        static_cast<int>(settingsButtonPosition.x),
        static_cast<int>(settingsButtonPosition.y),
        static_cast<int>(windowWidth * 0.27f), 
        static_cast<int>(windowHeight * 0.0667f),
        font,
        "Settings",
        sf::Color::Black, 
        sf::Color::White, 
        sf::Color(70, 70, 70, 200)
    );
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
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        return;
    }

    // Calculate relative positions based on window size
    sf::Vector2f windowSize(window.getSize().x, window.getSize().y);
    sf::Vector2f titlePosition = sf::Vector2f(windowSize.x * 0.34f, windowSize.y * 0.04f);
    sf::Vector2f soundEffectPosition = sf::Vector2f(windowSize.x * 0.5f, windowSize.y * 0.364); 
    sf::Vector2f scoreMultiplierPosition = sf::Vector2f(windowSize.x * 0.478f, windowSize.y * 0.52);
    sf::Vector2f hintPosition = sf::Vector2f(windowSize.x * 0.62f, windowSize.y * 0.22);
    sf::Vector2f powerupPosition = sf::Vector2f(windowSize.x * 0.56, windowSize.y * 0.662);
    sf::Vector2f backPosition = sf::Vector2f(windowSize.x * 0.62f, windowSize.y * 0.82);

    // Create "Settings" text
    Text titleText(font, "Settings", 120, sf::Color::White, sf::Color::Black, 6.0f, titlePosition);

    Text soundEffectText(font, "Sound Effects", 40, sf::Color::White, sf::Color::Black, 6.0f, soundEffectPosition);

    Text scoreMultiplierText(font, "Score Multiplier", 40, sf::Color::White, sf::Color::Black, 6.0f, scoreMultiplierPosition);
    Text hintText(font, "Hints", 40, sf::Color::White, sf::Color::Black, 6.0f, hintPosition);
    Text powerupText(font, "Powerups", 40, sf::Color::White, sf::Color::Black, 6.0f, powerupPosition);
    Text backText(font, "Back", 40, sf::Color::White, sf::Color::Black, 6.0f, backPosition);

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
    Button backButton(1075, 1200, 325, 100, font, "<-", sf::Color::White, sf::Color::White, sf::Color(70, 70, 70, 200));

    //Create slider
    sf::RectangleShape slider(sf::Vector2f(200, 20));
    slider.setFillColor(sf::Color::White);
    slider.setPosition(300, 280);

    // Slider handle properties
    sf::RectangleShape handle(sf::Vector2f(20, 40));
    handle.setFillColor(sf::Color::Red);
    handle.setPosition(slider.getPosition().x - handle.getSize().x * 0.5f, slider.getPosition().y - handle.getSize().y * 0.5f);

    sf::Text valueText("", font, 30);
    valueText.setFillColor(sf::Color::White);
    valueText.setPosition(400, 400);

    float sliderMin = slider.getPosition().x;
    float sliderMax = slider.getPosition().x + slider.getSize().x;
    float handleWidth = handle.getSize().x;
    bool isDragging = false;

    int sliderValue = 50;
    handle.setPosition(sliderMin + sliderValue * (sliderMax - sliderMin) / 100.0f - handleWidth * 0.5f, handle.getPosition().y);
    
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
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (handle.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    isDragging = true;
                }
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
            else if (event.type == sf::Event::MouseButtonReleased) {
                isDragging = false;
            }
            else if (event.type == sf::Event::MouseMoved) {
                if (isDragging) {
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                    float clampedX = std::max(sliderMin, std::min(sliderMax - handleWidth, mousePos.x));
                    float normalizedX = (clampedX - sliderMin) / (sliderMax - sliderMin - handleWidth);
                    sliderValue = static_cast<int>(normalizedX * 100);
                    handle.setPosition(clampedX, handle.getPosition().y);

                    //Calculate and display the current value
                    stringstream ss;
                    ss << "Current Volume " << sliderValue;
                    valueText.setString(ss.str());
                }
            }
        }

        window.clear();

        titleText.render(window) ;
        // soundText.render(window) ;
        // effectText.render(window) ;
        soundEffectText.render(window) ;
        scoreMultiplierText.render(window) ;
        hintText.render(window) ;
        powerupText.render(window) ;
        backText.render(window) ;

        soundeffectButton.render(&window);
        scoreMultiplierButton.render(&window);
        hintButton.render(&window);
        powerupButton.render(&window);
        backButton.render(&window);

        window.draw(slider);
        window.draw(handle);
        window.draw(valueText);
        
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