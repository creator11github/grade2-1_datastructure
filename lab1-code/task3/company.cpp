#include <iostream>
#include "company.h"

using namespace std;

void Company::inputEmployee()
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

void Company::findBestPaid()
{
    if (empContainer.isEmpty()) {
        cout << "No employees in the container." << endl;
        return;
    }

    DoublyLinkedList<Employee>::Iterator it = empContainer.Begin();
    bestPaid = *it;

    auto iteratorNotEqual = [](const DoublyLinkedList<Employee>::Iterator& it1, const DoublyLinkedList<Employee>::Iterator& it2) {
        return !(it1 == it2);
    };

    for (it = empContainer.Begin(); iteratorNotEqual(it, empContainer.End()); it++) {
        if (*it > bestPaid) {
            bestPaid = *it;
        }
    }
}

void Company::findBestPaidReverse()
{
    if (empContainer.isEmpty()) {
        cout << "No employees in the container." << endl;
        return;
    }

    DoublyLinkedList<Employee>::Iterator it = empContainer.rBegin();
    bestPaid = *it;

    auto iteratorNotEqual = [](const DoublyLinkedList<Employee>::Iterator& it1, const DoublyLinkedList<Employee>::Iterator& it2) {
        return !(it1 == it2);
    };

    for (it = empContainer.rBegin(); iteratorNotEqual(it, empContainer.rEnd()); it--) {
        if (*it > bestPaid) {
            bestPaid = *it;
        }
    }
}

void Company::printBestPaid() const
{
    cout << "The best-paid employee and gross pay: " << endl;
    bestPaid.output();
}