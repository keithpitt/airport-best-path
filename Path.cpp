#include "Path.h"
#include "Airport.h"
#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

Path::Path(string startTime) {
	this->startingTime = startTime;
};

Path::Path(int startTimeMinutes) {
	this->startingTime = formatMinutes(startTimeMinutes);
};

Path::Path(Path * other) {
  this->startingTime = other->getStartingTime();
  vector <Flight*> flights = other->getFlights();
	for(int i = 0, l = flights.size(); i < l; i++) {
    this->addFlight(flights[i]);
  }
}

vector <Flight *> Path::getFlights() {
	return flights;
};

void Path::addFlight(Flight * flight) {
	flights.push_back(flight);
};

void Path::removeLastFlight() {
	flights.pop_back();
};

void Path::clearFlights() {
  flights.clear();
};

string Path::getDepartureTime() {
  if(flights.size() > 0) {
    return flights.front()->getDepartureTime();
  } else {
    return "-";
  }
};

string Path::getArrivalTime() {
  if(flights.size() > 0) {
    return formatMinutes(flights.back()->getArrivalTime());
  } else {
    return "-";
  }
};

string Path::getPathDuration() {
  if(flights.size() > 0) {
    return formatMinutes(getTotalTime());
  } else {
    return "-";
  }
};

string Path::getStartingTime() {
	return this->startingTime;
};

int Path::getTotalTime() {
	int totalTime = 0;
	for(int i = 0, l = flights.size(); i < l; i++) {
		totalTime += flights[i]->getFlightDurationMinutes();
		if(i > 0 && i != (l - 1)) {
			totalTime += flights[i]->getArrivingAirport()->getConnectionTimeMinutes();
		}
	}
	return totalTime;
};

int Path::getStartingTimeMinutes() {
	return convertToMinutes(startingTime);
};

