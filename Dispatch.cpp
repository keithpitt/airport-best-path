#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dispatch.h"
#include "Utilities.h"

Dispatch::Dispatch() {}

int Dispatch::import(char fileName[]) {

	// cout << "Debugger: Importing file `" << fileName << "`\n";

	string line;
	vector <string> lines;
	ifstream dataFile(fileName);

	if (dataFile.is_open())
	{
		while (!dataFile.eof())
		{
			getline(dataFile,line);
			lines.push_back(line);
		}
		dataFile.close();
	} else {
		cout << "Error: Could not load file '" << fileName << "'\n";
		return 1;
	}

	int numberOfAirports = atoi(lines[0].c_str());
	int numberOfFlights = atoi(lines[1 + numberOfAirports].c_str());
	int tmp = 1;
	
	cout << "Debugger: Number of airports: " << numberOfAirports << "\n";
	cout << "Debugger: Number of flights: " << numberOfFlights << "\n";

	Airport * airport;
	string code, description, connectionTime;	
	int firstSpace, secondSpace;
	for(int i = 1, l = numberOfAirports; i <= l; i++) {
		firstSpace = lines[i].find(" ");
		secondSpace = lines[i].find(" ", 4, 1);
		code = lines[i].substr(0, 3);
		connectionTime = lines[i].substr(firstSpace + 1, secondSpace - code.size() - 1);
		description = lines[i].substr(secondSpace + 1);
		
		airport = new Airport(code, description,  connectionTime);
		airports.push_back(airport);

		// cout << "Debugger: Imported airport #" << tmp << " '" << airport->getCode() << "', '" << airport->getDescription() << "', '" << airport->getConnectionTime() << "', ('" << lines[i] << "')\n";
		// tmp = tmp + 1;
	}
	
	Flight * flight;
	tmp = 1;
	string origin, destination, departingTime, flightDuration;
	for(int x = (numberOfAirports + 2), xl = (x + numberOfFlights - 1); x <= xl; x++) {
		firstSpace = 8;
		secondSpace = lines[x].find(" ", firstSpace, 1) + 1;
		
		origin = lines[x].substr(0, 3);
		destination = lines[x].substr(4, 3);
		departingTime = lines[x].substr(firstSpace, secondSpace - firstSpace - 1);
		flightDuration = lines[x].substr(secondSpace);
		
		flight = new Flight(departingTime, flightDuration);
		(findAirportByCode(origin))->addDepartingFlight(flight);
		(findAirportByCode(destination))->addArrivingFlight(flight);
		
		// cout << "Debugger: Importing flight #" << tmp << " '" << origin << "', '" << destination << "', '" << departingTime << "', '" << flightDuration << "', ('" << lines[x] << "')\n";
		// tmp = tmp + 1;
	}

	return 0;

}

Airport * Dispatch::findAirportByCode(string airportCode) {
	// cout << "Debugger: Looking up airport `" << airportCode << "`\n";
	for(int i = 0, l = airports.size(); i < l; i++) {
		if(airports[i]->getCode() == airportCode) {
			return airports[i];
		}
	}
	return NULL;
}

Path * Dispatch::route(Airport * fromAirport, Airport * toAirport, string departureTime) {
	vector <Path *> paths = fromAirport->findPathsTo(toAirport, convertToMinutes(departureTime));
	Path * path = NULL;
	for(int x = 0, xl = paths.size(); x < xl; x++) {
		if(path == NULL || (path && path->getTotalTime() > paths[x]->getTotalTime())) {
			path = paths[x];
		}
	}
	return path;
}



