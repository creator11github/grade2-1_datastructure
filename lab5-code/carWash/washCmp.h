#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;

	int numServedCars;
	int totalWaitingTime;
	int numCarsToSimulate;
	int arrivalTimeNow; //previous arrival time

	double lambda;          // Arrival rate (lambda)
    double mu;              // Service rate (mu)

    int getNextArrival();        // Generate next arrival time
    int getServiceTime(); // Generate next service time
	void processArrivalNonEmptyQ(int currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(int currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp(double lambda, double mu, int numCars);
	void simulation();
	void printStatistic();
};


#endif