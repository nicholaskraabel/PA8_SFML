

#include "Header.h"


int menu(sf::RenderTarget& window)
{
    sf::Font font1;
    if (!font1.loadFromFile("Roboto-Black.ttf")) // select the font
        throw("Could not load font");

    sf::Font font2;
    if (!font2.loadFromFile("Star Trebek.otf")) // select the font
        throw("Could not load font");

    // TITLE
    sf::Text Menu;
    Menu.setFont(font1);
    Menu.setString("Menu");// set the string to display
    Menu.setCharacterSize(50); // set the character size in pixels, not points! 
    Menu.setFillColor(sf::Color::Yellow); // set the color
    Menu.setStyle(sf::Text::Bold); // set the text style
    Menu.setPosition(300, 100);



    //Menu board
    sf::RectangleShape rec_m;
    rec_m.setSize(sf::Vector2f(300, 600));
    rec_m.setOutlineThickness(20);
    rec_m.setFillColor(sf::Color::Blue);
    rec_m.setPosition(200, 200);



    window.draw(rec_m);
    window.draw(Menu);

}