#include "Path.h"
#include "Airport.h"
#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

Path::Path(vector <Flight *> connections) {
  flights = connections;
}

vector <Flight *> Path::getFlights() {
	return flights;
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

