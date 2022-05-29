#include "Draw.h"


void drawBoard(SDL_Renderer* rend) {
	SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(rend, 130, 0, 130, 400);
	SDL_RenderDrawLine(rend, 270, 0, 270, 400);
	SDL_RenderDrawLine(rend, 0, 130, 400, 130);
	SDL_RenderDrawLine(rend, 0, 270, 400, 270);
}

void drawX(SDL_Renderer* rend, position pos) {
	SDL_SetRenderDrawColor(rend, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(rend, pos.x-65, pos.y - 65, pos.x+65, pos.y+65);
	SDL_RenderDrawLine(rend, pos.x + 65, pos.y - 65, pos.x - 65, pos.y + 65);
	SDL_RenderPresent(rend);
}

void drawCircle(SDL_Renderer* rend, position pos) {
	SDL_SetRenderDrawColor(rend, 0, 0, 255, SDL_ALPHA_OPAQUE);
	const int radius = 65;
	const int diameter = (radius * 2);
	int x = (radius-1);
	int y = 0;
	int dx = 1;
	int dy = 1;
	int error = (dx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(rend, pos.x + x, pos.y - y);
		SDL_RenderDrawPoint(rend, pos.x + x, pos.y + y);
		SDL_RenderDrawPoint(rend, pos.x - x, pos.y - y);
		SDL_RenderDrawPoint(rend, pos.x - x, pos.y + y);
		SDL_RenderDrawPoint(rend, pos.x + y, pos.y - x);
		SDL_RenderDrawPoint(rend, pos.x + y, pos.y + x);
		SDL_RenderDrawPoint(rend, pos.x - y, pos.y - x);
		SDL_RenderDrawPoint(rend, pos.x - y, pos.y + x);

		if (error <= 0)
		{
			++y;
			error += dy;
			dy += 2;
		}

		if (error > 0)
		{
			--x;
			dx += 2;
			error += (dx - diameter);
		}
	}
	SDL_RenderPresent(rend);
}

void addX(position pos, SDL_Renderer* rend) {
	// First row
	if (pos.x < 130 && pos.y > 0 && pos.y < 130) {
		pos.x = 65;
		pos.y = 65;
		drawX(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 0 && pos.y < 130) {
		pos.x = 200;
		pos.y = 65;
		drawX(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 0 && pos.y < 130) {
		pos.x = 335;
		pos.y = 65;
		drawX(rend, pos);
	}
	// Second row
	else if (pos.x < 130 && pos.y > 130 && pos.y < 270) {
		pos.x = 65;
		pos.y = 200;
		drawX(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 130 && pos.y < 270) {
		pos.x = 200;
		pos.y = 200;
		drawX(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 130 && pos.y < 270) {
		pos.x = 335;
		pos.y = 200;
		drawX(rend, pos);
	}
	// Third row
	else if (pos.x < 130 && pos.y > 270) {
		pos.x = 65;
		pos.y = 335;
		drawX(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 270) {
		pos.x = 200;
		pos.y = 335;
		drawX(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 270) {
		pos.x = 335;
		pos.y = 335;
		drawX(rend, pos);
	}
	return;
}

void addCircle(position pos, SDL_Renderer* rend) {
	// First row
	if (pos.x < 130 && pos.y > 0 && pos.y < 130) {
		pos.x = 65;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 0 && pos.y < 130) {
		pos.x = 200;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 0 && pos.y < 130) {
		pos.x = 335;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	// Second row
	else if (pos.x < 130 && pos.y > 130 && pos.y < 270) {
		pos.x = 65;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 130 && pos.y < 270) {
		pos.x = 200;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 130 && pos.y < 270) {
		pos.x = 335;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	// Third row
	else if (pos.x < 130 && pos.y > 270) {
		pos.x = 65;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	else if (pos.x > 130 && pos.x < 270 && pos.y > 270) {
		pos.x = 200;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	else if (pos.x > 270 && pos.y > 270) {
		pos.x = 335;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	return;
}
void botCircle(int x, int y, SDL_Renderer* rend) {
	position pos;
	// First row
	if (x == 0  && y == 0) {
		pos.x = 65;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	else if (x == 1 && y == 0) {
		pos.x = 200;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	else if (x == 2 && y == 0) {
		pos.x = 335;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	// Second row
	else if (x == 0 && y == 1) {
		pos.x = 65;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	else if (x == 1 && y == 1) {
		pos.x = 200;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	else if (x == 2 && y == 1) {
		pos.x = 335;
		pos.y = 200;
		drawCircle(rend, pos);
	}
	// Third row
	else if (x == 0 && y == 2) {
		pos.x = 65;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	else if (x == 1 && y == 2) {
		pos.x = 200;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	else if (x == 2 && y == 2) {
		pos.x = 335;
		pos.y = 335;
		drawCircle(rend, pos);
	}
	return;
}

void botX(int x, int y, SDL_Renderer* rend) {
	position pos;
	// First row
	if (x == 0 && y == 0) {
		pos.x = 65;
		pos.y = 65;
		drawCircle(rend, pos);
	}
	else if (x == 1 && y == 0) {
		pos.x = 200;
		pos.y = 65;
		drawX(rend, pos);
	}
	else if (x == 2 && y == 0) {
		pos.x = 335;
		pos.y = 65;
		drawX(rend, pos);
	}
	// Second row
	else if (x == 0 && y == 1) {
		pos.x = 65;
		pos.y = 200;
		drawX(rend, pos);
	}
	else if (x == 1 && y == 1) {
		pos.x = 200;
		pos.y = 200;
		drawX(rend, pos);
	}
	else if (x == 2 && y == 1) {
		pos.x = 335;
		pos.y = 200;
		drawX(rend, pos);
	}
	// Third row
	else if (x == 0 && y == 2) {
		pos.x = 65;
		pos.y = 335;
		drawX(rend, pos);
	}
	else if (x == 1 && y == 2) {
		pos.x = 200;
		pos.y = 335;
		drawX(rend, pos);
	}
	else if (x == 2 && y == 2) {
		pos.x = 335;
		pos.y = 335;
		drawX(rend, pos);
	}
	return;
}
