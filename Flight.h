#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using namespace std;

class Airport;

class Flight {

	private:

		Airport * origin;
		Airport * destination;

		string departureTime;
		int departureTimeMinutes;

		string flightDuration;
		int flightDurationMinutes;

	public:

		Flight(string departureTime, string flightDuration);

		Airport * getDepartingAirport();
		Airport * getArrivingAirport();
		string getDepartureTime();
		int getDepartureTimeMinutes();
		string getFlightDuration();
		int getFlightDurationMinutes();
		int getArrivalTime();

		void setDepartingAirport(Airport * airport);
		void setArrivingAirport(Airport * airport);

		string toString();

};

#endif
