#pragma once
#include "SDL.h"
#include "SDL_mouse.h"
#include <iostream>

struct position {
	int x;
	int y;
};


void drawBoard(SDL_Renderer* rend);

void addX(position pos, SDL_Renderer* rend);

void addCircle(position pos, SDL_Renderer* rend);

void drawX(SDL_Renderer* rend, position pos);

void drawCircle(SDL_Renderer* rend, position pos);

void botCircle(int x, int y, SDL_Renderer* rend);

void botX(int x, int y, SDL_Renderer* rend);
