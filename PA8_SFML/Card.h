//The Card Class
#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>

int const deckSize = 52;

class Card {
private:
    int facevalue;
    char suit;
    std::string fileIdentifier; //used for locating texture

public:
    Card()
    {
        facevalue = -1;
        suit = '-1';
        fileIdentifier = "undefined";

    }
    Card(int fv, char s, std::string fi)
    {
        facevalue = fv;
        suit = s;
        //file tags my need folder tag put in front of it
        fileIdentifier = "CardTextures\\" + fi;
    }
    ~Card()
    {}
    int getFaceValue();
    char getSuit();
    //draws the front face of the card
    void draw(sf::RenderTarget &, float, float, float);
    //draws the back side of the card
    void drawBack(sf::RenderTarget&, float, float, float);
    //compares face value
    int compare(Card);

};