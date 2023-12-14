#include "game.h"

Game::Game() : board(10, 20), current(rand() % 7), score(0), tick(1), lastTick(0) {}

void Game::action() {
	int key = GetKeyPressed();
	if (key == KEY_LEFT) {
		current.move(-1, 0);
	} else if (key == KEY_RIGHT) {
		current.move(1, 0);
	} else if (key == KEY_UP) {
		current.rotateCW();
	} else if (key == KEY_DOWN) {
		current.move(0, 1);
	}
}
void Game::fall() {
	double now = GetTime();
	if (now - lastTick >= tick) {
		current.move(0, 1);
		lastTick = now;
	}
}

void Game::run() {
	while (!WindowShouldClose()) {
		action();
		fall();

		BeginDrawing();
		ClearBackground({ 26, 31, 40, 255 });
		board.render();
		current.render();
		EndDrawing();
	}
}