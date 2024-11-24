#ifndef WASH_H
#define WASH_H

#include <queue>
#include "car.h"

class WashCmp
{
private:
	std::queue<Car> carQueue;

	int numServedCars;
	double totalWaitingTime;
	int numCarsToSimulate;
	double arrivalTimeNow; //previous arrival time

	double lambda;          // Arrival rate (lambda)
    double mu;              // Service rate (mu)

    double getNextArrival();        // Generate next arrival time
    double getServiceTime(); // Generate next service time
	void processArrivalNonEmptyQ(double currTime); //a car arrives and the waiting queue is not empty
	void processArrivalEmptyQ(double currTime); //a car arrives and the waiting queue is empty
	void processDeparture();
	void processRemain(); //no more arriving cars, process the remaining cars in the waiting queue

public:
	WashCmp(double lambda, double mu, int numCars);
	void simulation();
	void printStatistic();
};


#endif