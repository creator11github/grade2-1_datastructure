#include "washCmp.h"
#include <iostream>

const int WashCmp::CAPACITY = 5 + 1;

WashCmp::WashCmp()
{
	totalWaitingTime = 0;
	numServedCars = 0;
}

void WashCmp::printStatistic()
{
	std::cout << "Number of served cars: " << numServedCars << std::endl;
	std::cout << "Total waiting time: " << totalWaitingTime << std::endl;
	if(numServedCars > 0)
		std::cout << "The average waiting time is: " << (double)totalWaitingTime / numServedCars << std::endl;
	else
		std::cout << "The average waiting time is not applicable!" << std::endl;
}

void WashCmp::simulation()
{
	int arrivalTime = getNextArrival(); //get the next arrival time from keyboard input

	while(arrivalTime != 999)
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

int WashCmp::getNextArrival()
{
	int tempT;
	std::cout << "Please input the next arrival time (input 999 to terminate):\n";
	std::cin >> tempT;
	return tempT;
}

void WashCmp::processArrivalEmptyQ(int arrivalTime)
{
	Car arrivedCar = Car(arrivalTime);
	arrivedCar.setDepartAndWaitTime(arrivalTime); //set the departure and waiting time of the arrived car
	arrivedCar.printCarArrival(); //print the arrival information of the arrived car
	carQueue.push(arrivedCar); //set the arrival time of the arrived car
}

void WashCmp::processArrivalNonEmptyQ(int arrivalTime)
{
	if (carQueue.size() < CAPACITY) //add the arrived car to the waiting queue
	{
		Car arrivedCar = Car(arrivalTime);
		arrivedCar.printCarArrival(); //print the arrival information of the arrived car
		carQueue.push(arrivedCar); //set the arrival time of the arrived car
	}
	else //the arrived car leaves
		std::cout << "OVERFLOW!!!\n";
}

void WashCmp::processDeparture()
{
	int currTime = carQueue.front().getDepartureTime(); //get the current time

	totalWaitingTime += carQueue.front().getWaitingTime(); //update statistics
	numServedCars++; //update statistics

	carQueue.front().printCarDeparture(); //print departure information 
	carQueue.pop(); //departs

	if (!carQueue.empty())                                 //set the departure and waiting time of
		carQueue.front().setDepartAndWaitTime(currTime);   //the current front car in the queue
}

void WashCmp::processRemain() //wash the remaining cars in the queue
{
	while (!carQueue.empty())
		processDeparture();
}