#include <SFML/Graphics.hpp>
#include "Card.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GO Fish");
    //main game loop
    while(window.isOpen())
    {
        sf::RectangleShape RS(sf::Vector2f(100.f, 100.f));
        sf::Texture t;
        Card club1 = Card(RS, 1, 'c', "CLUB-1.jpg");
        
       
      //Stages for go Fish
        //start of game intailizeing deck shuffle dealing 
        //ends when deck runs out

        window.clear();
        club1.draw(window, 550, 550);
        window.display();
    }

    return 0;
}