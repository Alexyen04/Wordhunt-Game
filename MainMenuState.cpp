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
