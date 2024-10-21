#include <iostream>
#include "company.h"

using namespace std;

void Company::inputEmployee()	//Task 1: please implement this!
{
    while (true) {
        Employee emp;
        emp.input();
        if (emp.getName() == "*") {
            break;
        }
        empContainer.addHead(emp);
    }
}

void Company::findBestPaid()	//Task 2: please implement this!
{
    if (empContainer.isEmpty()) {
        cout << "No employees in the container." << endl;
        return;
    }

    ListCont<Employee>::Iterator it = empContainer.Begin();
    bestPaid = *it;

    auto iteratorNotEqual = [](const ListCont<Employee>::Iterator& it1, const ListCont<Employee>::Iterator& it2) {
        return !(it1 == it2);
    };

    for (it = empContainer.Begin(); iteratorNotEqual(it, empContainer.End()); it++) {
        if (*it > bestPaid) {
            bestPaid = *it;
        }
    }
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
