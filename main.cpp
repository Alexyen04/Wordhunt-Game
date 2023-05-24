#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Game.h"
using namespace std;

sf::Vector2i getMousePosition(const sf::RenderWindow& window) {
    return sf::Mouse::getPosition(window);
}

int main(){
    Game WordHunt ;

    WordHunt.run() ;

    return 0 ;
}
