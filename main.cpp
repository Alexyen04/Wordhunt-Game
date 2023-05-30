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
void gameScreen(sf::RenderWindow& window, Settings &userSettings) ;

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
                        gameScreen(window, userSettings);
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

    sf::Vector2f dimensionPosition = sf::Vector2f(windowSize.x * 0.05f, windowSize.y * 0.22f);
    sf::Vector2f soundEffectPosition = sf::Vector2f(windowSize.x * 0.05f, windowSize.y * 0.366f); 
    sf::Vector2f soundDimension = sf::Vector2f(windowSize.x * 0.05f, windowSize.y * 0.516f);
    sf::Vector2f wordDimension = sf::Vector2f(windowSize.x * 0.05f, windowSize.y * 0.665f);
    sf::Vector2f scoreMultiplierPosition = sf::Vector2f(windowSize.x * 0.05f, windowSize.y * 0.817f);

    sf::Vector2f hintPosition = sf::Vector2f(windowSize.x * 0.67f, windowSize.y * 0.22f);
    sf::Vector2f timerPosition = sf::Vector2f(windowSize.x * 0.59f, windowSize.y * 0.366f);
    sf::Vector2f powerupPosition = sf::Vector2f(windowSize.x * 0.6f, windowSize.y * 0.516f);
    sf::Vector2f wordListPosition = sf::Vector2f(windowSize.x * 0.5f, windowSize.y * 0.665f);
    sf::Vector2f backPosition = sf::Vector2f(windowSize.x * 0.675f, windowSize.y * 0.817f);

    Text titleText(font, "Settings", 120, sf::Color::White, sf::Color::Black, 6.0f, titlePosition);

    Text dimensionText(font, "Dimensions", 40, sf::Color::White, sf::Color::Black, 6.0f, dimensionPosition);
    Text soundEffectText(font, "Sound Effects", 40, sf::Color::White, sf::Color::Black, 6.0f, soundEffectPosition);
    Text soundText(font, "Sound %", 40, sf::Color::White, sf::Color::Black, 6.0f, soundDimension);
    Text wordText(font, "Word Limit", 40, sf::Color::White, sf::Color::Black, 6.0f, wordDimension);
    Text scoreMultiplierText(font, "Score Multiplier", 40, sf::Color::White, sf::Color::Black, 6.0f, scoreMultiplierPosition);

    Text hintText(font, "Hints", 40, sf::Color::White, sf::Color::Black, 6.0f, hintPosition);
    Text timerText(font, "Timer Amount", 40, sf::Color::White, sf::Color::Black, 6.0f, timerPosition);
    Text powerupText(font, "Powerups", 40, sf::Color::White, sf::Color::Black, 6.0f, powerupPosition);
    Text customText(font, "Custom Word List", 40, sf::Color::White, sf::Color::Black, 6.0f, wordListPosition);
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
    Button hintButton(1140, 300, 325, 100, font, hintButtonText, hintButtonColor, hintButtonColor, hintButtonColor);
    Button soundeffectButton(400, 523, 325, 100, font, soundButtonText, soundButtonColor , soundButtonColor, soundButtonColor);
    Button scoreMultiplierButton(430, 1200, 325, 100, font, scoreMultiplierButtonText, scoreMultiplierButtonColor, scoreMultiplierButtonColor, scoreMultiplierButtonColor);
    Button powerupButton(1140, 750, 325, 100, font, powerupButtonText, powerupButtonColor, powerupButtonColor, powerupButtonColor);
    Button backButton(1140, 1200, 325, 100, font, "<-", sf::Color::White, sf::Color::White, sf::Color(70, 70, 70, 200));

    //Create slider
    sf::RectangleShape soundSlider(sf::Vector2f(200, 20));
    soundSlider.setFillColor(sf::Color::White);
    soundSlider.setPosition(windowSize.x * 0.215f, windowSize.y * 0.52f);

    // Slider handle properties
    sf::RectangleShape soundHandle(sf::Vector2f(20, 40));
    soundHandle.setFillColor(sf::Color::Red);
    soundHandle.setPosition(soundSlider.getPosition().x - soundHandle.getSize().x * 0.5f, soundSlider.getPosition().y - soundHandle.getSize().y * 0.5f);

    sf::Text valueText("", font, 30);
    valueText.setFillColor(sf::Color::White);
    valueText.setPosition(windowSize.x * 0.271f, windowSize.y * 0.538f);

    float sliderMin = soundSlider.getPosition().x;
    float sliderMax = soundSlider.getPosition().x + soundSlider.getSize().x;
    float handleWidth = soundHandle.getSize().x;
    bool isDragging = false;

    int sliderValue = 50;
    soundHandle.setPosition(sliderMin + sliderValue * (sliderMax - sliderMin) / 100.0f - handleWidth * 0.5f, soundHandle.getPosition().y);
    
    //Create text input
    sf::Text timeInputText("", font, 40);
    timeInputText.setFillColor(sf::Color::Black);
    timeInputText.setPosition(windowSize.x * 0.80f, windowSize.y * 0.366f);

    sf::Text dimensionInputText("", font, 40);
    dimensionInputText.setFillColor(sf::Color::Black);
    dimensionInputText.setPosition(windowSize.x * 0.24f, windowSize.y * 0.12);
    
    sf::Text limitInputText("", font, 40);
    limitInputText.setFillColor(sf::Color::Black);
    limitInputText.setPosition(windowSize.x * 0.24, windowSize.y * 0.506);

    sf::RectangleShape timerBox;
    timerBox.setSize(sf::Vector2f(250.0f, 45.0f));
    timerBox.setFillColor(sf::Color::White);
    timerBox.setOutlineColor(sf::Color::Black);
    timerBox.setOutlineThickness(1.0f);
    timerBox.setPosition(windowSize.x * 0.80f, windowSize.y * 0.366f);

    sf::RectangleShape dimensionBox;
    dimensionBox.setSize(sf::Vector2f(250.0f, 45.0f));
    dimensionBox.setFillColor(sf::Color::White);
    dimensionBox.setOutlineColor(sf::Color::Black);
    dimensionBox.setOutlineThickness(1.0f);
    dimensionBox.setPosition(windowSize.x * 0.24f, windowSize.y * 0.12f);

    sf::RectangleShape wordLimitBox;
    wordLimitBox.setSize(sf::Vector2f(250.0f, 45.0f));
    wordLimitBox.setFillColor(sf::Color::White);
    wordLimitBox.setOutlineColor(sf::Color::Black);
    wordLimitBox.setOutlineThickness(1.0f);
    wordLimitBox.setPosition(windowSize.x * 0.24f, windowSize.y * 0.506f);

    sf::RectangleShape timeCursor;
    timeCursor.setSize(sf::Vector2f(2.0f, 40.0f));
    timeCursor.setFillColor(sf::Color::Black);

    sf::RectangleShape dimensionCursor;
    dimensionCursor.setSize(sf::Vector2f(2.0f, 40.0f));
    dimensionCursor.setFillColor(sf::Color::Black);

    sf::RectangleShape limitCursor;
    limitCursor.setSize(sf::Vector2f(2.0f, 40.0f));
    limitCursor.setFillColor(sf::Color::Black);

    string timeInputString;
    string dimensionInputString;
    string limitInputString;

    bool showTimeCursor = true;
    bool showDimensionCursor = true;
    bool showLimitCursor = true;

    sf::Clock timeCursorTimer;
    const sf::Time timeCursorInterval = sf::seconds(0.5f);

    sf::Clock dimensionCursorTimer;
    const sf::Time dimensionCursorInterval = sf::seconds(0.5f);

    sf::Clock limitCursorTimer;
    const sf::Time limitCursorInterval = sf::seconds(0.5f);

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
                if (soundHandle.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
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
            else if (event.type == sf::Event::MouseMoved && isDragging) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                float mouseX = static_cast<float>(mousePos.x);
                // Clamp the mouse position to the slider bounds
                if (mouseX < sliderMin) {
                    mouseX = sliderMin;
                } else if (mouseX > sliderMax) {
                    mouseX = sliderMax;
                }
                // Calculate the new slider value based on the mouse position
                sliderValue = static_cast<int>((mouseX - sliderMin) / (sliderMax - sliderMin) * 100.0f);
                // Move the slider handle based on the new value
                soundHandle.setPosition(mouseX - handleWidth * 0.5f, soundHandle.getPosition().y);
                // Update the value text
                std::ostringstream oss;
                oss << sliderValue;
                valueText.setString(oss.str());
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (timerBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode >= 48 && event.text.unicode <= 57) {// Check if the entered character is a number
                        timeInputString += static_cast<char>(event.text.unicode);
                        timeInputText.setString(timeInputString);
                    }
                    else if (event.text.unicode == 8 && !timeInputText.getString().isEmpty()) {// Check if the entered character is the backspace key
                        timeInputString.pop_back();
                        timeInputText.setString(timeInputString);
                    }
                    else if (event.text.unicode == 13 && !timeInputString.empty()) {// Check if the entered character is the enter key
                        // Save the input when Enter key is pressed
                        cout << "Input: " << timeInputString << endl;
                    }
                }
            }
            else if (dimensionBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode >= 48 && event.text.unicode <= 57) {// Check if the entered character is a number
                        dimensionInputString += static_cast<char>(event.text.unicode);
                        dimensionInputText.setString(dimensionInputString);
                    }
                    else if (event.text.unicode == 8 && !dimensionInputText.getString().isEmpty()) {// Check if the entered character is the backspace key
                        dimensionInputString.pop_back();
                        dimensionInputText.setString(dimensionInputString);
                    }
                    else if (event.text.unicode == 13 && !dimensionInputString.empty()) {// Check if the entered character is the enter key
                        // Save the input when Enter key is pressed
                        cout << "Input: " << dimensionInputString << endl;
                    }
                }
            }
            else if (wordLimitBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode >= 48 && event.text.unicode <= 57) {// Check if the entered character is a number
                        limitInputString += static_cast<char>(event.text.unicode);
                        limitInputText.setString(limitInputString);
                    }
                    else if (event.text.unicode == 8 && !limitInputText.getString().isEmpty()) {// Check if the entered character is the backspace key
                        limitInputString.pop_back();
                        limitInputText.setString(limitInputString);
                    }
                    else if (event.text.unicode == 13 && !limitInputString.empty()) {// Check if the entered character is the enter key
                        // Save the input when Enter key is pressed
                        cout << "Input: " << limitInputString << endl;
                    }
                }
            }
        }

        window.clear();

        titleText.render(window) ;
        dimensionText.render(window) ;
        soundEffectText.render(window) ;
        soundText.render(window) ;
        wordText.render(window) ;
        scoreMultiplierText.render(window) ;
        
        hintText.render(window) ;
        timerText.render(window) ;
        powerupText.render(window) ;
        customText.render(window) ;
        backText.render(window) ;

        soundeffectButton.render(&window);
        scoreMultiplierButton.render(&window);
        hintButton.render(&window);
        powerupButton.render(&window);
        backButton.render(&window);

        window.draw(soundSlider);
        window.draw(soundHandle);
        window.draw(valueText);
        
        // Cursor blinking
        if (cursorTimer.getElapsedTime() >= cursorInterval)
        {
            showTimeCursor = !showTimeCursor;
            showDimensionCursor = !showDimensionCursor;
            showLimitCursor = !showLimitCursor;

            cursorTimer.restart();
        }

        // Update cursor position
        timeCursor.setPosition(timerBox.getPosition().x + timeInputText.getLocalBounds().width + 2, timerBox.getPosition().y + 3);
        dimensionCursor.setPosition(dimensionBox.getPosition().x + dimensionInputText.getLocalBounds().width + 2, timerBox.getPosition().y + 3);
        limitCursor.setPosition(wordLimitBox.getPosition().x + limitInputText.getLocalBounds().width + 2, timerBox.getPosition().y + 3);

        window.draw(timerBox);
        window.draw(timeInputText);

        window.draw(dimensionBox);
        window.draw(dimensionInputText);

        window.draw(wordLimitBox);
        window.draw(limitInputText);
        
        // Draw cursor if it's visible
        if (showTimeCursor)
            window.draw(timeCursor);
        if (showLimitCursor)
            window.draw(limitCursor);
        if (showLimitCursor)
            window.draw(dimensionCursor);
        
        // Display the window
        window.display();
    }
}

void gameScreen(sf::RenderWindow& window, Settings &userSettings) {
    // Clear the window
    window.clear(sf::Color::White);

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("Poppins-Black.ttf")) {
        return;
    }

    // Calculate relative positions and sizes based on window size
    float windowWidth = static_cast<float>(window.getSize().x);
    float windowHeight = static_cast<float>(window.getSize().y);
    sf::Vector2f titlePosition(windowWidth * 0.100f, windowHeight * 0.033f);

    // Create the title text
    Text titleText(font, "Game", static_cast<int>(windowHeight * 0.08f), sf::Color::White, sf::Color::Black, 6.0f, titlePosition);

    Board board(300.f, 300.f, 800.f, 800.f, &font, "Example Board");
    board.fillBoard(4, 4) ;

    // Game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                }
            }
        }

        window.clear();

        titleText.render(window);
        board.render(&window);
        
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