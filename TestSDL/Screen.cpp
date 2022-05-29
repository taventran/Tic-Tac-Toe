#include "Screen.h"

void runScreen() {

	// Set player turn to 1 first
	int player = 1;
	Bot bot;
	// Make array of gameboard
	char gameBoard[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gameBoard[i][j] = 'A';
		}
	}


	// Setting up SDL
	SDL_Init(SDL_INIT_EVERYTHING); 

	SDL_Window* window;
	SDL_Renderer* renderer;
	window = SDL_CreateWindow("Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		400, // width
		400, // height
		SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(window,
		-1,
		SDL_RENDERER_ACCELERATED);

	if (window == NULL) {
		std::cout << "FAILED" << SDL_GetError();
	}

	SDL_Event event;
	bool running = true;

	std::cout << "Option 1: Play against cpu" << std::endl << "Option 2: Play against a person" << std::endl;
	int choice;

	std::cin >> choice;
	
	// Loop until application is closed
	if (choice == 2) {
		// 2 players
		while (running) {

			while (SDL_PollEvent(&event)) {
				drawBoard(renderer);
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					twoPlayerGameLoop(renderer, player, gameBoard);
				}

				SDL_RenderPresent(renderer);

				if (event.type == SDL_QUIT) {
					running = false;
					break;
				}
			}

		}
	}
	else {
		while (running) {
			// Bot
			while (SDL_PollEvent(&event)) {
				drawBoard(renderer);
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					botGameLoop(renderer, player, gameBoard, bot);
				}
				SDL_RenderPresent(renderer);
				if (event.type == SDL_QUIT) {
					running = false;
					break;
				}
			}

		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); // Safely shuts down SDL application
}