#include "board.h"

Board::Board() : content(vector <vector <int>> (20, vector <int> (10, 0))) {}

void Board::render() {
	for (int y = 0; y < content.size(); y++) {
		for (int x = 0; x < content.at(y).size(); x++) {
			DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, COLORS.at(content.at(y).at(x)));
		}
	}
}

bool Board::fill(Tetromino &tetromino) {
	for (auto cell : tetromino.getCurrentCells()) {
		if (content.at(cell.second).at(cell.first) == 0) {
			content.at(cell.second).at(cell.first) = tetromino.getType();
		} else {
			// Collide when filling
			return false;
		}
	}
	// Fill all cell successfully
	return true;
}
bool Board::checkCollision(Tetromino& tetromino) {
	try {
		for (auto cell : tetromino.getCurrentCells()) {
			if (content.at(cell.second).at(cell.first) != 0) {
				return true;
			}
		}
		return false;
	} catch (out_of_range) {
		// Cell out of the board
		return true;
	}
}

int Board::clearRows() {
	vector <int> fullRows;
	// Find rows with full of blocks
	for (int i = 0; i < content.size(); i++) {
		if (find(content.at(i).begin(), content.at(i).end(), 0) == content.at(i).end()) {
			// Push the index to list
			fullRows.push_back(i);	
		}
	}
	// Clear rows
	for (auto i : fullRows) {
		content.erase(content.begin() + i);
		content.insert(content.begin(), vector <int> (content.at(0).size(), 0));
	}
	return fullRows.size();
}
