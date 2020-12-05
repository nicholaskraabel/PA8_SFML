#pragma once

#include <SFML/Graphics.hpp>
#include "Card.h"
#include "DeckConstruction.h"
#include <Windows.h>


/** 
Function:draw_window
Purpose: display window with board 
		 and players and score boxs
Parameters: RenderTarget& window
in/out: window
return void
**/
void draw_window(sf::RenderTarget& window);

/**
Function:draw_menu
Purpose: display menu board with the go fish on it and the red square.
Parameters: RenderTarget& window
in/out: window
return void
**/
void draw_menu(sf::RenderTarget& window);

/**
Function:draw_message_board
Purpose: display message board
Parameters: RenderTarget& window
in/out: window
out: message board
return void
**/
void draw_message_board(sf::RenderTarget& window);


//int get_go_fish(sf::Window& window);

/**
Function:draw_go_fishing_message
Purpose: Displays teh string in the message box
Parameters: RenderTarget& window std::string, int
in: string, int 
in/out: window, string
return void
**/
void draw_go_fishing_message(sf::RenderTarget& window, std::string, int);

/**
Function:draw_user_input
Purpose: displays the card the player enters
Parameters: RenderTarget& window, char s_user
in/out: window, s_user
return void
**/
void draw_user_input(sf::RenderTarget& window, char s_user);

/**
Function:draw_user_input_box
Purpose: display boxee to input for a card
Parameters: RenderTarget& window
in/out: window
return void
**/
void draw_user_input_box(sf::RenderTarget& window);

/**
Function:draw_player_input_boxes
Purpose: display input boxes to get players
Parameters: RenderTarget& window
in/out: window
return void
**/
void draw_player_input_boxes(sf::RenderTarget& window);


//void drawEndWindow(sf::RenderTarget& window, int sc1, int sc2, int sc3, int sc4);