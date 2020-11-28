#include <SFML/Graphics.hpp>
#include <string.h>

class Card : public sf::Drawable, sf::Transformable {
private:
    sf::RectangleShape cardBackground;
    char facevalue;
    char suit;
    std::string fileIdentifier;
    sf::Texture texture;

public:
    virtual void draw(sf::RenderTarget &, sf::RenderStates, int, int); 

};