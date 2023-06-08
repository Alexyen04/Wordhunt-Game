#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
public:
    GameState();
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

private:
    void update(const float& dt);
    void render(sf::RenderWindow* window = nullptr);
    void endState();
};

#endif