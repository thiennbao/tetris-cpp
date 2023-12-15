#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <raylib.h>
#include "constants.h"
#include "tetromino.h"

using namespace std;

class Board {
private:
	vector <vector <int>> content;
public:
	Board();
	void render();
	bool fill(Tetromino &tetromino);
	bool checkCollision(Tetromino& tetromino);
	int clearRows();
};

#endif
