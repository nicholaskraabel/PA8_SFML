
#include "PA8_Header.h"
#include <time.h>
#include <string>

/*************
Daniel
11/29/2020
**************/
void draw_window(sf::RenderTarget& window)
{
    

    //for the text
    sf::Font font;
    if (!font.loadFromFile("Roboto-Black.ttf")) // select the font
        throw("Could not load font");

    //board
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(650, 650));
    rec.setOutlineThickness(20);
    rec.setFillColor(sf::Color::Green);
    rec.setPosition(850, 150);

    //SCORE 3 NOT 1 board-title
    sf::RectangleShape score1;
    score1.setSize(sf::Vector2f(50, 50));
    score1.setOutlineThickness(10);
    score1.setFillColor(sf::Color::Cyan);
    score1.setPosition(1235, 50);
    sf::Text text_s1;
    text_s1.setFont(font);
    text_s1.setString("Score");// set the string to display
    text_s1.setCharacterSize(20); // set the character size in pixels, not points! 
    text_s1.setFillColor(sf::Color::Cyan); // set the color
    text_s1.setStyle(sf::Text::Italic); // set the text style
    text_s1.setPosition(1233, 18);

    // SCORE 4 NOT 2 board-title
    sf::RectangleShape score2;
    score2.setSize(sf::Vector2f(50, 50));
    score2.setOutlineThickness(10);
    score2.setFillColor(sf::Color::Cyan);
    score2.setPosition(1588, 470);
    sf::Text text_s2;
    text_s2.setFont(font);
    text_s2.setString("Score");// set the string to display
    text_s2.setCharacterSize(20); // set the character size in pixels, not points! 
    text_s2.setFillColor(sf::Color::Cyan); // set the color
    text_s2.setStyle(sf::Text::Italic); // set the text style
    text_s2.setPosition(1586, 438);

    //SCORE YOU NOT 3 board-title
    sf::RectangleShape score3;
    score3.setSize(sf::Vector2f(50, 50));
    score3.setOutlineThickness(10);
    score3.setFillColor(sf::Color::Cyan);
    score3.setPosition(1235, 872);
    sf::Text text_s3;
    text_s3.setFont(font);
    text_s3.setString("Score");// set the string to display
    text_s3.setCharacterSize(20); // set the character size in pixels, not points! 
    text_s3.setFillColor(sf::Color::Cyan); // set the color
    text_s3.setStyle(sf::Text::Italic); // set the text style
    text_s3.setPosition(1233, 840);

    // SCORE 1 NOT 4 board-title
    sf::RectangleShape score4;
    score4.setSize(sf::Vector2f(50, 50));
    score4.setOutlineThickness(10);
    score4.setFillColor(sf::Color::Cyan);
    score4.setPosition(720, 470);
    sf::Text text_s4;
    text_s4.setFont(font);
    text_s4.setString("Score");// set the string to display
    text_s4.setCharacterSize(20); // set the character size in pixels, not points! 
    text_s4.setFillColor(sf::Color::Cyan); // set the color
    text_s4.setStyle(sf::Text::Italic); // set the text style
    text_s4.setPosition(718, 438);
    
    // TITLE
    sf::Text text_t;
    text_t.setFont(font);
    text_t.setString("Go Fish");// set the string to display
    text_t.setCharacterSize(70); // set the character size in pixels, not points! 
    text_t.setFillColor(sf::Color::Yellow); // set the color
    text_t.setStyle(sf::Text::Bold); // set the text style
    text_t.setPosition(700, 25);

    // Player 2 NOT 1
    sf::Text text_1;
    text_1.setFont(font);
    text_1.setString("Player 2");// set the string to display
    text_1.setCharacterSize(30); // set the character size in pixels, not points!
    text_1.setFillColor(sf::Color::Yellow); // set the color
    text_1.setStyle(sf::Text::Bold); // set the text style
    text_1.setPosition(1075, 50);

    // Player 3 NOT 2
    sf::Text text_2;
    text_2.setFont(font);
    text_2.setString("Player 3");// set the string to display
    text_2.setCharacterSize(30); // set the character size in pixels, not points! 
    text_2.setFillColor(sf::Color::Yellow); // set the color
    text_2.setStyle(sf::Text::Bold); // set the text style
    text_2.setPosition(1555, 400);
    
    // Player "YOU" NOT 3
    sf::Text text_3;
    text_3.setFont(font);
    text_3.setString("You");// set the string to display
    text_3.setCharacterSize(30); // set the character size in pixels, not points! 
    text_3.setFillColor(sf::Color::Yellow); // set the color
    text_3.setStyle(sf::Text::Bold); // set the text style
    text_3.setPosition(1140, 870);

    // Player 1 NOT 4
    sf::Text text_4;
    text_4.setFont(font);
    text_4.setString("Player 1");// set the string to display
    text_4.setCharacterSize(30); // set the character size in pixels, not points! 
    text_4.setFillColor(sf::Color::Yellow); // set the color
    text_4.setStyle(sf::Text::Bold); // set the text style
    text_4.setPosition(685, 400);

    //Discard text
    sf::Text text_5; 
    text_5.setFont(font);
    text_5.setString("Discard");// set the string to display
    text_5.setCharacterSize(30); // set the character size in pixels, not points! 
    text_5.setFillColor(sf::Color::Yellow); // set the color
    text_5.setStyle(sf::Text::Bold); // set the text style
    text_5.setPosition(1555, 610);

    window.draw(rec); // output board
    window.draw(text_t); // output title
    window.draw(score1); // output score board 2
    window.draw(text_s1); // output score 2 tile
    window.draw(score2); // output score board 3
    window.draw(text_s2); // output score 3 tile
    window.draw(score3); // output score board 3
    window.draw(text_s3); // output score you tile
    window.draw(score4); // output score board 1
    window.draw(text_s4); // output score 2 tile
    window.draw(text_1); // output Player 2
    window.draw(text_2); // output Player 3
    window.draw(text_3); // output Player you
    window.draw(text_4); // output Player 1
    window.draw(text_5); // discard pile.


}

/*
Daniel Clawson
12/1/2020
*/
void draw_go_fishing_message(sf::RenderTarget& window, std::string message, int center)
{
    sf::Font font2;
    if (!font2.loadFromFile("Star Trebek.otf")) // select the font
        throw("Could not load font");

    // Go Fish text
    sf::Text g_f;
    g_f.setFont(font2);
    g_f.setString(message);// set the string to display
    g_f.setCharacterSize(50); // set the character size in pixels, not points! 
    g_f.setFillColor(sf::Color::Yellow); // set the color
    g_f.setStyle(sf::Text::Bold); // set the text style
    g_f.setPosition(220 + center, 820);


    window.draw(g_f);

}

/*We do not use this function*/
void drawEndWindow(sf::RenderTarget& window, int sc1, int sc2, int sc3, int sc4)
{
    sf::Font font;
    if (!font.loadFromFile("Roboto-Black.ttf")) // select the font
        throw("Could not load font");
    sf::Text title;
    title.setFont(font);
    std::string str = "The final scores for Go Fish Game.";
    title.setString(str);
    title.setCharacterSize(65);
    title.setFillColor(sf::Color::Blue);
    title.setStyle(sf::Text::Bold);
    title.setPosition(300, 150);

    sf::Text text1;
    text1.setFont(font);
    text1.setString(std::to_string(sc1));// set the string to display
    text1.setCharacterSize(30); // set the character size in pixels, not points! 
    text1.setFillColor(sf::Color::Black); // set the color
    text1.setStyle(sf::Text::Bold); // set the text style
    text1.setPosition(112.5, 337.5);
    sf::RectangleShape score1;
    score1.setSize(sf::Vector2f(75, 75));
    score1.setOutlineThickness(8);
    score1.setFillColor(sf::Color::Red);
    score1.setPosition(75, 300);

    sf::Text text2;
    text2.setFont(font);
    text2.setString(std::to_string(sc2));// set the string to display
    text2.setCharacterSize(30); // set the character size in pixels, not points! 
    text2.setFillColor(sf::Color::Black); // set the color
    text2.setStyle(sf::Text::Bold); // set the text style
    text2.setPosition(262.5, 337.5);
    sf::RectangleShape score2;
    score2.setSize(sf::Vector2f(75, 75));
    score2.setOutlineThickness(8);
    score2.setFillColor(sf::Color::Red);
    score2.setPosition(225, 300);

    sf::Text text3;
    text3.setFont(font);
    text3.setString(std::to_string(sc3));// set the string to display
    text3.setCharacterSize(30); // set the character size in pixels, not points! 
    text3.setFillColor(sf::Color::Black); // set the color
    text3.setStyle(sf::Text::Bold); // set the text style
    text3.setPosition(412.5, 337.5);
    sf::RectangleShape score3;
    score3.setSize(sf::Vector2f(75, 75));
    score3.setOutlineThickness(8);
    score3.setFillColor(sf::Color::Red);
    score3.setPosition(375, 300);

    sf::Text text4;
    text4.setFont(font);
    text4.setString(std::to_string(sc4));// set the string to display
    text4.setCharacterSize(30); // set the character size in pixels, not points! 
    text4.setFillColor(sf::Color::Black); // set the color
    text4.setStyle(sf::Text::Bold); // set the text style
    text4.setPosition(562.5, 337.5);
    sf::RectangleShape score4;
    score4.setSize(sf::Vector2f(75, 75));
    score4.setOutlineThickness(8);
    score4.setFillColor(sf::Color::Red);
    score4.setPosition(525, 300);


    window.clear();
    window.draw(title);
    window.draw(score1);
    window.draw(text1);
    window.draw(score2);
    window.draw(text2);
    window.draw(score3);
    window.draw(text3);
    window.draw(score4);
    window.draw(text4);
    

}