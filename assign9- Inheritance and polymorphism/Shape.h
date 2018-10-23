/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the header for Shape

*********************************************************************/


#ifndef SHAPE_H
#define SHAPE_H

#include<string>
using std::string;

//This is an abstract class
class Shape{
protected:
	string name;
public:
	Shape( const string& );
	virtual ~Shape();
	virtual void print();
	virtual double getArea()=0; //Pure virtual function
};

#endif
