/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the definitions for the cirlce class

*********************************************************************/

#include"Shape.h"
#include"Circle.h"
#include<iomanip>
#include<cmath>
#include<iostream>
#include<string>

using std::setprecision;
using std::fixed;
using std::string;
using std::cout;
using std::endl;

////////////////////////////////////////////////
//This is the constructor
Circle::Circle(const string& newName,const int& newRadius) : Shape(newName){
	radius=newRadius;
}
/////////////////////////////////////////////
//This is the overidden funtion getArea
//Returns: Double:the area of the circle
double Circle::getArea(){
	return (M_PI* (radius*radius));
}

////////////////////////////////////////////
//This is the  overidden function print
//Returns: Nothing
void Circle::print(){
	Shape::print();
	cout << " circle, " << "radius " << radius << ", area " << fixed << setprecision(2) <<  getArea() << endl;
}
