#include "State.h"

class MainMenuState:
    public State
{
private:
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget& target = NULL);
};