#pragma once
#include "Draw.h"
#include "Check.h"



void gameLoop(SDL_Renderer* rend, int& player, char(&board)[3][3]);

void checkTurn(int& player);

void resetBoard(char(&board)[3][3]);