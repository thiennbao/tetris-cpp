#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <raylib.h>
#include "constants.h"

using namespace std;
using namespace constants;

class Board {
private:
	vector <vector <int>> content;
public:
	Board(int witdth = 0, int height = 0);
	void render();
};

#endif
