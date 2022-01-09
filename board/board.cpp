#include <iostream>
#include "raylib.h"
#include "board.h"

Board::Board() {
    pieceSize = 100;
    board = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    currentIndexOfBlank = 8;

    SetRandomSeed(time(NULL));
    randomizeBoard();
}

int Board::findIndexFromValue(int key) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == key) {
            return i;
        }
    }
    return -1;
}

void Board::swapFromArray(int index1, int index2) {
    int temp = board[index1];
    board[index1] = board[index2];
    board[index2] = temp;
}

void Board::swapUp(int i) {
    swapFromArray(i, i + 3);
}
void Board::swapDown(int i) {
    swapFromArray(i, i - 3);
}
void Board::swapLeft(int i) {
    swapFromArray(i, i + 1);
}
void Board::swapRight(int i) {
    swapFromArray(i, i - 1);
}

void Board::randomizeBoard() {
    for (int i = 0; i < 10000; i++) {
        int random = GetRandomValue(1, 4);
        int currentIndexOfBlank = findIndexFromValue(9);

        switch (random) {
        case 1:
            if (currentIndexOfBlank < 6) {
                swapUp(currentIndexOfBlank);
            }
            break;
        case 2:
            if (currentIndexOfBlank > 2) {
                swapDown(currentIndexOfBlank);
            }
            break;
        case 3:
            if (currentIndexOfBlank % 3 != 2) {
                swapLeft(currentIndexOfBlank);
            }
            break;
        case 4:
            if (currentIndexOfBlank % 3 != 0) {
                swapRight(currentIndexOfBlank);
            }
            break;
        default:
            break;
        }
    }
}

int Board::getPieceSize() {
    return pieceSize;
}

int Board::getBoardAt(int i) {
    return board[i];
}

int Board::getCurrentIndexOfBlank() {
    return currentIndexOfBlank;
}

void Board::setBoardAt(int i, int value) {
    board[i] = value;
}

void Board::setCurrentIndexOfBlank(int value) {
    currentIndexOfBlank = value;
}

void Board::getInput() {
    int index = findIndexFromValue(9);
    setCurrentIndexOfBlank(index);
    int cur = getCurrentIndexOfBlank();

    // Get Input
    if (IsKeyPressed(KEY_UP)) {
        if (cur < 6) {
            swapUp(cur);
        }
    }
    if (IsKeyPressed(KEY_DOWN)) {
        if (cur > 2) {
            swapDown(cur);
        }
    }
    if (IsKeyPressed(KEY_LEFT)) {
        if (cur % 3 != 2) {
            swapLeft(cur);
        }
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        if (cur % 3 != 0) {
            swapRight(cur);
        }
    }
}

void Board::draw() {
    for (int i = 0; i < 9; i++) {
        // get piece coordinate
        int pX = (i % 3) * pieceSize;
        int pY = (int)(i / 3) * pieceSize;

        // draw rects
        DrawRectangle(pX, pY, pieceSize, pieceSize, GRAY);

        if (board[i] != 9) {
            // get text coordinate
            int tX = pX + (pieceSize / 2) - 8;
            int tY = pY + (pieceSize / 2) - 8;

            // draw
            DrawRectangle(pX + 1, pY + 1, pieceSize - 2, pieceSize - 2, LIGHTGRAY);
            DrawText(std::to_string(board[i]).c_str(), tX, tY, 16, BLACK);
        } else {
            DrawRectangle(pX + 1, pY + 1, pieceSize - 2, pieceSize - 2, WHITE);
        }
    }
}