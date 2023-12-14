#include <iostream>
#include <raylib.h>
#include "board.h"

using namespace std;

int main() {
    InitWindow(400, 800, "Tetris");
    SetTargetFPS(60);

    Board board(10, 20);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({0, 0, 0});
        board.render();
        EndDrawing();
    }

    return 0;
}