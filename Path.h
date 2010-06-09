#ifndef PATH_H
#define PATH_H

#include "Flight.h"
#include <string>
#include <vector>

class Path {

	private:
		
		string startingTime;
		vector <Flight *> flights;

	public:

		Path(string startTime);

		string getStartingTime();
		string getArrivalTime();
		string getPathDuration();
		
		int getStartingTimeMinutes();
		int getTotalTime();

		void addFlight(Flight *);
		vector <Flight *> getFlights();

};

#endif
