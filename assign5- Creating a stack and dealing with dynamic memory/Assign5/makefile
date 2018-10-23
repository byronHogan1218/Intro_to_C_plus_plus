#
#   PROGRAM:    CSCI 241 Assignment 5 - makefile
#   PROGRAMMER: Kevin Kang
#   LOGON ID:   z1837081
#   SECTION:    4
#   TA: Abdul   Subhan Moin Syed
#   DUE DATE:   Tuesday, 10/31/2017 by 11:59 pm 
#
#   FUNCTION:   makefile for assignment 5
#

assign: assign5.o Stack.o
	g++ -Wall -std=c++11 -o assign5 assign5.o Stack.o

assign5.o: assign5.cpp Stack.h
	g++ -Wall -std=c++11 -c assign5.cpp

Stack.o: Stack.cpp Stack.h
	g++ -Wall -std=c++11 -c Stack.cpp

clean:
	rm *.o assign5


               
