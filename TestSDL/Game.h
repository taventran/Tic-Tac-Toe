#pragma once
#include "Draw.h"
#include "Check.h"
#include "Bot.h"


void twoPlayerGameLoop(SDL_Renderer* rend, int& player, char(&board)[3][3]);

void botGameLoop(SDL_Renderer* rend, int& player, char(&board)[3][3], Bot& bot);

void checkTurn(int& player);

void resetBoard(char(&board)[3][3]);
