#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <raylib.h>

using namespace std;

namespace constants {
	const int CELL_SIZE = 40;

	const vector <Color> COLORS = {
		{ 220, 53, 69, 255 }, // red
		{ 253, 126, 20, 255 }, // orange
		{ 255, 193, 7, 255 }, // yellow
		{ 25, 135, 84, 255 }, // green
		{ 13, 110, 253, 255 }, // blue
		{ 111, 66, 193, 255 }, // purple
		{ 214, 51, 132, 255 } // pink
	};
}

#endif
