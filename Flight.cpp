#include "Flight.h"
#include "Airport.h"
#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

Flight::Flight(string departureTime, string flightDuration) {
	this->departureTime = departureTime;
	this->departureTimeMinutes = convertToMinutes(departureTime);
	this->flightDuration = flightDuration;
	this->flightDurationMinutes = convertToMinutes(flightDuration);
}

Airport * Flight::getDepartingAirport() {
	return origin;
}

Airport * Flight::getArrivingAirport() {
	return destination;
}

string Flight::getDepartureTime() {
	return departureTime;
}

int Flight::getDepartureTimeMinutes() {
	return departureTimeMinutes;
}

string Flight::getFlightDuration() {
	return flightDuration;
}

int Flight::getFlightDurationMinutes() {
	return flightDurationMinutes;
}

int Flight::getArrivalTime() {
	return departureTimeMinutes + flightDurationMinutes;
}

void Flight::setDepartingAirport(Airport * airport) {
	this->origin = airport;
}

void Flight::setArrivingAirport(Airport * airport) {
	this->destination = airport;
}

string Flight::toString() {
	string str = origin->getCode() + " " + destination->getCode() + " " + departureTime + " " + flightDuration;
	return str;
}

