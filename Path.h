#ifndef PATH_H
#define PATH_H

#include "Flight.h"
#include <string>
#include <vector>

class Path {

	private:
		
		vector <Flight *> flights;

	public:

    Path(vector <Flight *> connections);

		string getDepartureTime();
		string getArrivalTime();
		string getPathDuration();

		int getTotalTime();

		vector <Flight *> getFlights();

};

#endif
