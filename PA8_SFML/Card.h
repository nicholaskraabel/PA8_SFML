//The Card Class
#include <SFML/Graphics.hpp>
#include <string.h>

class Card {
private:
    sf::RectangleShape card;
    int facevalue;
    char suit;
    std::string fileIdentifier;

public:
    Card(sf::RectangleShape cb, int fv, char s, std::string fi)
    {
        card = cb;
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
    bool compare(Card);

};