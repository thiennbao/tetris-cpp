#include "menu.h"

Menu::Menu() : option(0), level(0) {}

int Menu::getOption() {
	return option;
}
int Menu::getLevel() {
	return level;
}

void Menu::render() {
	Texture2D background = LoadTexture(string("background-menu.png").c_str());
	Texture2D logo = LoadTexture(string("logo.png").c_str());
	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	while (!WindowShouldClose()) {
		int key = GetKeyPressed();
		if (key == KEY_UP) {
			option = (option - 1 + 3) % 3;
		} else if (key == KEY_DOWN) {
			option = (option + 1) % 3;
		} else if (key == KEY_LEFT) {
			if (option == 0) {
				level = (level - 1 + 4) % 4;
			}
		} else if (key == KEY_RIGHT) {
			if (option == 0) {
				level = (level + 1) % 4;
			}
		} else if (key == KEY_SPACE || key == KEY_ENTER) {
			break;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);
		// Background
		DrawTexture(background, 400 - background.width / 2, 400 - background.height / 2, WHITE);
		DrawTexture(logo, 400 - logo.width / 2, 75, WHITE);
		// Buttons
		DrawRectangle(150, 375, 500, 100, option == 0 ? DARKBLUE : COLORS.at(0));
		string levelText;
		if (level == 0) {
			levelText = "<  Easy  >";
		} else if (level == 1) {
			levelText = "<  Normal  >";
		} else if (level == 2) {
			levelText = "<  Hard  >";
		} else if (level == 3) {
			levelText = "<  Asian  >";
		}
		DrawText(levelText.c_str(), 150 + 250 - MeasureText(levelText.c_str(), 40) / 2, 405, 40, WHITE);
		DrawRectangle(150, 500, 500, 100, option == 1 ? DARKBLUE : COLORS.at(0));
		DrawText("Help", 150 + 250 - MeasureText("Help", 40) / 2, 530, 40, WHITE);
		DrawRectangle(150, 625, 500, 100, option == 2 ? DARKBLUE : COLORS.at(0));
		DrawText("Quit", 150 + 250 - MeasureText("Quit", 40) / 2, 655, 40, WHITE);

		EndDrawing();
	}

	UnloadTexture(background);
	UnloadTexture(logo);
	UnloadFont(font);
}
