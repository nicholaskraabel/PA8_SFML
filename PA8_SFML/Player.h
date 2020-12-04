#pragma once
#include "Card.h"
#include <list>
#include <stack>
#include <vector>

class Player {
protected:
	int score;
	int playerNum;
public:
	std::vector <Card> hand;
	Player(int pn)
	{
		score = 0;
		playerNum = pn;
	}
	~Player(){}

	void setScore(int sc)
	{score = sc;}

	int getScore()
	{return score;}

	//run once at the begining of game 
	void fillHand(std::stack <Card>&);
	void displayHand(sf::RenderTarget&){}
	void askForCard(Player&, int, std::stack<Card>&, std::stack<Card>& discard);
	void drawFromDeck(std::stack<Card>&);
	void scoreCards(int, std::stack<Card>&);
	void displayscore(sf::RenderTarget& window);
};

class HumanPlayer : public Player
{
public:
	HumanPlayer(int pn) : Player(pn){}

	void displayHand(sf::RenderTarget&);
};

class AIPlayer : public Player
{
public:
	AIPlayer(int pn) : Player(pn) {}

	void displayHand(sf::RenderTarget&);

	int selectCard();
};

void Mergesort(std::vector<Card>&);

void merge(std::vector<Card>&, std::vector<Card>&, std::vector<Card>&);