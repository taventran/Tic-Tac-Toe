#pragma once
#include "Draw.h"

struct coord {
	int row;
	int col;
};

struct coord checkPos(position pos); // Check position of mouse and then return what to change in array

bool changeArray(char(&board)[3][3], int player, coord &spot); // Returns true if spot hasn't been taken

bool gameOver(char(&board)[3][3]); // Returns true if one player won