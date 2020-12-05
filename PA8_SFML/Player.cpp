#include "Player.h"
#include "Card.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <stack>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstring>

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
			hand.erase(hand.begin() + i, hand.begin()+i+4);			
			score++;
			return;
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


void AIPlayer::displayHand(sf::RenderTarget& window, bool fliped)
{
	//don't know the exact coordinates but it will be something like this
	float startPt;
	switch (playerNum)
	{
	case(4):
		startPt = (620 - (int)hand.size() * 15) / 2.0 + 140;
		for (int i = 0; i < hand.size(); i++)
		{
			if(fliped)
				hand[i].draw(window, 1480, startPt + i * 15, 90);
			else
				hand[i].drawBack(window, 1480, startPt + i * 15, 90);
		}
		break;
	case(3):
		startPt = (620 - (int)hand.size() * 15) / 2.0 +	950;
		for (int i = 0; i < hand.size(); i++)
		{
			if(fliped)
				hand[i].draw(window, startPt + (i * 15), 312.5, 180);
			else
				hand[i].drawBack(window, startPt + (i * 15), 312.5, 180);
		}
		break;
	case(2):
		startPt = (620 - (int)hand.size() * 15) / 2.0 + 140;
		for (int i = 0; i < hand.size(); i++)
		{
			if(fliped)
				hand[i].draw(window, 1010, startPt + i *15, 90);
			else
				hand[i].drawBack(window, 1010, startPt + i * 15, 90);

		}
		break;
	default:
		std::cout << "Something bad happen. (I don't know how this happen)\n";

	}


}

void Player::askForCard(Player& target, int card, std::stack<Card>& deck, std::stack<Card> &discard)
{
	Card tempHold[4];
	int tracker = 0, firstIndex = -1;

	for(int i = 0; i < target.hand.size(); i++)
	{
		if (target.hand[i].getFaceValue() == card)
		{
			tempHold[tracker] = target.hand[i];
			if (firstIndex == -1)
				firstIndex = i;
			tracker++; 
		}
	}
	//erases the cards from hand
	if (firstIndex != -1)
	{
		target.hand.erase(target.hand.begin() + firstIndex, target.hand.begin() + firstIndex + tracker);
		target.hand.shrink_to_fit();
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
	std::cout << "\n\n";
	int CM[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < hand.size(); i++)
	{
		CM[hand[i].getFaceValue() - 1]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (CM[i] == 4)
			scoreCards(i + 1, discard);
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

/*
Daniel Clawson
12/4/2020
*/
void Player::displayscore(sf::RenderTarget& window)
{
	sf::Font font2;
	if (!font2.loadFromFile("Star Trebek.otf")) // select the font
		throw("Could not load font");

	//int score = 0;
	std::string score_c;

	//score = getScore();

	score_c = std::to_string(score);

	// TITLE
	sf::Text Score;
	Score.setFont(font2);
	Score.setString(score_c);// set the string to display
	Score.setCharacterSize(40); // set the character size in pixels, not points! 
	Score.setFillColor(sf::Color::Yellow); // set the color
	Score.setStyle(sf::Text::Bold); // set the text style
	//Score.setPosition(100, 100);
	if (playerNum == 1)
		Score.setPosition(1250, 870);
	if (playerNum == 2)
		Score.setPosition(735, 470);
	if (playerNum == 3)
		Score.setPosition(1250, 50);
	if (playerNum == 4)
		Score.setPosition(1605, 470);

	window.draw(Score);
}