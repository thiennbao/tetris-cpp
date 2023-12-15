#include "tetromino.h"

Tetromino::Tetromino(int type) : type(type), origin({ 0, 0 }), direction(0) {
	if (type == 1) {
		// I block
		cellSet[0] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
		cellSet[1] = { {2, 0}, {2, 1}, {2, 2}, {2, 3} };
		cellSet[2] = { {0, 2}, {1, 2}, {2, 2}, {3, 2} };
		cellSet[3] = { {1, 0}, {1, 1}, {1, 2}, {1, 3} };
	} else if (type == 2) {
		// O block
		cellSet[0] = cellSet[1] = cellSet[2] = cellSet[3] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	} else if (type == 3) {
		// T block
		cellSet[0] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {1, 0}, {1, 1}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
		cellSet[3] = { {0, 1}, {1, 1}, {1, 2}, {2, 1} };
	} else if (type == 4) {
		// L block
		cellSet[0] = { {0, 2}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 0} };
		cellSet[3] = { {0, 1}, {1, 1}, {2, 1}, {2, 2} };
	} else if (type == 5) {
		// J block
		cellSet[0] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {1, 1}, {2, 0}, {2, 1} };
		cellSet[2] = { {1, 0}, {1, 1}, {1, 2}, {2, 2} };
		cellSet[3] = { {0, 1}, {0, 2}, {1, 1}, {2, 1} };
	} else if (type == 6) {
		// S block
		cellSet[0] = { {0, 1}, {0, 2}, {1, 0}, {1, 1} };
		cellSet[1] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
		cellSet[2] = { {1, 1}, {1, 2}, {2, 0}, {2, 1} };
		cellSet[3] = { {0, 1}, {1, 1}, {1, 2}, {2, 2} };
	}
	else if (type == 7) {
		// Z block
		cellSet[0] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
		cellSet[1] = { {0, 1}, {1, 0}, {1, 1}, {2, 0} };
		cellSet[2] = { {1, 0}, {1, 1}, {2, 1}, {2, 2} };
		cellSet[3] = { {0, 2}, {1, 1}, {1, 2}, {2, 1} };
	} else {
		throw invalid_argument("Invalid type");
	}
}

void Tetromino::setOrigin(int x, int y) {
	origin = { x, y };
}

int Tetromino::getType() {
	return type;
}
vector <pair <int, int>> Tetromino::getCurrentCells() {
	vector <pair <int, int>> cells;
	for (auto cell : cellSet[direction]) {
		cells.push_back({ cell.first + origin.first, cell.second + origin.second });
	}
	return cells;
}

void Tetromino::render(int offsetX, int offsetY) {
	for (auto cell : cellSet[direction]) {
		DrawRectangle((cell.first + origin.first) * CELL_SIZE + offsetX, (cell.second + origin.second) * CELL_SIZE + offsetY, CELL_SIZE - 1, CELL_SIZE - 1, COLORS.at(type));
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
	direction = (direction - 1 + 4) % 4;
}