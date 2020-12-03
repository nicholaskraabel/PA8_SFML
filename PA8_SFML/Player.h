#pragma once
#include "Card.h"
#include <list>
#include <stack>
class Player {
protected:
	int score;
	int playerNum;
public:
	std::list <Card> hand;
	Player(int pn)
	{
		score = 0;
		playerNum = pn;
	}
	~Player(){}

	void setScore(int sc)
	{
		score = sc;
	}
	int getScore()
	{
		return score;
	}
	//run once at the begining of game 
	virtual void fillHand(std::stack <Card>&);

	virtual void displayHand(sf::RenderTarget&);

	virtual void askForCard(Player&, int);

	virtual void sortHand();





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