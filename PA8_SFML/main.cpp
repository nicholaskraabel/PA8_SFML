#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GO Fish");
    //main game loop
    while(window.isOpen())
    {
        sf::RectangleShape RS;
        RS.setFillColor(sf::Color::Red);
        RS.setPosition(500, 500);
       
      //Stages for go Fish
        //start of game intailizeing deck shuffle dealing 
        //ends when deck runs out

        window.clear();
        window.draw(RS);
        window.display();
    }

    return 0;
}