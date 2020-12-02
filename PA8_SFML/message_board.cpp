

#include "PA8_Header.h"

/*
Daniel Clawson
12/1/2020
*/
void draw_message_board(sf::RenderTarget& window)
{
    //Message board
    sf::RectangleShape rec_m;
    rec_m.setSize(sf::Vector2f(600, 100));
    rec_m.setOutlineThickness(20);
    rec_m.setFillColor(sf::Color::Blue);
    rec_m.setPosition(100, 800);


    window.draw(rec_m);

}