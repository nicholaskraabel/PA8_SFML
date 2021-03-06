#include <SFML/Graphics.hpp>
#include <iostream>
#include "Card.h"
//edited these

int Card::getFaceValue()
{
    return facevalue; 
}
char Card::getSuit()
{
    return suit; 
}

void Card::draw(sf::RenderTarget &window, float xLoc, float yLoc, float rotation) //may add render state later to help stop repeat rendering 
{
    if (facevalue == -1)
    {
        std::cout << "Card is undefined, can not be display." << std::endl;
        return;
    }
    sf::Texture Ctexture;
    sf::RectangleShape card(sf::Vector2f(100.f, 139.f));
    card.setRotation(rotation);
    card.setPosition(xLoc, yLoc);
    Ctexture.loadFromFile(fileIdentifier);
    card.setTexture(&Ctexture);
    window.draw(card);

    
}

void Card::drawBack(sf::RenderTarget& window, float xLoc, float yLoc, float rotation) //may add render state later to help stop repeat rendering 
{
    if (facevalue == -1)
    {
        std::cout << "Card is undefined, can not be display." << std::endl;
        return;
    }
    sf::Texture Ctexture;
    sf::RectangleShape card(sf::Vector2f(100.f, 139.f));
    card.setRotation(rotation);
    card.setPosition(xLoc, yLoc);
    Ctexture.loadFromFile("CardTextures\\BackOfCard.jpg");
    card.setTexture(&Ctexture);
    window.draw(card);


}
//returns true if they are equal(suit and facevalue) and returns false otherwise
int Card::compare(Card c2)
{
    return facevalue < c2.getFaceValue();
}