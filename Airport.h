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

    void findPathSegment(vector <Path * > &paths, vector <Flight * > flights, Airport * currentAirport, Airport * destination, int currentTime);

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
		vector <Path*> findPathsTo(Airport * destination, int startingTimeMinutes);

		bool operator == (Airport * airport);

};

#endif
