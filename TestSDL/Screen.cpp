#include "Screen.h"

void runScreen() {

	// Set player turn to 1 first
	int player = 1;

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

	// Loop until application is closed
	while (running) {
		
		while (SDL_PollEvent(&event)) {
			drawBoard(renderer);
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				gameLoop(renderer, player, gameBoard);
			}

			SDL_RenderPresent(renderer);

			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); // Safely shuts down SDL application
}