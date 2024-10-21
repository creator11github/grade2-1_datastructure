#include <iostream>
#include <cstdlib>
#include <ctime>
#include "employee.h"
using namespace std;

Employee::Employee()
{
   name = "";
   grossPay = 0;
} // default constructor


void Employee::input(int id)
{
	//please implement this
	name = "employee" + to_string(id);
	srand(time(0));
	grossPay = rand();
} // input


void Employee::output() const
{
	cout << "name: " << name << "; gross pay: " << grossPay << endl;
} // output

void Employee::operator=(const Employee &otherEmployee)
{
	name = otherEmployee.name;
	grossPay = otherEmployee.grossPay;
}

bool Employee::operator>(const Employee &otherEmployee) const
{
   return grossPay > otherEmployee.grossPay;
} // compare

string Employee::getName() const
{
	return name;
}