#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <vector>
#include <raylib.h>
#include "constants.h"

using namespace std;
using namespace constants;

class Tetromino {
private:
	int type;
	pair <int, int> origin;
	int direction;
	vector <pair <int, int>> cellSet[4];
public:
	Tetromino(int type = 0);
	int getType();
	vector <pair <int, int>> getCurrentCells();
	void render();
	void move(int x, int y);
	void rotateCW();
	void rotateCCW();
};

#endif
