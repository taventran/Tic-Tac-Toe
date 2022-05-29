#pragma once
#include "Check.h"

class Bot {
	public:
		Bot();
		int getTurnNum() { return turnNum; }
		coord botMove(char(&board)[3][3]);
	private:
		int turnNum;
};

