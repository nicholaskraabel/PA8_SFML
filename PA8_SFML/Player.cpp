#include "Player.h"
#include "Card.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <stack>
#include <iostream>

bool compare(Card &c1, Card &c2)
{
	if (c1.getFaceValue() == c2.getFaceValue())
		return true;
	return false;
}

void Player::fillHand(std::stack <Card>& deck)
{
	std::list<Card>::iterator itr = hand.begin();
	for (int i = 0; i < 5; i++)
	{
		Card temp = deck.top();
		*itr = temp;
		deck.pop();
		itr++;
	}
	hand.sort(compare);
}

void HumanPlayer::displayHand(sf::RenderTarget &window)
{
	//don't know the exact coordinates but it will be something like this
	float startPt = (hand.size() * 15 - 1000/*size of the window*/) / 2.0;
	std::list<Card>::iterator itr = hand.begin();
	for (int i = 0; i < hand.size(); i++)
	{
		itr->draw(window, startPt + (i * 15), 500, 0.f);
		itr++;
	}


}


void AIPlayer::displayHand(sf::RenderTarget& window)
{
	//don't know the exact coordinates but it will be something like this
	switch (playerNum)
	{
	case(2):
		//put in the numbers
		break;
	case(3):
		//addd numbers
		break;
	case(4):
		//add stuff
		break;
	default:
		std::cout << "Something bad happen. (I don't know how this happen)\n";

	}
	float startPt = (hand.size() * 15 - 1000/*size of the window*/) / 2.0;
	std::list<Card>::iterator itr = hand.begin();
	for (int i = 0; i < hand.size(); i++)
	{
		itr->drawBack(window, 100, 100, 90);
	}


}

void Player::askForCard(Player& target, int card)
{
	Card tempHold[4];
	int tracker = 0;
	std::list<Card>::iterator itr = target.hand.begin();
	for(int i = 0; i < target.hand.size(); i++)
	{
		if (itr->getFaceValue() == card)
		{
			tempHold[tracker] = *itr;
			itr = target.hand.erase(itr);

			tracker++;
		}

		itr++;
	}
	for (int i = 0; i < tracker; i++)
	{
		hand.push_back(tempHold[i]);
	}
	//really hopeful this just works
	hand.sort(compare); 
}

int AIPlayer::selectCard()
{
	//This is a modified counting sort 
	//adds one at the index of face value of the card
	//then selects value with the highest number filtering out four out a kinds 
	int tracker = 0;
	int CM[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	std::list<Card>::iterator itr = hand.begin();
	for (int i = 0; i < hand.size(); i++)
	{
		CM[itr->getFaceValue()-1]++;
		itr++;
	}
	//getting index of max
	int Index, max = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (CM[i - 1] == 4)
		{
			//playCardSet() write this later
		}
		else 
		{
			if (max < CM[i - 1])
			{
				max = CM[i - 1];
				Index = i;
			}
		}
	}
	return Index;
}