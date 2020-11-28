#include <SFML/Graphics.hpp>
#include "Card.h"

int Card::getFaceValue()
{
    return facevalue; 
}
char Card::getSuit()
{
    return suit; 
}

void Card::draw(sf::RenderTarget &window, float xLoc, float yLoc ) //may add render state later to help stop repeat rendering 
{
    sf::Texture Ctexture;
    card.setPosition(550, 550);
    Ctexture.loadFromFile(fileIdentifier);
    card.setTexture(&Ctexture);
    window.draw(card);

    // changed here
    
}
//returns true if they are equal(suit and facevalue) and returns false otherwise
bool Card::compare(Card c2)
{
    if (facevalue == c2.getFaceValue() && suit == c2.getSuit())
        return true;
    return false;
}