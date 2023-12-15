#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "game.h"

using namespace std;

int main() {
    InitWindow(800, 800, "Tetris");
    SetTargetFPS(60);
    srand(time(0));

    while (!WindowShouldClose()) {
        Game game(0);
        game.run();
    }

    CloseWindow();

    return 0;
}