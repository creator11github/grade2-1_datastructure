#ifndef COMPCONT_H
#define COMPCONT_H

#include "employee.h"
#include "DoublyLinkedList.h"

class Company
{
private:
    Employee bestPaid;
    DoublyLinkedList<Employee> empContainer;

public:
    void inputEmployee(); // input employee from keyboard and store in the container
    void findBestPaid(); // find the best paid employee
    void findBestPaidReverse(); // find the best paid employee from tail to head
    void printBestPaid() const;
}; 

#endif