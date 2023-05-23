#include "MainMenuState.h"

void MainMenuState::initKeybinds() {
    std::ifstream ifs("Config/gamestate_keybinds.ini");

    if(ifs.is_open()) {
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2) {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }
    ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {
    this->initKeybinds();
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::endState() {
    std::cout << "Ending GameState" << "\n";
}

void MainMenuState::updateInput(const float & dt) {
    this->checkForQuit();

    //update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.get("MOVE_LEFT")))) {
        this->player.move(dt, -1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.get("MOVE_RIGHT")))) {
        this->player.move(dt, 1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.get("MOVE_UP")))) {
        this->player.move(dt, 0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.get("MOVE_DOWN")))) {
        this->player.move(dt, 0.f, 1.f);
    }
}

void MainMenuState::update(const float& dt) {
    this->updateInput(dt);
    this->player.update(dt);
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target) {
        target = this->window;
    }
    this->player.render(target);
}