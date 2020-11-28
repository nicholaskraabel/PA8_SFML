#include <SFML/Graphics.hpp>
#include "Card.h"

void Card::draw(sf::RenderTarget &window, sf::RenderStates state, int locX, int locY)
{
    cardBackground.setPosition(locX, locY);


    window.draw(cardBackground);


    
}