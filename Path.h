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
		Path(int startTimeMinutes);
    Path(Path * other);

		string getDepartureTime();
		string getArrivalTime();
		string getPathDuration();
		string getStartingTime();

		int getStartingTimeMinutes();
		int getTotalTime();

		void addFlight(Flight *);
		void clearFlights();
		void removeLastFlight();

		vector <Flight *> getFlights();

};

#endif
