#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

void Game::initWindow()
{
   this -> window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML WordHunt") ;
}


Game::Game()
{
    this -> initWindow() ;
}


Game::~Game()
{
   delete this -> window ;
}


void Game::update()
{
    this -> updateSFMLevents() ;
}


void Game::render()
{
    this -> window -> clear() ;
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
