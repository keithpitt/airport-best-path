CC=					g++

LDFLAGS= 

all:				assign3

clean:
					rm -f *.o
					rm assign3

test:
					
					./assign3 data.txt BP PER KNS 7:00

assign3:			main.o Airport.o Flight.o Dispatch.o Path.o Utilities.o
					$(CC) $(LDFLAGS) -o assign3 \
										main.o \
										Airport.o \
										Flight.o \
										Dispatch.o \
										Path.o \
										Utilities.o

main.o:		main.cpp
		$(CC) -c main.cpp

Airport.o:	Airport.cpp
		$(CC) -c Airport.cpp

Flight.o:	Flight.cpp
		$(CC) -c Flight.cpp

Dispatch.o:	Dispatch.cpp
		$(CC) -c Dispatch.cpp

Path.o:		Path.cpp
		$(CC) -c Path.cpp

Utilities.o:	Utilities.cpp
		$(CC) -c Utilities.cpp

