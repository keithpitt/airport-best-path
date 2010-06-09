#ifndef DISPATCH_H
#define DISPATCH_H

#include "Flight.h"
#include "Airport.h"
#include "Path.h"
#include <string>
#include <vector>

using namespace std;

class Dispatch {

	private:

		vector<Flight *> flights;
		vector<Airport *> airports;

	public:
		
		Dispatch();
		int import(char fileName[]);
		Airport * findAirportByCode(string code);
		Path * route(Airport * fromAirport, Airport * toAirport, string departureTime);
		
};

#endif
