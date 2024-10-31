#include "backtrack.h"

BackTrack::BackTrack() {}

BackTrack::BackTrack(const Application& thisApp)
{
    this->app = thisApp;
}

bool BackTrack::backTrack(const Position& currPos)
{
    app.progress(currPos);

    if (app.success(currPos))
    {
        app.print(); // 打印当前解
        app.goBack(currPos); // 回溯以寻找下一个解
        return false; // 继续寻找其他解
    }
    else
    {
        Application::Iterator itr(currPos);
        Position nextPos;

        while (!itr.noNextPosition())
        {
            nextPos = itr.getNextPosition();
            if (app.isValid(nextPos) && backTrack(nextPos)) // 递归调用
                return true;
        }
        // 无法从 currPos 到达目标
        app.goBack(currPos); // 回溯
        return false; // 从 currPos 无解
    }
}