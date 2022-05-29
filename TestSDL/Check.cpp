#include "Check.h"


struct coord checkPos(position pos) {
	coord spot;
	// First row
	if (pos.x < 130 && pos.y > 0 && pos.y < 130) {
		spot.row = 0;
		spot.col = 0;
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 0 && pos.y < 130) {
		spot.row = 0;
		spot.col = 1;
	}
	else if (pos.x > 270 && pos.y > 0 && pos.y < 130) {
		spot.row = 0;
		spot.col = 2;
	}
	// Second row
	else if (pos.x < 130 && pos.y > 130 && pos.y < 270) {
		spot.row = 1;
		spot.col = 0;
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 130 && pos.y < 270) {
		spot.row = 1;
		spot.col = 1;
	}
	else if (pos.x > 270 && pos.y > 130 && pos.y < 270) {
		spot.row = 1;
		spot.col = 2;
	}
	// Third row
	else if (pos.x < 130 && pos.y > 270) {
		spot.row = 2;
		spot.col = 0;
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 270) {
		spot.row = 2;
		spot.col = 1;
	}
	else if (pos.x > 270 && pos.y > 270) {
		spot.row = 2;
		spot.col = 2;
	}
	return spot;
}

bool changeArray(char(&board)[3][3], int player, coord &spot) {
	if (board[spot.row][spot.col] == 'A') {
		if (player == 1) {
			board[spot.row][spot.col] = 'X';
		}
		else {
			board[spot.row][spot.col] = 'O';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Spot filled already!" << std::endl;
		return false;
	}
	return true;
}

bool gameOver(char(&board)[3][3]) {
	// Checks horizontally
	char checkThreeInARow[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			checkThreeInARow[j] = board[i][j];
		}
		if ((checkThreeInARow[0] == checkThreeInARow[1]) && (checkThreeInARow[0] == checkThreeInARow[2])) {
			if (checkThreeInARow[0] != 'A') {
				return true;
			}
		}
	} 
	// Checks Vertically
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			checkThreeInARow[j] = board[j][i];
		}
		if ((checkThreeInARow[0] == checkThreeInARow[1]) && (checkThreeInARow[0] == checkThreeInARow[2])) {
			if (checkThreeInARow[0] != 'A') {
				return true;
			}
		}
	}
	// Checks Diagonally 
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		if (board[0][0] != 'A') {
			return true;
		}
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
		if (board[2][0] != 'A') {
			return true;
		}
	}

	return false;
}