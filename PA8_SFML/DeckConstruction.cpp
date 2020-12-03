//This the deck constructor it return the reference of an array of the cards.
#include "Card.h"
#include <string>
#include <stack>
void deckConstuctor(Card(&deck)[deckSize])
{
	std::string suit, fileTag;
	char s;
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			suit = "CLUB-";
			s = 'c';
			break;
		case 1:
			suit = "DIAMOND-";
			s = 'd';
			break;
		case 2:
			suit = "HEART-";
			s = 'h';
			break;
		case 3:
			suit = "SPADE-";
			s = 's';
		}
		for (int j = 1; j <= 13; j++)
		{
		    if (j == 11)
				fileTag = suit + std::to_string(j) + "-JACK.jpg";
			else if (j == 12)
				fileTag = suit + std::to_string(j) + "-QUEEN.jpg";
			else if (j == 13) 
				fileTag = suit + std::to_string(j) + "-KING.jpg";
			else
				fileTag = suit + std::to_string(j) + ".jpg";

			deck[count] = Card(j, s, fileTag);
			count++;
		}

	}
}

void gameDeck(std::stack <Card>& finalDeck)
{
	Card deck[52];
	deckConstuctor(deck);
	//shuffle function

	while (!finalDeck.empty())
	{
		finalDeck.pop();
	}
	for (int i = 0; i < 52; i++)
	{
		finalDeck.push(deck[i]);
	}


}