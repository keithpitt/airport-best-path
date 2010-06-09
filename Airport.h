#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <vector>

using namespace std;

class Flight;

class Airport {

	private:

		string code;
		string description;
		string connectionTime;

		vector <Flight *> departures;
		vector <Flight *> arrivals;

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

		vector <Flight*> findNextFlightTo(Airport * destination, int startingTimeMinutes);

		bool operator == (Airport *);

};

#endif
