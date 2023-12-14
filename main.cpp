#include <iostream>
#include <raylib.h>

using namespace std;

int main() {
    Color green = { 25, 135, 84 };
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(green);
        EndDrawing();
    }

    return 0;
}