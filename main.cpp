#include <iostream>
#include <stdlib.h>
#include <string>
#include "Airport.h"
#include "Flight.h"
#include "Dispatch.h"

int main (int argc, char* argv[]) {

	if(argc == 1) {
		cout << "Error: No airport data file specified.\n";
		return 1;
	}

	if(argc == 2) {
		cout << "Error: No command specified.\n";
		return 1;
	}

	// cout << "Debugger: Runnnig dispatch with " << argc << " arguments\n";

	Dispatch * dispatch = new Dispatch();
	int result = dispatch->import(argv[1]);	

	if(result != 0) {
		return result;
	}

	string commandToRun = argv[2];

	// cout << "Debugger: Running command `" << commandToRun << "`\n";

	if(commandToRun == "NFF") {

		if(argc == 3) {
			cout << "Error: No airport code specified.\n";
			return 1;
		}

		Airport * airport = dispatch->findAirportByCode(argv[3]);

		if(airport == NULL) {
			cout << "Error: Could not locate airport.\n";
			return 1;
		} 

		cout << "*** Number of Flights From " << airport->getCode() << " ***\n";
		cout << airport->getDeparturesCount() << "\n";
		return 0;

	}

	if(commandToRun == "SC") {

		if(argc == 3) {
			cout << "Error: No airport code specified.\n";
			return 1;
		}

		Airport * airport = dispatch->findAirportByCode(argv[3]);

		if(airport == NULL) {
			cout << "Error: Could not locate airport.\n";
			return 1;
		} 

		cout << "*** Starting in " << airport->getCode() << " ***\n";

		vector <Flight *> departures = airport->getDepartures();
		for(int i = 0, l = departures.size(); i < l; i++) {
			cout << departures[i]->toString() << "\n";
		}
		
		return 0;

	}

	if(commandToRun == "DEST") {

		if(argc == 3) {
			cout << "Error: No airport code specified.\n";
			return 1;
		}

		Airport * airport = dispatch->findAirportByCode(argv[3]);

		if(airport == NULL) {
			cout << "Error: Could not locate airport.\n";
			return 1;
		} 

		cout << "*** Destination to " << airport->getCode() << " ***\n";

		vector <Flight *> arrivals = airport->getArrivals();
		for(int i = 0, l = arrivals.size(); i < l; i++) {
			cout << arrivals[i]->toString() << "\n";
		}
		
		return 0;

	}

	if(commandToRun == "BP") {

		if(argc != 6) {
			cout << "Error: Not enough arguments.\n";
			return 1;
		}

		Airport * origin = dispatch->findAirportByCode(argv[3]);
		if(origin == NULL) {
			cout << "Error: Could not locate origin airport '" << argv[3] << "'.\n";
			return 1;
		} 

		Airport * destination = dispatch->findAirportByCode(argv[4]);
		if(destination == NULL) {
			cout << "Error: Could not locate destination airport '" << argv[4] << "'.\n";
			return 1;
		}
		
		Path * path = dispatch->route(origin, destination, argv[5]);
		
		if(path != NULL) {

			cout << "***Best Path Found***\n";

			cout << "Starting airport: " << origin->getCode() << "\n";
			cout << "Starting time: " << path->getStartingTime() << "\n";
			cout << "Arrival time: " << path->getArrivalTime() << "\n";
			cout << "Path duration: " << path->getPathDuration() << "\n";
			cout << "Path details:\n";

			vector <Flight *> flights = path->getFlights();
			for(int i = 0, l = flights.size(); i < l; i++) {
				cout << flights[i]->getDepartingAirport()->getCode() << " " << flights[i]->getArrivingAirport()->getCode() << " " << flights[i]->getDepartureTime() << " " << flights[i]->getFlightDuration() << "\n";
			}
		
		} else {
			cout << "Error: Could not locate a path from '" << origin->getCode() << "' to '" << destination->getCode() << "' at '" << argv[5] << "'\n";
			return 1;
		}
		
		return 0;

	}

	cout << "Error: No command was run.\n";

}


