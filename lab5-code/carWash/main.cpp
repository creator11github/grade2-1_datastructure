#include "car.h"
#include "washCmp.h"
#include <iostream>
using namespace std;

int main()
{
	double lambda, mu;
    int numCarsToSimulate;

    // User inputs for arrival rate, service rate, and number of cars
    cout << "Please input the mean arrival rate: ";
    cin >> lambda;
    cout << "Please input the mean service rate: ";
    cin >> mu;
    cout << "Please input the number of cars to be simulated: ";
	
    cin >> numCarsToSimulate;

    // Create WashCmp object and start simulation
    WashCmp cmp(lambda, mu, numCarsToSimulate);
	cmp.simulation();
	cmp.printStatistic();
	
	system("pause");
	return 0;
}
