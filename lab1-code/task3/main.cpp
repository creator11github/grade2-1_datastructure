#include <iostream>
#include "company.h"

using namespace std;

int main()
{
    Company cmp;

    cmp.inputEmployee();

    cmp.findBestPaid();
    cout << "Search for the highest earning employee from start to finish:" << endl;
    cmp.printBestPaid();

    cmp.findBestPaidReverse();
    cout << "Search for the highest earning employee from finish to start:" << endl;
    cmp.printBestPaid();

    return 0;
}