

#include "PA8_Header.h"

/*
Daniel Clawson
12/1/2020
*/
void draw_menu(sf::RenderTarget& window)
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
    Menu.setPosition(300, 50);



    //Menu board
    sf::RectangleShape rec_m;
    rec_m.setSize(sf::Vector2f(300, 300));
    rec_m.setOutlineThickness(20);
    rec_m.setFillColor(sf::Color::Blue);
    rec_m.setPosition(200, 150);


    // Go Fish text
    sf::Text g_f;
    g_f.setFont(font2);
    g_f.setString("Go Fish");// set the string to display
    g_f.setCharacterSize(50); // set the character size in pixels, not points! 
    g_f.setFillColor(sf::Color::Yellow); // set the color
    g_f.setStyle(sf::Text::Bold); // set the text style
    g_f.setPosition(280, 175);


    //go fish dot
    sf::RectangleShape rec_red;
    rec_red.setSize(sf::Vector2f(100, 100));
    rec_red.setOutlineThickness(10);
    rec_red.setFillColor(sf::Color::Red);
    rec_red.setPosition(290, 280);

    window.draw(rec_m);
    //window.draw(Menu);  // draws MENU
    window.draw(rec_red);
    window.draw(g_f);
}


/*
Daniel Clawson
12/2/2020
*/
void draw_player_input_boxes(sf::RenderTarget& window)
{
    sf::Font font1;
    if (!font1.loadFromFile("Roboto-Black.ttf")) // select the font
        throw("Could not load font");

    // PL 1 blue dot
    sf::RectangleShape rec_red_1;
    rec_red_1.setSize(sf::Vector2f(100, 100));
    rec_red_1.setOutlineThickness(20);
    rec_red_1.setFillColor(sf::Color::Blue);
    rec_red_1.setPosition(50, 600);

    // PL 2 blue dot
    sf::RectangleShape rec_red_2;
    rec_red_2.setSize(sf::Vector2f(100, 100));
    rec_red_2.setOutlineThickness(20);
    rec_red_2.setFillColor(sf::Color::Blue);
    rec_red_2.setPosition(215, 600);

    // PL 3 blue dot
    sf::RectangleShape rec_red_3;
    rec_red_3.setSize(sf::Vector2f(100, 100));
    rec_red_3.setOutlineThickness(20);
    rec_red_3.setFillColor(sf::Color::Blue);
    rec_red_3.setPosition(380, 600);


    sf::Text P1;
    P1.setFont(font1);
    P1.setString("P1");// set the string to display
    P1.setCharacterSize(50); // set the character size in pixels, not points! 
    P1.setFillColor(sf::Color::Yellow); // set the color
    P1.setStyle(sf::Text::Bold); // set the text style
    P1.setPosition(70, 615);

    sf::Text P2;
    P2.setFont(font1);
    P2.setString("P2");// set the string to display
    P2.setCharacterSize(50); // set the character size in pixels, not points! 
    P2.setFillColor(sf::Color::Yellow); // set the color
    P2.setStyle(sf::Text::Bold); // set the text style
    P2.setPosition(235, 615);

    sf::Text P3;
    P3.setFont(font1);
    P3.setString("P3");// set the string to display
    P3.setCharacterSize(50); // set the character size in pixels, not points! 
    P3.setFillColor(sf::Color::Yellow); // set the color
    P3.setStyle(sf::Text::Bold); // set the text style
    P3.setPosition(400, 615);


    window.draw(rec_red_1); // display 1's blue square.
    window.draw(rec_red_2);
    window.draw(rec_red_3);

    window.draw(P1);
    window.draw(P2); // displays P2
    window.draw(P3);

}

/*
Daniel Clawson
12/2/2020
*/
void draw_user_input_box(sf::RenderTarget& window)
{
    // user input board
    sf::RectangleShape rec_u;
    rec_u.setSize(sf::Vector2f(100, 100));
    rec_u.setOutlineThickness(20);
    rec_u.setFillColor(sf::Color::Blue);
    rec_u.setPosition(550, 600);

    window.draw(rec_u);

}


/*
Daniel Clawson
12/2/2020
*/
void draw_user_input(sf::RenderTarget& window, char s_user)
{

    sf::Font font2;
    if (!font2.loadFromFile("Star Trebek.otf")) // select the font
        throw("Could not load font");

    sf::Text g_f;


    if (s_user == '1')
    {     
        g_f.setString("10");// set the string to display
    }
    else
    { 
        g_f.setString(s_user);// set the string to display
    }

    g_f.setFont(font2);
    g_f.setCharacterSize(50); // set the character size in pixels, not points! 
    g_f.setFillColor(sf::Color::Yellow); // set the color
    g_f.setStyle(sf::Text::Bold); // set the text style
    g_f.setPosition(590, 610);

    window.draw(g_f);
}



/*Could not get this to return the 1 so will not use*/
/*
Daniel Clawson
12/2/2020
*/
//int get_go_fish(sf::Window& window)
//{
//    int mouse_x = 0, mouse_y = 0, Go_Fishing = 0;
//
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//    {
//        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//        mouse_x = mousePos.x;
//        mouse_y = mousePos.y;
//
//        if (mouse_y < 380 && mouse_y >280)
//        {
//            if (mouse_x < 390 && mouse_x >290)
//                Go_Fishing = 1;
//        }
//    }
//    return Go_Fishing;
//}