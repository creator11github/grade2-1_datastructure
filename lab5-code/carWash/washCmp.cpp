#include "washCmp.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

WashCmp::WashCmp(double lambda, double mu, int numCars)
{
	this->lambda = lambda;
	this->mu = mu;
	this->numCarsToSimulate = numCars;
	totalWaitingTime = 0;
	numServedCars = 0;
	arrivalTimeNow = 0;
	srand(time(0));
}

int WashCmp::getNextArrival()
{
    double p = (double)rand() / RAND_MAX;
    double deltaT = (-1 / lambda) * log(1 - p);
    return arrivalTimeNow += (int)round(deltaT);
}

int WashCmp::getServiceTime()
{
    double q = (double)rand() / RAND_MAX;
    double serviceTime = (-1 / mu) * log(1 - q);
    return (int)round(serviceTime);
}

void WashCmp::processArrivalEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.setDepartAndWaitTime(arrivalTime,getServiceTime()); //set the departure and waiting time of the arrived car
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processArrivalNonEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processDeparture()
{
	int currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics
	numServedCars++; //update statistics

	carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())                                 //set the departure and waiting time of
		carQueue.front().setDepartAndWaitTime(currTime,getServiceTime());   //the current front car in the queue
}

void WashCmp::processRemain() //wash the remaining cars in the queue
{
	while (!carQueue.empty())
		processDeparture();
}

void WashCmp::simulation()
{
	int arrivalTime = getNextArrival(); //get the first arrival time

	while(numServedCars < numCarsToSimulate)
	{
		if (carQueue.empty()) //queue empty, process arrival
		{
			processArrivalEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(); //get next arrival
		}
		else if (arrivalTime < carQueue.front().getDepartureTime()) //arrival first, process arrival
		{
			processArrivalNonEmptyQ(arrivalTime);
			arrivalTime = getNextArrival(); //get next arrival
		}
		else //departure first or of the same time, process departure
		{
			processDeparture(); //no need to get next arrival
		}
	}

	//no more arrival, process the remaining cars in the queue
	processRemain();
}

void WashCmp::printStatistic()
{
	std::cout << "Number of served cars: " << numServedCars << std::endl;
	std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
	if(numServedCars > 0)
		std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	else
		std::cout << "The average waiting time is not applicable!" << std::endl;
    // Calculate theoretical average waiting time
    double thAvgWaitTime = lambda / (mu * (mu - lambda));
    std::cout << "The theoretical average waiting time is: " << thAvgWaitTime << std::endl;
}