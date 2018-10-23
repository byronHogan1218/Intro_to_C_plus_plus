#
#   PROGRAM:    CSCI 241 Assignment 4 - makefile
#   PROGRAMMER: Kevin Kang
#   LOGON ID:   z1837081
#   SECTION:    4
#   TA: Abdul   Subhan Moin Syed
#   DUE DATE:   Thursday, 10/19/2017 by 11:59 pm
#
#   FUNCTION:   makefile for assignment 4
               
#variables
CC = g++
CCFLAGS = -Wall -std=c++11 

assign4: assign4.o Complex.o
	$(CC) $(CCFLAGS) -o assign4 assign4.o Complex.o

assign4.o: assign4.cpp Complex.h
	$(CC) $(CCFLAGS) -c assign4.cpp

Complex.o: Complex.cpp Complex.h
	$(CC) $(CCFLAGS) -c Complex.cpp

clean:
	- rm *.o assign4
