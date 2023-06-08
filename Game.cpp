#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

void Game::initWindow()
{
   this -> window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML WordHunt") ;
}

void Game::initStates() 
{
    this -> states.push(new GameState(this -> window)) ;
}

Game::Game()
{
    this -> initWindow() ;
    this -> initStates() ;
}


Game::~Game()
{
   delete this -> window ;

   while (this -> states.empty() )
   {
        delete this -> states.top() ;
        this -> states.pop() ;
   }
}


void Game::update()
{
    this -> updateSFMLevents() ;

    if (this -> states.empty())
    {
        this -> states.top() -> update(this -> dt) ;
    }    
}


void Game::render()
{
    this -> window -> clear() ;

    if (this -> states.empty())
    {
        this -> states.top() -> render() ;
    }

    this -> window -> display() ;
}


void Game::run()
{
    while (this -> window -> isOpen())
    {
        this -> update() ;
        this -> render() ;
    }
}


void Game::updateSFMLevents()
{
    while ( this -> window -> pollEvent(this -> sfEvent))
    {
        if (this -> sfEvent.type == sf::Event::Closed)
        {
            this -> window -> close() ;
        }
    }
}