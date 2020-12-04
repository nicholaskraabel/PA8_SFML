#pragma once
#include "Card.h"
#include <stack>

//This is just called once and creates all the cards for the game. 
void deckConstuctor(Card(&deck)[deckSize]);

//This is the actual stack used for the game which is given.
void gameDeck(std::stack<Card>&);

void shuffle(Card(&deck)[deckSize]);