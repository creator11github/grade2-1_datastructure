#include "car.h"
#include <iostream>

Car::Car()
{
	arrivalTime = 0;
	departureTime = 0;
	waitingTime = 0;
}

Car::Car(int arrivalT)
{
	arrivalTime = arrivalT;
	departureTime = 0; //to be set later
	waitingTime = 0; //to be set later
	serviceTime = 0; //to be set later
}

int Car::getArrivalTime()
{
	return arrivalTime;
}

int Car::getDepartureTime()
{
	return departureTime;
}

int Car::getWaitingTime()
{
	return waitingTime;
}

int Car::getServiceTime()
{
	return serviceTime;
}

void Car::setDepartAndWaitTime(int startServiceTime, int serviceTime)
{
    this->serviceTime = serviceTime;
    departureTime = startServiceTime + serviceTime;
    waitingTime = startServiceTime - arrivalTime;  // Calculate waiting time
}

void Car::printCarDeparture()
{
	std::cout << "A car is washed and departs!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
	std::cout << "\tDeparture time: " << departureTime << std::endl;
	std::cout << "\tWaiting time: " << waitingTime << std::endl;
	std::cout << "\tService time: " << serviceTime << std::endl;
}

void Car::printCarArrival()
{
	std::cout << "A car arrives!\n";
	std::cout << "\tArrival time: " << arrivalTime << std::endl;
}