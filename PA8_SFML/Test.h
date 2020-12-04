#pragma once
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "DeckConstruction.h"
#include "PA8_Header.h"
#include "Player.h"

class Test
{
private:
	Card* deckTest;
public:
	Test();
	void gameDeckTest();
	void fillhandTest(); 
	void askTest();
	void drawTest();
	void shuffleTest();
};