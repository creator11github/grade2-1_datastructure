#include <iostream>
#include <string>
#include "network.h"

using namespace std;

int main()
{
    network<string> school_map;

    // 插入顶点和边
    school_map.insert_edge("桃园", "桃园食堂", 121);
    school_map.insert_edge("桃园食堂", "橘园食堂", 199);
    school_map.insert_edge("橘园食堂", "第二运动场", 149);
    school_map.insert_edge("第二运动场", "志成大厦", 217);
    school_map.insert_edge("志成大厦", "杏园食堂", 51);
    school_map.insert_edge("杏园食堂", "杏园", 113);
    school_map.insert_edge("杏园", "北区图书馆", 250);
    school_map.insert_edge("北区图书馆", "禾丰楼", 300);
    school_map.insert_edge("禾丰楼", "北区校医院", 100);
    school_map.insert_edge("北区校医院", "第一运动场", 349);
    school_map.insert_edge("第一运动场", "出版社", 310);
    school_map.insert_edge("出版社", "八教", 111);
    school_map.insert_edge("八教", "李园", 110);
    school_map.insert_edge("李园", "李园食堂", 220);
    school_map.insert_edge("李园食堂", "中心图书馆", 200);
    school_map.insert_edge("中心图书馆", "软件学院", 200);
    school_map.insert_edge("软件学院", "二十八教", 100);
    school_map.insert_edge("二十八教", "二十七教", 100);
    school_map.insert_edge("二十七教", "二十六教", 100);
    school_map.insert_edge("志成大厦", "二十八教", 303);
    school_map.insert_edge("志成大厦", "八教", 342);
    school_map.insert_edge("桃园", "第二运动场", 182);
    school_map.insert_edge("第二运动场", "禾丰楼", 379);

    string start, finish;

    cout << "\n请输入起点和终点顶点：" << endl;
    cin >> start >> finish;
    cout << endl;

    pair<list<string>, double> result = school_map.get_shortest_path(start, finish);
    list<string>::iterator vertex_list_itr;

    if (result.first.empty())
        cout << "路径不存在！" << endl;
    else
    {
        for (vertex_list_itr = result.first.begin();
            vertex_list_itr != result.first.end();
            vertex_list_itr++)
            cout << *vertex_list_itr << endl;
        cout << endl << "从 " << start << " 到 " << finish << " 的最短路径结束" << endl;
        cout << "路径权重 = " << result.second << endl;
    }

    return 0;
}