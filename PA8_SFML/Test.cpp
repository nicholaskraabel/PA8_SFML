
#include"Test.h"
#include<string.h>
#include<iostream>

using namespace std;

Test::Test()
{

}
void Test::gameDeckTest()
{
	stack<Card> deckTest;
	gameDeck(deckTest);

	if (!deckTest.empty())
	{
		if (deckTest.size() == 52)
		{
			cout << "Deck Test Passed" << endl;
		}
		else
		{
			cout << "Deck Test Failed" << endl;
		}
	}
}
void Test::fillhandTest()
{
	vector<Card> handTest;
	stack<Card> deckTest;
	HumanPlayer P = HumanPlayer(1);
	gameDeck(deckTest);
	P.fillHand(deckTest);
	if (P.hand.size() == 5)
	{
		cout << "Fill Hand Test Pass" << endl;
	}
	else
	{
		cout << "Fill Hand Test Failed " << P.hand.size() << " cards" << endl;
	}
}
void Test::askTest()
{
		vector<Card> handTest;
		stack<Card> deckTest, discardTest;
		gameDeck(deckTest);
		HumanPlayer PT = HumanPlayer(1);
		PT.fillHand(deckTest);
		AIPlayer AT = AIPlayer(1);
		AT.fillHand(deckTest);
		
		int asked = 1;
		asked = AT.hand[0].getFaceValue();
		
		PT.askForCard(AT, asked, deckTest, discardTest);
		if (PT.hand.size() == 6)
		{
			cout << "Ask Test Passed" << endl;
		}
		else
		{
			cout << "Ask Test Failed" << endl;
		}
	}
void Test::drawTest()
{
	vector<Card> handTest;
	stack<Card> deckTest;
	gameDeck(deckTest);
	HumanPlayer PT = HumanPlayer(1);
	PT.fillHand(deckTest);
	PT.drawFromDeck(deckTest);
	if (PT.hand.size() == 6)
	{
		cout << "Draw Test Passed" << endl;
	}
	else
	{
		cout << "Draw Test Failed" << endl;
	}

}
void Test::shuffleTest()
{
	Card deck[deckSize];
	deckConstuctor(deck);

	int faceValue1, faceValue5, faceValue10, faceValue15, faceValue20, faceValue25 = 0;

	faceValue1 = deck[0].getFaceValue();
	faceValue5 = deck[4].getFaceValue();
	faceValue10 = deck[9].getFaceValue();
	faceValue15 = deck[14].getFaceValue();
	faceValue20 = deck[19].getFaceValue();
	faceValue25 = deck[24].getFaceValue();

	shuffle(deck);

	int shuffle1, shuffle5, shuffle10, shuffle15, shuffle20, shuffle25 = 0;
	shuffle1 = deck[0].getFaceValue();
	shuffle5 = deck[4].getFaceValue();
	shuffle10= deck[9].getFaceValue();
	shuffle15 = deck[14].getFaceValue();
	shuffle20 = deck[19].getFaceValue();
	shuffle25 = deck[24].getFaceValue();

	int difference = 0;
	
	if (faceValue1 != shuffle1)
	{
		difference++;
	}
	if (faceValue5 != shuffle5)
	{
		difference++;
	}
	if (faceValue10 != shuffle10)
	{
		difference++;
	}
	if (faceValue15 != shuffle15)
	{
		difference++;
	}
	if (faceValue20 != shuffle20)
	{
		difference++;
	}
	if (faceValue25 != shuffle25)
	{
		difference++;
	}
	if (difference > 0)
	{
		cout << "Shuffle Test Passed" << endl;
	}
	else
	{
		cout << "Shuffle Test Failed" << endl;
	}

}

