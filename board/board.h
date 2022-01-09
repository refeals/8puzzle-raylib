#pragma once
#include "raylib.h"
#include <vector>

class Board {
private:
    int pieceSize; // piece size in pixels
    std::vector<int> board; // board array with values for each position
    int currentIndexOfBlank; // current index for the blank piece

public:
    Board();
    void randomizeBoard();
    int findIndexFromValue(int key = 9);
    void swapFromArray(int index1, int index2);
    void swapUp(int i);
    void swapDown(int i);
    void swapLeft(int i);
    void swapRight(int i);

    int getPieceSize();
    int getBoardAt(int i);
    int getCurrentIndexOfBlank();
    void setBoardAt(int i, int value);
    void setCurrentIndexOfBlank(int value);

    void getInput();
    void draw();
};