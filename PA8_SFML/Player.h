#pragma once
#include "Card.h"
#include <list>
#include <stack>
#include <vector>

class Player {
protected:
	int score;
	int playerNum; // player identifier used for locations seting of graphics
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

	 /** fillHand
		 |
		 |  Purpose: Pop 5 cards off the stack and a inserts them into the hand in sorted order
		 |
		 |
		 |  Parameters: in/out stack<Card> & reference
		 | 			    class member hand the vector which is filled
		 |              
		 |
		 |  return void
		 **/
	void fillHand(std::stack <Card>&);

	/*PloyMorphic*/
	//display hand using render target
	void displayHand(sf::RenderTarget&){}

	/** askForCard
		|
		|  Purpose: takes either player or Ai selection of card and the opponent which they selected 
		|			will automaticly play a four of a kind if one occurs in players hand.
		|
		|
		|  Parameters: in/out stack<card> This is the deck is modify if player chosen does not have the card
		|			   in/out Player& target this is the opponent selected
		|			   in int card selected by facevalue that the player wants 
		|              class member targets hand and players hands are modified if a change of cards happens
		|			   in/out stack<Card> &discard is the discard pile modifiy if player scores a point
		|
		|
		|  return void
		**/
	void askForCard(Player&, int, std::stack<Card>&, std::stack<Card>& discard);

	//Draws card from given stack if stack is empty returns
	void drawFromDeck(std::stack<Card>&);
	
	/** scoreCards
		|
		|  Purpose: Scores a point for player from the set of 4 passed in and removes the four cards from hand and
		|			pushes them onto discard
		|
		|
		|  Parameters: in/out stack<card> discard one card is push onto to this to display the most recent discard
		|			   in int card facevalue of the set of 4 
		|              class member hand modified by the removal of the set of four. 
		|
		|
		|  return void
		**/
	void scoreCards(int, std::stack<Card>&);

	//displays player score
	void displayscore(sf::RenderTarget& window);
};

class HumanPlayer : public Player
{
public:
	HumanPlayer(int pn) : Player(pn){}

	//The Human and Ai verison differ based on location and that human is auto set to display
	void displayHand(sf::RenderTarget&);
};

class AIPlayer : public Player
{
public:
	AIPlayer(int pn) : Player(pn) {}

	//display hands base on player id and whether or not there fliped is based 
	void displayHand(sf::RenderTarget&, bool);

	int selectCard();
};

void Mergesort(std::vector<Card>&);

void merge(std::vector<Card>&, std::vector<Card>&, std::vector<Card>&);