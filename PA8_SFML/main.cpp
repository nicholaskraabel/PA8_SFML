#include <SFML/Graphics.hpp>
#include "Card.h"
#include "DeckConstruction.h"
#include <Windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "GO Fish");
    //main game loop
    while (window.isOpen())
    {


        //Stages for go Fish
          //start of game intailizeing deck shuffle dealing 
          //ends when deck runs out
        Card deck[deckSize]; 
        deckConstuctor(deck); 
        window.clear();
        for (int i = 0; i < 52; i++)
        {
            deck[i].draw(window, 80 + (i * 15), 500);
        }
        deck[0].drawBack(window, 450, 150);
        window.display();
        Sleep(100000);
        window.close();
    }

    return 0;
}