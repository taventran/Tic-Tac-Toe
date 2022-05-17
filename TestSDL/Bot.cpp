#include "Bot.h"
#include <cstdlib>
#include <ctime>

Bot::Bot() {
	srand(time(0));
	this->turnNum = rand() % 2 + 1;
}


coord Bot::botMove(char(&board)[3][3]) {
	bool validMove;
	coord spot;
	do {
		spot.row = rand() % 3;
		spot.col = rand() % 3;
		validMove = changeArray(board, this->turnNum, spot);
	} while (!validMove);
	return spot;
}
