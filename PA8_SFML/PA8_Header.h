#pragma once

#include <SFML/Graphics.hpp>
#include "Card.h"
#include "DeckConstruction.h"
#include <Windows.h>



void draw_window(sf::RenderTarget& window);
void draw_menu(sf::RenderTarget& window);
void draw_message_board(sf::RenderTarget& window);
//int get_go_fish(sf::Window& window);
void draw_go_fishing_message(sf::RenderTarget& window, std::string, int);
void draw_user_input(sf::RenderTarget& window, char s_user);
void draw_user_input_box(sf::RenderTarget& window);
void draw_player_input_boxes(sf::RenderTarget& window);
void drawEndWindow(sf::RenderTarget& window, int sc1, int sc2, int sc3, int sc4);


