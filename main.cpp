#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

int main() {
    InitWindow(400, 800, "Tetris");
    SetTargetFPS(60);
    srand(GetTime());

    while (!WindowShouldClose()) {
        Game game;
        game.run();
    }

    CloseWindow();

    return 0;
}