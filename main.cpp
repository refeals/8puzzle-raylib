#include "raylib.h"
#include "board/board.h"

int main(void) {
    Board* b = new Board();

    InitWindow(b->getPieceSize() * 3, b->getPieceSize() * 3, "8-puzzle");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        b->getInput();
        b->draw();

        EndDrawing();
    }

    CloseWindow();
    delete b;

    return 0;
}