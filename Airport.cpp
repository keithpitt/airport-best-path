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

vector <Path*> Airport::findPathTo(Airport * destination, int startingTimeMinutes) {

  vector <Path *> paths;
  vector <Flight *> departures = findNextFlights(startingTimeMinutes);

  for(int i = 0, l = departures.size(); i < l; i++) {

    vector <Flight *> connections;

    findPathSegment(connections, departures[i], destination);

    if(connections.size() > 0) {
      Path * path = new Path(startingTimeMinutes);
      for(int x = (connections.size() - 1); x > 0; x--) {
        path->addFlight(connections[x]);
      } 
      paths.push_back(path);
    }

  }

  return paths;

};

void Airport::findPathSegment(vector <Flight *> &connections, Flight * &flight, Airport * &destination) {

  if(flight->getArrivingAirport() == destination) {
    connections.push_back(flight);
  } else {
    Airport * arivalAirport = flight->getArrivingAirport();
    vector <Flight *> departures = arivalAirport->findNextFlights(flight->getDepartureTimeMinutes() + arivalAirport->getConnectionTimeMinutes());
    cout << "Debugger: Looking at flights from " << arivalAirport->getCode() << "\n";
    for(int i = 0, l = departures.size(); i < l; i++) {
      cout << "Debugger: -- " << departures[i]->getArrivingAirport()->getCode() << "\n";
      findPathSegment(connections, departures[i], destination);
    }
    if(connections.size() > 0) {
      connections.push_back(flight);
    }
  }

}

bool Airport::operator== (Airport *) {
	return true;
};


