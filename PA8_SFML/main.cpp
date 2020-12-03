//#include <SFML/Graphics.hpp>
//#include "Card.h"
//#include "DeckConstruction.h"
//#include <Windows.h>

#include "PA8_Header.h"

int main()
{
    int input = 0;
    int mouse_x = 0;
    int mouse_y = 0;
    int Go_Fishing = 0;
    int card_user = 0;
    char s_user = '\0';
    int player = 0;

    sf::RenderWindow window(sf::VideoMode(1700, 950), "Go Fish"); 



   


    //sf::RenderWindow window(sf::VideoMode(1000, 1000), "GO Fish");
    //main game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Go_Fishing = get_go_fish(window);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            mouse_x = mousePos.x;
            mouse_y = mousePos.y;

            if (mouse_y < 380 && mouse_y >280)
            {
                if (mouse_x < 390 && mouse_x >290)
                    Go_Fishing = 1;
            }

            if (mouse_y < 700 && mouse_y >600)
            {
                if (mouse_x < 150 && mouse_x >50)
                    player = 2;
            }

            if (mouse_y < 700 && mouse_y >600)
            {
                if (mouse_x < 315 && mouse_x >215)
                    player = 3;
            }

            if (mouse_y < 700 && mouse_y >600)
            {
                if (mouse_x < 480 && mouse_x >380)
                    player = 4;
            }

            

        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            card_user = 1;
            s_user = 'A';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
        {
            card_user = 2;
            s_user = '2';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
        {
            card_user = 3;
            s_user = '3';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
        {
            card_user = 4;
            s_user = '4';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5))
        {
            card_user = 5;
            s_user = '5';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6))
        {
            card_user = 6;
            s_user = '6';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7))
        {
            card_user = 7;
            s_user = '7';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8))
        {
            card_user = 8;
            s_user = '8';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num9))
        {
            card_user = 9;
            s_user = '9';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
        {
             card_user = 10;
             s_user = '1';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
        {
            card_user = 11;
            s_user = 'J';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        {
            card_user = 12;
            s_user = 'Q';
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
        {
            card_user = 13;
            s_user = 'K';
        }


        //Stages for go Fish
          //start of game intailizeing deck shuffle dealing 
          //ends when deck runs out

        Card deck[deckSize];
        deckConstuctor(deck);
        window.clear();
        /* for (int i = 0; i < 52; i++)
         {
             deck[i].draw(window, 80 + (i * 15), 500);
         }
         deck[0].drawBack(window, 450, 150);*/

        draw_window(window); // displays the main board with players
        draw_menu(window);  // displays the menu
        draw_message_board(window); // displays the message board
        draw_user_input_box(window); // displays the user input board
        draw_user_input(window, s_user);  // display user input
        draw_player_input_boxes(window); // display Player choice boxes
        draw_go_fishing_message(window); // displays for you to go fish
        window.display();  // ouputs the window

       /* Sleep(100000);
        window.close();*/

    }


    return 0;
}