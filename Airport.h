#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>
#include "Path.h"

using namespace std;

class Flight;

class Airport {

	private:

		string code;
		string description;
		string connectionTime;

		vector <Flight *> departures;
		vector <Flight *> arrivals;

    void findPathSegment(vector <Flight *> &connections, Flight * &flight, Airport * &destination);

	public:

		Airport(string code, string description, string connectionTime);
		
		int getDeparturesCount();
		int getArrivalsCount();
		string getCode();
		string getDescription();
		string getConnectionTime();
		int getConnectionTimeMinutes();
		vector <Flight*> getDepartures();
		vector <Flight*> getArrivals();

		void addDepartingFlight(Flight * departure);
		void addArrivingFlight(Flight * arrival);

		vector <Flight*> findNextFlightsTo(Airport * destination, int startingTimeMinutes);
		vector <Flight*> findNextFlights(int startingTimeMinutes);
		vector <Path*> findPathTo(Airport * destination, int startingTimeMinutes);

		bool operator == (Airport *);

};

#endif
