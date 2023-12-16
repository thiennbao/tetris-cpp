#include "menu.h"

Menu::Menu() : option(0), level(0) {
	InitAudioDevice();
	moveSound = LoadSound("Music/MenuMoveSound.wav");
	musicSound = LoadMusicStream("Music/MenuBackground.mp3");
	PlayMusicStream(musicSound);
}

int Menu::getOption() {
	return option;
}
int Menu::getLevel() {
	return level;
}

Color Menu::getRandomColor() {
	Color randomColor = { GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
	return randomColor;
}

void Menu::drawHelpScreen() {
	BeginDrawing();
	ClearBackground({ 26, 31, 40, 255 });


	double currentTime = GetTime();
	if (currentTime - lastColorChangeTime >= 1.0f) {
		currentTextColor = getRandomColor();
		lastColorChangeTime = currentTime;
	}

	DrawText("T", 220, 50, 70, currentTextColor);
	DrawText("E", 280, 50, 70, currentTextColor);
	DrawText("T", 340, 50, 70, currentTextColor);
	DrawText("R", 400, 50, 70, currentTextColor);
	DrawText("I", 460, 50, 70, currentTextColor);
	DrawText("S", 520, 50, 70, currentTextColor);

	// Draw rectangles for sections
	DrawRectangle(90, 120, 340, 50, { 62, 73, 93, 255 });   // Rectangle for "Objective"
	DrawRectangle(90, 260, 340, 50, { 62, 73, 93, 255 });   // Rectangle for "Controls"
	DrawRectangle(90, 400, 340, 50, { 62, 73, 93, 255 });   // Rectangle for "Scoring"

	DrawText("Objective:", 100, 130, 25, WHITE);
	DrawText("Move and rotate falling blocks to", 100, 170, 20, WHITE);
	DrawText("create solid rows, which will", 100, 190, 20, WHITE);
	DrawText("disappear and earn points.", 100, 210, 20, WHITE);

	DrawText("Controls:", 100, 270, 25, WHITE);
	DrawText("LEFT/RIGHT arrows - Move", 100, 310, 20, WHITE);
	DrawText("DOWN arrow - Move down faster", 100, 330, 20, WHITE);
	DrawText("UP arrow - Rotate", 100, 350, 20, WHITE);
	DrawText("SPACE bar - Drop", 100, 370, 20, WHITE);

	DrawText("Scoring:", 100, 420, 25, WHITE);
	DrawText("Clear 1 line - 100 points", 100, 450, 20, WHITE);
	DrawText("Clear 2 lines - 300 points", 100, 470, 20, WHITE);
	DrawText("Clear 3 lines - 500 points", 100, 490, 20, WHITE);
	DrawText("Clear 4 lines (Tetris) - Bonus", 100, 510, 20, WHITE);

	// Draw "Turn Back" button
	DrawRectangle(80, 560, 340, 50, { 62, 73, 93, 255 });
	DrawText("Press back space to exit", 90, 570, 25, WHITE);

	EndDrawing();
}

void Menu::render() {
	Texture2D background = LoadTexture(string("background-menu.png").c_str());
	Texture2D logo = LoadTexture(string("logo.png").c_str());
	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);



	while (!WindowShouldClose()) {
		UpdateMusicStream(musicSound);
		int key = GetKeyPressed();
		if (key == KEY_UP) {
			PlaySound(moveSound);
			option = (option - 1 + 3) % 3;
		} else if (key == KEY_DOWN) {
			PlaySound(moveSound);
			option = (option + 1) % 3;
		} else if (key == KEY_LEFT) {
			PlaySound(moveSound);
			if (option == 0) {
				level = (level - 1 + 4) % 4;
			}
		} else if (key == KEY_RIGHT) {
			PlaySound(moveSound);
			if (option == 0) {
				level = (level + 1) % 4;
			}
		} else if (key == KEY_SPACE || key == KEY_ENTER) {
			PlaySound(moveSound);
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
	StopMusicStream(musicSound);
	StopSound(moveSound);
}