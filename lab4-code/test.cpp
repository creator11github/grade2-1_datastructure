#include <iostream>
#include "list.h"

int main() {
    // 1. 测试默认构造函数
    list<int> lst1;
    if (lst1.empty()) {
        std::cout << "1. Default constructor test passed." << std::endl;
    } else {
        std::cout << "1. Default constructor test failed." << std::endl;
    }

    // 2. 测试析构函数（无法直接测试，程序结束时自动调用）

    // 3. 测试拷贝构造函数
    lst1.push_back(10);
    list<int> lst2(lst1);
    if (!lst2.empty() && lst2.size() == lst1.size() && *lst2.begin() == *lst1.begin()) {
        std::cout << "3. Copy constructor test passed." << std::endl;
    } else {
        std::cout << "3. Copy constructor test failed." << std::endl;
    }

    // 4. 测试push_front
    lst1.push_front(5);
    if (lst1.size() == 2 && *lst1.begin() == 5) {
        std::cout << "4. push_front test passed." << std::endl;
    } else {
        std::cout << "4. push_front test failed." << std::endl;
    }

    // 5. 测试push_back
    lst1.push_back(15);
    if (lst1.size() == 3 && *(--lst1.end()) == 15) {
        std::cout << "5. push_back test passed." << std::endl;
    } else {
        std::cout << "5. push_back test failed." << std::endl;
    }

    // 6. 测试insert
    list<int>::iterator it = lst1.begin();
    ++it;
    lst1.insert(it, 8);  // 插入到第二个位置
    it = lst1.begin();
    ++it;
    if (*it == 8) {
        std::cout << "6. insert test passed." << std::endl;
    } else {
        std::cout << "6. insert test failed." << std::endl;
    }

    // 7. 测试pop_front
    lst1.pop_front();
    if (lst1.size() == 3 && *lst1.begin() == 8) {
        std::cout << "7. pop_front test passed." << std::endl;
    } else {
        std::cout << "7. pop_front test failed." << std::endl;
    }

    // 8. 测试pop_back
    lst1.pop_back();
    if (lst1.size() == 2 && *(--lst1.end()) == 10) {
        std::cout << "8. pop_back test passed." << std::endl;
    } else {
        std::cout << "8. pop_back test failed." << std::endl;
    }

    // 9. 测试erase(iterator position)
    it = lst1.begin();  // 指向8
    lst1.erase(it);
    if (lst1.size() == 1 && *lst1.begin() == 10) {
        std::cout << "9. erase(iterator position) test passed." << std::endl;
    } else {
        std::cout << "9. erase(iterator position) test failed." << std::endl;
    }

    // 10. 测试erase(iterator first, iterator last)
    lst1.push_back(20);
    lst1.push_back(30);
    it = lst1.begin();  // 指向10
    list<int>::iterator it2 = lst1.end();  // 指向尾后
    --it2;  // 指向30
    lst1.erase(it, it2);  // 删除10,20
    if (lst1.size() == 1 && *lst1.begin() == 30) {
        std::cout << "10. erase(iterator first, iterator last) test passed." << std::endl;
    } else {
        std::cout << "10. erase(iterator first, iterator last) test failed." << std::endl;
    }

    // 11. 测试size()
    if (lst1.size() == 1) {
        std::cout << "11. size() test passed." << std::endl;
    } else {
        std::cout << "11. size() test failed." << std::endl;
    }

    // 12. 测试empty()
    lst1.pop_back();
    if (lst1.empty()) {
        std::cout << "12. empty() test passed." << std::endl;
    } else {
        std::cout << "12. empty() test failed." << std::endl;
    }

    // 13. 测试begin()
    lst1.push_back(40);
    if (*lst1.begin() == 40) {
        std::cout << "13. begin() test passed." << std::endl;
    } else {
        std::cout << "13. begin() test failed." << std::endl;
    }

    // 14. 测试end()
    it = lst1.end();
    --it;
    if (*it == 40) {
        std::cout << "14. end() test passed." << std::endl;
    } else {
        std::cout << "14. end() test failed." << std::endl;
    }

    // 15. 测试operator=()
    list<int> lst3;
    lst3 = lst1;
    if (lst3.size() == lst1.size() && *lst3.begin() == *lst1.begin()) {
        std::cout << "15. operator=() test passed." << std::endl;
    } else {
        std::cout << "15. operator=() test failed." << std::endl;
    }

    // 16. 测试splice()
    list<int> lst4;
    lst4.push_back(50);
    lst4.push_back(60);
    it = lst1.begin();
    lst1.splice(it, lst4);
    if (lst1.size() == 3 && *lst1.begin() == 50 && *(++lst1.begin()) == 60 && *(--lst1.end()) == 40 && lst4.empty()) {
        std::cout << "16. splice() test passed." << std::endl;
    } else {
        std::cout << "16. splice() test failed." << std::endl;
    }

    // 17. 测试iterator的operator++()
    it = lst1.begin(); // 指向50
    ++it;
    if (*it == 60) {
        std::cout << "17. iterator operator++() test passed." << std::endl;
    } else {
        std::cout << "17. iterator operator++() test failed." << std::endl;
    }

    // 18. 测试iterator的operator++(int)
    it++;
    if (*it == 40) {
        std::cout << "18. iterator operator++(int) test passed." << std::endl;
    } else {
        std::cout << "18. iterator operator++(int) test failed." << std::endl;
    }

    // 19. 测试iterator的operator--()
    --it;
    if (*it == 60) {
        std::cout << "19. iterator operator--() test passed." << std::endl;
    } else {
        std::cout << "19. iterator operator--() test failed." << std::endl;
    }

    // 20. 测试iterator的operator--(int)
    it--;
    if (*it == 50) {
        std::cout << "20. iterator operator--(int) test passed." << std::endl;
    } else {
        std::cout << "20. iterator operator--(int) test failed." << std::endl;
    }

    // 21. 测试iterator的operator*()
    if (*it == 50) {
        std::cout << "21. iterator operator*() test passed." << std::endl;
    } else {
        std::cout << "21. iterator operator*() test failed." << std::endl;
    }

    // 22. 测试iterator的operator==()
    list<int>::iterator it_test = lst1.begin();
    if (it == it_test) {
        std::cout << "22. iterator operator==() test passed." << std::endl;
    } else {
        std::cout << "22. iterator operator==() test failed." << std::endl;
    }

    return 0;
}