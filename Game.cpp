#include "Game.h"


void Game::initWindow()
{
   this -> window = new sf::RenderWindow(sf::VideoMode(800, 600), "C++ SFML WordHunt") ;


}


Game::Game()
{


}


Game::~Game()
{
   delete this -> window ;
}


void Game::update()
{


}


void Game::render()
{


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
