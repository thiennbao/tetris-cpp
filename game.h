#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tetromino.h"

using namespace std;

class Game {
private:
	Board board;
	Tetromino current, next;
	int score;
	double tick, lastTick;
	void action();
	bool fall();
public:
	Game();
	void run();
};

#endif
