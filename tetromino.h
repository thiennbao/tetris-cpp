#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <vector>
#include <raylib.h>
#include "constants.h"

using namespace std;

class Tetromino {
private:
	int type;
	pair <int, int> origin;
	int direction;
	vector <pair <int, int>> cellSet[4];
public:
	Tetromino(int type = 1);
	void setOrigin(int x, int y);
	int getType();
	vector <pair <int, int>> getCurrentCells();
	void render(int offsetX = 0, int offsetY = 0);
	void move(int x, int y);
	void rotateCW();
	void rotateCCW();
};

#endif
