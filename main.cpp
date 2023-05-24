#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace std;

sf::Vector2f getMousePosition(const sf::RenderWindow& window) {
    sf::Vector2<int> intVector = sf::Mouse::getPosition(window);
    sf::Vector2<float> floatVector;
    floatVector.x = static_cast<float>(intVector.x);
    floatVector.y = static_cast<float>(intVector.y);
    return floatVector;
}

int main(){
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Modified Word Hunt");

    //testing gif features
    sf::Texture gifTexture;
    if (!gifTexture.loadFromFile("main_menu.gif")){
        // Error handling if the image cannot be loaded
        return 1;
    }

    sf::Sprite gifSprite(gifTexture);
    gifSprite.setScale(
        static_cast<float>(window.getSize().x) / gifSprite.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / gifSprite.getLocalBounds().height
    );

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

    // print button
    Button* gamestate_btn = new Button(540, 800, 190, 100, font, "New Game", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button* gamestate_btn_2 = new Button(540, 1060, 325, 100, font, "New Game", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));


    // Game loop
    while (window.isOpen()){
        // Handle events
        sf::Event event;
        sf::Vector2f mousePos = getMousePosition(window);
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //tracking of mouse

            sf::Vector2f mousePos = getMousePosition(window);
            cout << "Mouse position: X = " << mousePos.x << ", Y = " << mousePos.y << endl;
            
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

        window.clear();
        window.draw(gifSprite);

        // Draw the title
        window.draw(titleText);

        // Draw the buttons
        window.draw(playText);
        window.draw(settingsText);
        
        gamestate_btn->update(mousePos);
        gamestate_btn->render(&window);
        gamestate_btn_2->update(mousePos);
        gamestate_btn_2->render(&window);

        // Display the window
        window.display();
    }

    return EXIT_SUCCESS;
}
