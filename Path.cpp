#include "Path.h"
#include "Airport.h"
#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

Path::Path(string startTime) {
	this->startingTime = startTime;
}

vector <Flight *> Path::getFlights() {
	return flights;
}

void Path::addFlight(Flight * flight) {
	flights.push_back(flight);
}

string Path::getStartingTime() {
	return flights.front()->getDepartureTime();
}

string Path::getArrivalTime() {
	return formatMinutes(flights.back()->getArrivalTime());
}

string Path::getPathDuration() {
	return formatMinutes(getTotalTime());
}

int Path::getTotalTime() {
	int totalTime = 0;
	for(int i = 0, l = flights.size(); i < l; i++) {
		totalTime += flights[i]->getFlightDurationMinutes();
		if(i > 0 && i != (l - 1)) {
			totalTime += flights[i]->getArrivingAirport()->getConnectionTimeMinutes();
		}
	}
	return totalTime;
}

int Path::getStartingTimeMinutes() {
	return convertToMinutes(startingTime);
}
#include "Utilities.h"
