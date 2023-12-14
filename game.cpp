#include "game.h"

Game::Game() : board(10, 20), current(rand() % 7), next(rand() % 7), score(0), tick(1), lastTick(0) {}

void Game::action() {
	int key = GetKeyPressed();
	Tetromino prevState = current;
	if (key == KEY_UP) {
		current.rotateCW();
	} else if (key == KEY_LEFT) {
		current.move(-1, 0);
	} else if (key == KEY_RIGHT) {
		current.move(1, 0);
	} else if (key == KEY_DOWN) {
		current.move(0, 1);
	} else if (key == KEY_SPACE) {
		while (!board.checkCollision(current)) {
			prevState = current;
			current.move(0, 1);
		}
		lastTick = tick; // Block fall instantly
	}
	if (board.checkCollision(current)) {
		// If collide, go back
		current = prevState;
	}
}
bool Game::fall() {
	double now = GetTime();
	if (now - lastTick >= tick) {
		current.move(0, 1);
		if (board.checkCollision(current)) {
			// If collide when fall
			current.move(0, -1);
			bool fillable = board.fill(current);
			if (!fillable) {
				// Game over
				return true;
			}
			int clearedRows = board.clearRows();
			score += clearedRows * 100;
			current = next;
			next = Tetromino(rand() % 7);
		}
		lastTick = now;
	}
	return false;
}

void Game::run() {
	while (!WindowShouldClose()) {
		action();
		bool isOver = fall();

		if (isOver) {
			break;
		}

		BeginDrawing();
		ClearBackground({ 26, 31, 40, 255 });
		board.render();
		current.render();
		EndDrawing();
	}
}