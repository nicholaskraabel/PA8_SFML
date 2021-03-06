
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "DeckConstruction.h"
#include "PA8_Header.h"
#include "Player.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Test.h"
/**
 |    Assignment:  PA8
 |
 |        Authors:  Nicholas Kraabel, Daniel Clawson, Sebastian Mercado 
 |                  (fourth person in the group never responsed to the email)
 |
 |         Class:  Cpts 122 - Data Structures
 |
 |    Instructor:  Nadra Guizani
 |
 |Date completed:  12/4/2020
 |
 |      Comments: You should reference the instruction set text file for gameplay menchanics
 |                The test functions run at begining creating each element seperatly at begining in the console
 |
 */
int main()
{
    int input = 0;
    int mouse_x = 0;
    int mouse_y = 0;
    bool Go_Fishing = true;
    int card_user = 0;
    char s_user = '\0';
    int player = -1;
    int centered = 0;

    //test functions
    Test test;
    test.gameDeckTest();
    test.fillhandTest();
    test.askTest();
    test.drawTest();
    test.shuffleTest();

    sf::RenderWindow window(sf::VideoMode(1700, 950), "Go Fish");



    //creating all the elements
    std::stack<Card> deck, discard;
    Card deckCard = Card(1, 's', "no");
    gameDeck(deck);
    HumanPlayer P1 = HumanPlayer(1);
    P1.fillHand(deck);
    AIPlayer P2 = AIPlayer(2);
    P2.fillHand(deck);
    AIPlayer P3 = AIPlayer(3);
    P3.fillHand(deck);
    AIPlayer P4 = AIPlayer(4);
    P4.fillHand(deck);
    std::string message = "Welcome to Go Fish";
    bool flip = false;


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


        //Controls
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            mouse_x = mousePos.x;
            mouse_y = mousePos.y;

            if (mouse_y < 380 && mouse_y >280)
            {
                if (mouse_x < 390 && mouse_x >290)
                    Go_Fishing = true;
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


        
        //checking for game ending condtion
        if (P1.hand.empty() || P2.hand.empty() || P3.hand.empty() || P4.hand.empty())
        {
            message = "Game Over!";
            flip = true;
            centered = 35;
        }


        window.clear();
        draw_window(window); // displays the main board with players
        draw_menu(window);  // displays the menu
        draw_message_board(window); // displays the message board
        draw_user_input_box(window); // displays the user input board
        draw_user_input(window, s_user);  // display user input
        draw_player_input_boxes(window); // display Player choice boxes
        draw_go_fishing_message(window, message, centered); // displays for you to go fish
        P1.displayHand(window);
        P2.displayHand(window, flip);
        P3.displayHand(window,flip);
        P4.displayHand(window, flip);
        P1.displayscore(window);
        P2.displayscore(window);
        P3.displayscore(window);
        P4.displayscore(window);
        if (!discard.empty())
            discard.top().draw(window, 1565, 650, 0);
        if (!deck.empty())
            deckCard.drawBack(window, 1125, 405.5, 0);


        window.display();  // ouputs the window

        //main game logic
        if (Go_Fishing)
        {
            std::srand(std::time(nullptr));
            if (s_user == '\0' || player == -1)
            {
                std::cout << "You need to select a player and a card" << std::endl;
            }

            else
            {
                //human
                std::cout << "C: " << card_user << " P: " << player - 1 << std::endl;
                switch (player)
                {
                case(2):
                    P1.askForCard(P2, card_user, deck, discard);
                    break;
                case(3):
                    P1.askForCard(P3, card_user, deck, discard);
                    break;
                case(4):
                    P1.askForCard(P4, card_user,deck, discard);
                    break;
                }

                // Ai P1
                int selector = std::rand() % 3, selHand;
                selHand = P2.selectCard();
                std::cout << "C: " << selHand;
                switch (selector)
                {
                case(0):
                    std::cout << " P1: P" << std::endl;
                    P2.askForCard(P1, selHand, deck, discard);
                    break;
                case(1):
                    std::cout << " P1: 2" << std::endl;
                    P2.askForCard(P3, selHand, deck, discard);
                    break;
                case(2):
                    std::cout << " P1: 3" << std::endl;
                    P2.askForCard(P4, selHand, deck, discard);
                    break;
                }

                //AI P2
                selector = std::rand() % 3;
                selHand = P3.selectCard();
                std::cout << "C: " << selHand;
                switch (selector)
                {
                case(0):
                    std::cout << " P2: P" << std::endl;
                    P3.askForCard(P1, selHand, deck, discard);
                    break;
                case(1):
                    std::cout << " P2: 1" << std::endl;
                    P3.askForCard(P2, selHand, deck, discard);
                    break;
                case(2):
                    std::cout << " P2: 3" << std::endl;
                    P3.askForCard(P4, selHand, deck, discard);
                    break;
                }

                //AI P3
                selector = std::rand() % 3;
                selHand = P4.selectCard();
                std::cout << "C: " << selHand;
                switch (selector)
                {
                case(0):
                    std::cout << " P3: P" << std::endl;
                    P4.askForCard(P1, selHand, deck, discard);
                    break;
                case(1):
                    std::cout << " P3: 1" << std::endl;
                    P4.askForCard(P2, selHand, deck, discard);
                    break;
                case(2):
                    std::cout << " P3: 2" << std::endl;
                    P4.askForCard(P3, selHand, deck, discard);
                    break;
                }
                std::cout << "\n|End of round|\n"; 
                

                player = -1;
                card_user = 0;
                s_user = '\0';


            }
            Go_Fishing = false;


        }

    }


    return 0;
}