//#include <SFML/Graphics.hpp>
//#include "Card.h"
//#include "DeckConstruction.h"
//#include <Windows.h>

#include "Header.h"

int main()
{
    int input = 0;
    //sf::RenderWindow window(sf::VideoMode(1000, 1000), "GO Fish");

    // for the board
    sf::RenderWindow window(sf::VideoMode(1700, 950), "Go Fish"); // , sf::Style::Fullscreen);
   

    //main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Stages for go Fish
          //start of game intailizeing deck shuffle dealing 
          //ends when deck runs out
        Card deck[deckSize]; 
        deckConstuctor(deck); 
        window.clear();
        /*for (int i = 0; i < 52; i++)
        {
            deck[i].draw(window, 80 + (i * 15), 500);
        }*/
        //deck[0].drawBack(window, 450, 150);
        draw_window(window); // displays the main screen
        input = menu(window);
        window.display(); 

        //Sleep(100000);
        //window.close();
    }

    return 0;
}