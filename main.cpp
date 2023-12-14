#include <iostream>
#include <raylib.h>
#include "board.h"
#include "tetromino.h"

using namespace std;

int main() {
    InitWindow(400, 800, "Tetris");
    SetTargetFPS(60);

    Board board(10, 20);
    Tetromino block(5);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({0, 0, 0});
        board.render();
        block.render();
        EndDrawing();
    }

    return 0;
}