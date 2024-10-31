// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "backtrack.h"
#include <iostream>
using namespace std;

int main()
{
	Application app;
	BackTrack btr(app);

	if (btr.backTrack(app.getStartPosition()))
		app.print();
	else
		cout << "There is no further solution to the problem!" << endl;

	system("pause");
	return 0;
}