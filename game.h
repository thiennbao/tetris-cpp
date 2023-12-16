#ifndef GAME_H
#define GAME_H

#include <string>
#include "board.h"
#include "tetromino.h"
#include "menu.h"

using namespace std;

class Game {
private:
	Board board;
	Tetromino current, next;
	int difficulty;
	int score;
	double tick, lastTick;
	void action();
	bool fall();

	Music gameMusic;
	Sound gameSound;
public:
	Game(int level = 0);
	void run();
};

#endif
