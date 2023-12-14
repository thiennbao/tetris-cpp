#include "board.h"

Board::Board(int width, int height) : content(vector <vector <int>> (height, vector <int> (width, 4))) {}

void Board::render() {
	for (int y = 0; y < content.size(); y++) {
		for (int x = 0; x < content.at(y).size(); x++) {
			if (content.at(y).at(x) != 0) {
				DrawRectangle(x * CELL_SIZE + 1, y * CELL_SIZE + 1, CELL_SIZE - 1, CELL_SIZE - 1, COLORS.at(content.at(y).at(x) - 1));
			}
		}
	}
}