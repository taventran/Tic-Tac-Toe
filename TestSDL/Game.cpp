#include "Game.h"
#include <Windows.h>

void twoPlayerGameLoop(SDL_Renderer* rend, int& player, char(&board)[3][3]) {

	int x, y;
	Uint32 buttons;
	SDL_PumpEvents(); // Clear old mouse state
	buttons = SDL_GetMouseState(&x, &y);
	position currentPos;
	currentPos.x = 0;
	currentPos.y = 0;
	if ((buttons & SDL_BUTTON_LMASK) != 0) {

		std::cout << player << std::endl;
		SDL_Log("Mouse Button 1 (left) is pressed.");
		currentPos.x = x;
		currentPos.y = y;    
		coord spot = checkPos(currentPos);
		bool valid = changeArray(board, player, spot);
		if (valid) {
			switch (player) {
			case 1:
				addX(currentPos, rend);
				break;
			case 2:
				addCircle(currentPos, rend);
				break;
			default:
				std::cout << "Broken" << std::endl;
			}
			checkTurn(player);
		}
		bool checkWin = gameOver(board);
		if (checkWin) {
			checkTurn(player);                                     
			std::cout << "Player: " << player << " won" << std::endl;
			resetBoard(board);
		}
		std::cout << currentPos.x << " " << currentPos.y << std::endl;
	}
	
}

void botGameLoop(SDL_Renderer* rend, int& player, char(&board)[3][3], Bot& bot, SDL_Event& event) {
	coord spot;
	std::string buffer;
	bool checkWin = false;
	if (bot.getTurnNum() == 1) {
		int x, y;
		Uint32 buttons;
		SDL_PumpEvents(); // Clear old mouse state
		buttons = SDL_GetMouseState(&x, &y);
		position currentPos;
		currentPos.x = 0;
		currentPos.y = 0;

		if (player == 1) {
			spot = bot.botMove(board);
			botX(spot.col, spot.row, rend);
			checkWin = gameOver(board);
			checkTurn(player);
		}

		if (checkWin) {
			checkTurn(player);
			std::cout << "Player: " << player << " won" << std::endl;
			std::cout << "Click Enter to continue " << std::endl;
			std::cin >> buffer;
			resetBoard(board);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN  && player==2) {
			if (player == 2 && (buttons & SDL_BUTTON_LMASK) != 0) {
				std::cout << player << std::endl;
				SDL_Log("Mouse Button 1 (left) is pressed.");
				currentPos.x = x;
				currentPos.y = y;
				spot = checkPos(currentPos);
				bool valid = changeArray(board, player, spot);
				if (valid) {
					addCircle(currentPos, rend);
					checkTurn(player);
				}
				checkWin = gameOver(board);
				if (checkWin) {
					checkTurn(player);
					std::cout << "Player: " << player << " won" << std::endl;
					std::cout << "Click Enter to continue " << std::endl;
					std::cin >> buffer;
					resetBoard(board);
				}
				std::cout << player << std::endl;
				SDL_Log("Mouse Button 1 (left) is pressed.");
				currentPos.x = x;
				currentPos.y = y;
				spot = checkPos(currentPos);
				checkWin = gameOver(board);
				if (checkWin) {
					checkTurn(player);
					std::cout << "Player: " << player << " won" << std::endl;
					std::cout << "Click Enter to continue " << std::endl;
					std::cin >> buffer;
					resetBoard(board);
				}
			}
		}
	}
	else {
		int x, y;
		Uint32 buttons;
		SDL_PumpEvents(); // Clear old mouse state
		buttons = SDL_GetMouseState(&x, &y);
		position currentPos;
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (player == 1 && (buttons & SDL_BUTTON_LMASK) != 0) {
				std::cout << player << std::endl;
				SDL_Log("Mouse Button 1 (left) is pressed.");
				currentPos.x = x;
				currentPos.y = y;
				spot = checkPos(currentPos);
				bool valid = changeArray(board, player, spot);
				if (valid) {
					addX(currentPos, rend);
					checkTurn(player);
				}
				checkWin = gameOver(board);
				if (checkWin) {
					checkTurn(player);
					std::cout << "Player: " << player << " won" << std::endl;
					std::cout << "Click Enter to continue " << std::endl;
					std::cin >> buffer;
					resetBoard(board);
				}
				spot = bot.botMove(board);
				botCircle(spot.col, spot.row, rend);
				checkWin = gameOver(board);
				checkTurn(player);
				if (checkWin) {
					checkTurn(player);
					std::cout << "Player: " << player << " won" << std::endl;
					std::cout << "Click Enter to continue " << std::endl;
					std::cin >> buffer;
					resetBoard(board);
				}
			}
		}
	}
}

void checkTurn(int& player) {
	if (player == 1) {
		player = 2;
	}
	else {
		player = 1;
	}

	return;
}

void resetBoard(char(&board)[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 'A';
		}
	}
}