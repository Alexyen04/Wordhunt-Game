#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
public:
    Game();
    virtual ~Game();

    void updateSFMLevents();
    void update();
    void run();
    void render();

private:
    void initWindow() ;
    void initStates() ;

    sf::RenderWindow* window; // Added 'window' member variable
    sf::Event sfEvent; // Added 'sfEvent' member variable

    sf::Clock dtclock ;
    float dt ;

    std::stack<State*> states ;

};

#endif
