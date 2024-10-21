#include <iostream>
#include "linked-todo.h"
using namespace std;

int main() {
    Linked<int> linkobj;
    for (int i = 1; i <= 100; ++i) {
        linkobj.push_front(i);
    }

    for (auto it = linkobj.begin(); it != linkobj.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}