//The Card Class
#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>

//This may want to be move just needs to be in a collective header file.
int const deckSize = 52;

class Card {
private:
    int facevalue;
    char suit;
    std::string fileIdentifier;

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
    void draw(sf::RenderTarget &, float, float);
    void drawBack(sf::RenderTarget&, float, float);
    bool compare(Card);

};