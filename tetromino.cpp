#include "tetromino.h"

Tetromino::Tetromino(int type) : type(type + 1), origin({ 0, 0 }), direction(0) {
	if (type == 0) {
		// I block
		cellSet[0] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
		cellSet[1] = { {2, 0}, {2, 1}, {2, 2}, {2, 3} };
		cellSet[2] = { {0, 2}, {1, 2}, {2, 2}, {3, 2} };
		cellSet[3] = { {1, 0}, {1, 1}, {1, 2}, {1, 3} };
	} else if (type == 1) {
		// O block
		cellSet[0] = cellSet[1] = cellSet[2] = cellSet[3] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	} else if (type == 2) {
		// T block
		cellSet[0] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {1, 1}, {1, 2}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
		cellSet[3] = { {0, 1}, {1, 0}, {1, 1}, {2, 1} };
	} else if (type == 3) {
		// L block
		cellSet[0] = { {0, 2}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {1, 1}, {2, 1}, {2, 2} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 0} };
		cellSet[3] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
	} else if (type == 4) {
		// J block
		cellSet[0] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {0, 2}, {1, 1}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 2} };
		cellSet[3] = { {0, 1}, {1, 1}, {2, 0}, {2, 1} };
	} else if (type == 5) {
		// S block
		cellSet[0] = { {0, 1}, {0, 2}, {1, 0}, {1, 1} };
		cellSet[1] = { {0, 1}, {1, 1}, {1, 2}, {2, 2} };
		cellSet[2] = { {1, 1}, {1, 2}, {2, 0}, {2, 1} };
		cellSet[3] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
	}
	else if (type == 6) {
		// Z block
		cellSet[0] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 2}, {1, 1}, {1, 2}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {2, 1}, {2, 2} };
		cellSet[3] = { {0, 1}, {1, 0}, {1, 1}, {2, 0} };
	} else {
		throw invalid_argument("Invalid type");
	}
}

void Tetromino::render() {
	for (auto cell : cellSet[direction]) {
		DrawRectangle((cell.first + origin.first) * CELL_SIZE + 1, (cell.second + origin.second) * CELL_SIZE + 1, CELL_SIZE - 1, CELL_SIZE - 1, COLORS.at(type - 1));
	}
}

void Tetromino::move(int x, int y) {
	origin.first += x;
	origin.second += y;
}
void Tetromino::rotateCW() {
	direction = (direction + 1) % 4;
}
void Tetromino::rotateCCW() {
	direction = (direction - 1) % 4;
}