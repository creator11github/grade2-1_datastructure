#ifndef CAR_H
#define CAR_H

class Car
{
private:
	int arrivalTime;
	int departureTime;
	int waitingTime;
	int serviceTime;

public:
	Car();
	Car(int arrivalT);

	int getArrivalTime();
	int getDepartureTime();
	int getWaitingTime();
	int getServiceTime();

	void setDepartAndWaitTime(int currTime, int serviceTime);
	void printCarDeparture();
	void printCarArrival();
};


#endif
