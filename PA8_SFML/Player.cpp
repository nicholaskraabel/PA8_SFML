#include "Player.h"
#include "Card.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <stack>
#include <iterator>
#include <iostream>
#include <algorithm>

bool compare(Card c1, Card c2)
{
	return c1.getFaceValue() > c2.getFaceValue();
}

void Player::scoreCards(int value, std::stack<Card> &discard)
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getFaceValue() == value)
		{
			discard.push(hand[i]);
			hand.erase(hand.begin() + i);
			score++;
		}
	}

}
void Player::drawFromDeck(std::stack<Card>& deck)
{
	if (deck.empty())
		return;
	hand.push_back(deck.top());
	deck.pop();
	std::sort(hand.begin(), hand.end(), compare);
}

void Player::fillHand(std::stack <Card>& deck)
{
	for (int i = 0; i < 5; ++i)
	{
		Card temp = deck.top();
		hand.push_back(temp);
		deck.pop();
	}
	std::sort(hand.begin(), hand.end(), compare);
}


void HumanPlayer::displayHand(sf::RenderTarget &window)
{
	//don't know the exact coordinates but it will be something like this
	int size = hand.size();
	float startPt = (610 - size * 15) / 2.0 + 850;
	for (int i = 0; i < size; i++)
	{
		Card temp = hand[i];
		temp.draw(window, startPt + (i * 15), 637.5, 0.f);
	}


}


void AIPlayer::displayHand(sf::RenderTarget& window)
{
	//don't know the exact coordinates but it will be something like this
	float startPt;
	switch (playerNum)
	{
	case(4):
		startPt = (620 - (int)hand.size() * 15) / 2.0 + 140;
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].draw(window, 1480, startPt + i * 15, 90);
		}
		break;
	case(3):
		startPt = (620 - (int)hand.size() * 15) / 2.0 +	950;
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].draw(window, startPt + (i * 15), 312.5, 180);
		}
		break;
	case(2):
		startPt = (620 - (int)hand.size() * 15) / 2.0 + 140;
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].draw(window, 1010, startPt + i *15, 90);
		}
		break;
	default:
		std::cout << "Something bad happen. (I don't know how this happen)\n";

	}


}

void Player::askForCard(Player& target, int card, std::stack<Card>& deck, std::stack<Card>&discard)
{
	Card tempHold[4];
	int tracker = 0;
	for(int i = 0; i < target.hand.size(); i++)
	{
		if (target.hand[i].getFaceValue() == card)
		{
			tempHold[tracker] = target.hand[i];
			target.hand.erase(target.hand.begin()+i);

			tracker++;
		}
	}
	for (int i = 0; i < tracker; i++)
	{
		hand.push_back(tempHold[i]);
	}
	if (tracker == 0)
	{
		drawFromDeck(deck);
		std::cout << "Drawn from deck." << std::endl;
		return;
	}
	//really hopeful this just works
	std::sort(hand.begin(), hand.end(), compare);
	
	std::cout << "User hand" << std::endl;
	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << hand[i].getFaceValue() << " ";

	}
	std::cout << "\nTarget hand" << std::endl;
	for (int i = 0; i < target.hand.size(); i++)
	{
		std::cout << target.hand[i].getFaceValue() << " ";

	}
	std::cout << "\n";
	int CM[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < hand.size(); i++)
	{
		CM[hand[i].getFaceValue() - 1]++;
	}
	for (int i = 1; i <= 13; i++)
	{
		if (CM[i - 1] == 4)
		{
			scoreCards(CM[i], discard);
		}
	}
	
}

int AIPlayer::selectCard()
{
	//This is a modified counting sort 
	//adds one at the index of face value of the card
	//then selects value with the highest number filtering out four out a kinds 
	int CM[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < hand.size(); i++)
	{
		CM[hand[i].getFaceValue()-1]++;
	}
	//getting index of max
	int Index, max = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (CM[i - 1] == 4)
		{
			//do nothing will be score else
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

//void Mergesort(std::vector<Card>& hand) {
//	if (hand.size() <= 1) 
//		return;
//
//	int mid = hand.size() / 2;
//	std::vector<Card> left;
//	int count = 0;
//	for (int i = 0; i <= mid; i++)
//	{
//		left[count] = hand[count];
//		count++;
//	}
//
//	std::vector<Card> right;
//	for (int i = count; i < hand.size(); i++)
//	{
//		right[count] = hand[count];
//		count++;
//	}
//	Mergesort(left);
//	Mergesort(right);
//	merge(left, right, hand);
//}
//
//void merge(std::vector<Card>& left, std::vector<Card>& right, std::vector<Card>& results)
//{
//	int L_size = left.size();
//	int R_size = right.size();
//	int i = 0, j = 0, k = 0;
//	// two finger algorithm
//	while (j < L_size && k < R_size)
//	{
//		if (left[j].compare(right[k])) {
//			results[i] = left[j];
//			j++;
//		}
//		else {
//			results[i] = right[k];
//			k++;
//		}
//		i++;
//	}
//	while (j < L_size) {
//		results[i] = left[j];
//		j++; i++;
//	}
//	while (k < R_size) {
//		results[i] = right[k];
//		k++; i++;
//	}
//}