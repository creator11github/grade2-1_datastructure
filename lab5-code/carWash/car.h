#ifndef CAR_H
#define CAR_H

class Car
{
private:
	double arrivalTime;
	double departureTime;
	double waitingTime;
	double serviceTime;

public:
	Car();
	Car(double arrivalT);

	double getArrivalTime();
	double getDepartureTime();
	double getWaitingTime();
	double getServiceTime();

	void setDepartAndWaitTime(double currTime, double serviceTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
