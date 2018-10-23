/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the header for the circle class

*********************************************************************/


#ifndef CIRCLE_H
#define CIRCLE_H
#include"Shape.h"

using std::string;

class Circle : public Shape{
	private:
		int radius;
	public:
		int getRadius() const { return radius; }
		Circle(const string&,const int&);
		double getArea();
		void print();
};




#endif




