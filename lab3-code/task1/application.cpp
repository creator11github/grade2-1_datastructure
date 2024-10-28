#include "application.h"
#include <iostream>
using namespace std;

#define NULL 0

// Initialize the maze to all 0s, representing an 8x8 chessboard
int maze[8][8] = {0};

void Application::initialize() {}

Position Application::getStartPosition()
{
    return Position(0, 0);
}

bool Application::isValid(const Position& p) {
    int row = p.getRow();
    int column = p.getColumn();

    // Check the current row, column, and diagonals for any queens
    for (int i = 0; i < 8; ++i) {
        if (maze[row][i] || maze[i][column]) {
            return false;
        }
        // Check the diagonals
        int d1 = row - i + column;
        int d2 = row + i - column;
        if (maze[8 + d1] || maze[8 - d2]) {
            return false;
        }
    }
    return true;
}

void Application::progress(const Position& p) {
    maze[p.getRow()][p.getColumn()] = 1;
}

bool Application::success(const Position& p) {
    return p.getRow() == 7;
}

void Application::goBack(const Position& p) {
    maze[p.getRow()][p.getColumn()] = 0;
}

void Application::print() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

struct itrPosition {
    int row;
    int column;
};

Application::Iterator::Iterator(const Position& currPos) {
    itrPosition* p = new itrPosition;
    p->row = currPos.getRow();
    p->column = currPos.getColumn();
    currItrPosPtr = p;
}

Position Application::Iterator::getNextPosition() {
    itrPosition* pos = (itrPosition*)currItrPosPtr;
    if (pos->column + 1 < 8) {
        pos->column++;
        return Position(pos->row, pos->column);
    } else {
        delete pos;
        currItrPosPtr = NULL;
        return Position(-1, -1); // Indicates no more positions
    }
}

bool Application::Iterator::noNextPosition() {
    itrPosition* pos = (itrPosition*)currItrPosPtr;
    return pos == NULL || pos->column + 1 >= 8;
}

Application::Iterator::~Iterator() {
    delete (itrPosition*)currItrPosPtr;
}