#include "application.h"
#include <iostream>
#include <cmath>

using namespace std;

const int BOARD_SIZE = 8;

static int solution[BOARD_SIZE];  // solution[i] = 皇后在第i行的列位置
static int numQueens;             // 已放置的皇后数量

void Application::initialize()
{
    numQueens = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
        solution[i] = -1;  // 初始化为-1
}

Position Application::getStartPosition()
{
    initialize();
    // 起始位置行号为 -1
    Position startPosition(-1, -1);
    return startPosition;
}

bool Application::isValid(const Position& p)
{
    int row = p.getRow();
    int col = p.getColumn();

    for (int i = 0; i < row; i++)
    {
        int existingCol = solution[i];
        // 检查列冲突
        if (col == existingCol)
            return false;
        // 检查对角线冲突
        if (abs(row - i) == abs(col - existingCol))
            return false;
    }
    return true;
}

void Application::progress(const Position& p)
{
    int row = p.getRow();
    int col = p.getColumn();
    if (row >= 0)
    {
        solution[row] = col;
        numQueens++;
    }
}

bool Application::success(const Position& p)
{
    return numQueens == BOARD_SIZE;
}

void Application::goBack(const Position& p)
{
    int row = p.getRow();
    if (row >= 0)
    {
        solution[row] = -1;
        numQueens--;
    }
}

void Application::print()
{
    cout << "One solution to this problem is:" << endl;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << "|";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (solution[i] == j)
                cout << "Q|";
            else
                cout << "_|";
        }
        cout << endl;
    }
}

// Iterator 实现

// 定义用于存储迭代器状态的结构体
struct IteratorState
{
    int row;    // 当前行号
    int col;    // 当前列号
};

Application::Iterator::Iterator()
{
    currItrPosPtr = nullptr;
}

Application::Iterator::Iterator(const Position& currP)
{
    // 分配迭代器状态并初始化
    IteratorState* state = new IteratorState;
    state->row = currP.getRow() + 1; // 移动到下一行
    state->col = 0;                  // 从第0列开始
    if (state->row < BOARD_SIZE)
    {
        currItrPosPtr = state;
    }
    else
    {
        delete state;
        currItrPosPtr = nullptr;
    }
}

Position Application::Iterator::getNextPosition()
{
    IteratorState* state = (IteratorState*)currItrPosPtr;
    Position nextPos(state->row, state->col);
    state->col++;  // 为下次调用递增列号
    return nextPos;
}

bool Application::Iterator::noNextPosition()
{
    IteratorState* state = (IteratorState*)currItrPosPtr;
    if (state == nullptr)
        return true;

    if (state->col >= BOARD_SIZE)
        return true;
    else
        return false;
}

Application::Iterator::~Iterator()
{
    if (currItrPosPtr != nullptr)
    {
        delete (IteratorState*)currItrPosPtr;
        currItrPosPtr = nullptr;
    }
}