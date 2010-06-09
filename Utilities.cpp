#include "Utilities.h"
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>

int convertToMinutes(string time) {
	int position = time.find_first_of(":");
	int hours = atoi(time.substr(0, position).c_str());
	int minutes = atoi(time.substr(position + 1).c_str());
	return (hours * 60) + minutes;
}

string formatMinutes(int time) {
	char buffer[5];
	int hours = time / 60;
	int minutes = time - (hours * 60);
	sprintf(buffer, "%02d:%02d", hours, minutes);
	return buffer;
}

