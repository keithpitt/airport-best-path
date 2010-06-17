#include "Airport.h"
#include "Flight.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <map>

Airport::Airport(string code, string description, string connectionTime) {
	this->code = code;
	this->description = description;
	this->connectionTime = connectionTime;
};

string Airport::getDescription() {
	return description;
};

string Airport::getConnectionTime() {
	return connectionTime;
};

string Airport::getCode() {
	return code;
};

int Airport::getArrivalsCount() {
	return arrivals.size();
};

int Airport::getDeparturesCount() {
	return departures.size();
};

vector <Flight*> Airport::getDepartures() {
	return departures;
};

vector <Flight*> Airport::getArrivals() {
	return arrivals;
};

int Airport::getConnectionTimeMinutes() {
	int position = connectionTime.find_first_of(":");
	int hours = atoi(connectionTime.substr(0, position).c_str());
	int minutes = atoi(connectionTime.substr(position + 1).c_str());
	return (hours * 60) + minutes;
}

void Airport::addDepartingFlight(Flight * departure) {
	departure->setDepartingAirport(this);
	departures.push_back(departure);
};

void Airport::addArrivingFlight(Flight * arrival) {
	arrival->setArrivingAirport(this);
	arrivals.push_back(arrival);
};

vector <Flight*> Airport::findNextFlightsTo(Airport * destination, int startingTimeMinutes) {
	vector <Flight*> flights;
	for(int i = 0, l = departures.size(); i < l; i++) {
		if(departures[i]->getArrivingAirport() == destination && departures[i]->getDepartureTimeMinutes() >= startingTimeMinutes) {
			flights.push_back(departures[i]);
		}
	}
	return flights;
};

vector <Flight*> Airport::findNextFlights(int startingTimeMinutes) {
	vector <Flight*> flights;
	for(int i = 0, l = departures.size(); i < l; i++) {
		if(departures[i]->getDepartureTimeMinutes() >= startingTimeMinutes) {
			flights.push_back(departures[i]);
		}
	}
	return flights;
};

vector <Path*> Airport::findPathsTo(Airport * destination, int startingTimeMinutes) {
  vector <Path *> paths;
  vector <Flight *> flights;
  findPathSegment(paths, flights, this, destination, startingTimeMinutes);
  return paths;
};

void Airport::findPathSegment(vector <Path * > &paths, vector <Flight * > flights, Airport * currentAirport, Airport * destination, int currentTime) {

  vector <Flight *> departures = currentAirport->findNextFlights(currentTime);
  bool lastTry = false;

  if(departures.size() == 0) {
    departures = currentAirport->findNextFlights(0);
    lastTry = true;
  }

  for(int i = 0, l = departures.size(); i < l; i++) {

    int time = currentTime;
    Airport * arrival = departures[i]->getArrivingAirport();
    vector <Flight *> connections;

    if(time < departures[i]->getDepartureTimeMinutes()) {
      time = departures[i]->getDepartureTimeMinutes();
    }

    time = time + departures[i]->getFlightDurationMinutes() + currentAirport->getConnectionTimeMinutes();

    for(int x = 0, xl = flights.size(); x < xl; x++) {
      connections.push_back(flights[x]);
    }
    connections.push_back(departures[i]);

    if(arrival == destination) {
      paths.push_back(new Path(connections));
    } else if(lastTry == false) {
      findPathSegment(paths, connections, arrival, destination, (time > 24 * 60) ? 0 : time);
    }

  }
  
}

bool Airport::operator== (Airport * airport) {
	return this->getCode() == airport->getCode();
};

