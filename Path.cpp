#include "Path.h"
#include "Airport.h"
#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

Path::Path(vector <Flight *> connections) {
	flights = connections;
}

void Path::setStartTime(int startTime) {
  startingTimeMinutes = startTime;
};

vector <Flight *> Path::getFlights() {
	return flights;
};

string Path::getStartingTime() {
	if(flights.size() > 0) {
		return formatMinutes(startingTimeMinutes);
	} else {
		return "-";
	}
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
    int totalTime = getTotalTime();
    int days = totalTime / (24 * 60);
		return formatMinutes((days * 24 * 60) + flights.back()->getArrivalTime());
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

  if(flights.size() > 1) {
    totalTime += flights.front()->getDepartureTimeMinutes() - startingTimeMinutes;
    for(int i = 0, l = flights.size(); i < l; i++) {
      if(i > 0) {
        int timeToAdd = 0;
        if(flights[i]->getDepartureTimeMinutes() < flights[i-1]->getDepartureTimeMinutes()) {
          timeToAdd = (60 * 24) - flights[i-1]->getDepartureTimeMinutes();
          timeToAdd += flights[i]->getDepartureTimeMinutes();
        } else {
          timeToAdd = flights[i]->getDepartureTimeMinutes() - flights[i-1]->getDepartureTimeMinutes();
        }
        totalTime += timeToAdd;
      }
    }
    totalTime += flights.back()->getFlightDurationMinutes();
  } else {
		totalTime += flights.front()->getFlightDurationMinutes();
  }

  return totalTime;

};

