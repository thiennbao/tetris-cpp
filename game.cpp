#include "game.h"

Game::Game(int level) : board(), current(GetRandomValue(1, 7)), next(GetRandomValue(1, 7)), difficulty(level), score(0), tick(1 - difficulty * 0.3), lastTick(0) {
	// Center the block
	if (current.getType() == 1) {
		current.setOrigin(3, 0); // I block
	} else {
		current.setOrigin(4, 0);
	}
	gameSound = LoadSound("Music/GameMoveSound.wav");
	gameMusic = LoadMusicStream("Music/GameBackground.mp3");
	PlayMusicStream(gameMusic);
}

void Game::action() {
	int key = GetKeyPressed();
	Tetromino prevState = current;
	if (key == KEY_UP) {
		PlaySound(gameSound);
		current.rotateCW();
	} else if (key == KEY_LEFT) {
		PlaySound(gameSound);
		current.move(-1, 0);
	} else if (key == KEY_RIGHT) {
		PlaySound(gameSound);
		current.move(1, 0);
	} else if (key == KEY_DOWN) {
		PlaySound(gameSound);
		current.move(0, 1);
	} else if (key == KEY_SPACE) {
		PlaySound(gameSound);
		while (!board.checkCollision(current)) {
			prevState = current;
			current.move(0, 1);
		}
		lastTick = tick; // Block fall instantly
	}
	if (board.checkCollision(current)) {
		// If collide, go back to cancel the action
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
			score += clearedRows * (100 + difficulty * 10);
			current = next;
			// Center the block
			if (current.getType() == 1) {
				current.setOrigin(3, 0); // I block
			}
			else {
				current.setOrigin(4, 0);
			}
			next = Tetromino(GetRandomValue(1, 7));
		}
		lastTick = now;
	}
	return false;
}

void Game::run() {
	string backgroundName = "background-" + to_string(difficulty) + ".png";
	Texture2D background = LoadTexture(backgroundName.c_str());
	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
	string difficultyText;
	if (difficulty == 0) {
		difficultyText = "Easy";
	} else if (difficulty == 1) {
		difficultyText = "Normal";
	} else if (difficulty == 2) {
		difficultyText = "Hard";
	} else if (difficulty == 3) {
		difficultyText = "Asian";
	}

	while (!WindowShouldClose()) {
		action();
		bool isOver = fall();
		UpdateMusicStream(gameMusic);
		if (isOver) {
			// Game over screen
			while (!WindowShouldClose() && GetKeyPressed() != KEY_ENTER) {
				BeginDrawing();
				ClearBackground(RAYWHITE);
				DrawTexture(background, 400 - background.width / 2, 400 - background.height / 2, WHITE);
				DrawRectangle(150, 300, 500, 200, COLORS.at(0));
				Vector2 gameOverTextSize = MeasureTextEx(font, string("GAME OVER").c_str(), 50, 5);
				DrawTextEx(font, string("GAME OVER ").c_str(), { 150 + (250 - gameOverTextSize.x / 2) , 350}, 50, 5, WHITE);
				Vector2 scoreTextSize = MeasureTextEx(font, ("Your score: " + to_string(score)).c_str(), 30, 5);
				DrawTextEx(font, ("Your score: " + to_string(score)).c_str(), { 150 + (250 - scoreTextSize.x / 2) , 425 }, 30, 5, WHITE);
				EndDrawing();
			}
			break;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		// Background
		DrawTexture(background, 800 / 2 - background.width / 2, 800 / 2 - background.height / 2, WHITE);
		// Difficulty mode
		DrawRectangle(450, 50, 300, 150, COLORS.at(0));
		DrawTextEx(font, string("Difficulty ").c_str(), { 460, 60 }, 25, 5, WHITE);
		Vector2 difficultyTextSize = MeasureTextEx(font, difficultyText.c_str(), 40, 5);
		DrawTextEx(font, difficultyText.c_str(), { 450 + (300 - difficultyTextSize.x) / 2, 110 }, 40, 5, WHITE);
		// Score box
		DrawRectangle(450, 250, 300, 150, COLORS.at(0));
		DrawTextEx(font, string("Score ").c_str(), { 460, 260 }, 25, 5, WHITE);
		Vector2 scoreTextSize = MeasureTextEx(font, to_string(score).c_str(), 40, 5);
		DrawTextEx(font, to_string(score).c_str(), { 450 + (300 - scoreTextSize.x) / 2, 310 }, 40, 5, WHITE);
		// Next box
		DrawRectangle(450, 450, 300, 300, COLORS.at(0));
		DrawTextEx(font, string("Next ").c_str(), { 460, 460 }, 25, 5, WHITE);
		if (next.getType() == 1) {
			next.render(520, 540); // I block (4 x 4)
		} else if (next.getType() == 2) {
			next.render(560, 560); // O block (2 x 2)
		} else {
			next.render(560, 540); // Remaining blocks (2 x 3)
		}
		// Board
		board.render();
		current.render();

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadFont(font);
}