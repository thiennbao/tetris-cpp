#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "menu.h"
#include "game.h"

using namespace std;

int main() {
    InitWindow(800, 800, "Tetris");
    SetTargetFPS(60);
    Menu menu;

    while (!WindowShouldClose()) {
        menu.render();

        if (menu.getOption() == 0) {
            Game game(menu.getLevel());
            game.run();
        } else if (menu.getOption() == 1) {
            // Add help screen later
            while (!IsKeyPressed(KEY_BACKSPACE))
            {
                menu.drawHelpScreen();
            }
        } else {
            // Quit
            break;
        }

    }

    CloseWindow();

    return 0;
}