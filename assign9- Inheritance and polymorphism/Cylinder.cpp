/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the definitions for the cylinder class

*********************************************************************/

#include"Cylinder.h"
#include"Circle.h"
#include"Shape.h"
#include<cmath>
#include<iostream>
#include<iomanip>
#include<string>

using std::setprecision;
using std::fixed;
using std::cout;
using std::endl;
using std::string;

///////////////////////////////////////////////////////
//This is the constructor
Cylinder::Cylinder(const string& newName, const int& newRadius, const int& newHeight) : Circle (newName, newRadius){
	height=newHeight;
}

///////////////////////////////////////////////////////
//This is the overidden function getArea
//Returns: Double:The calculated area of a cylinder
double Cylinder::getArea(){
	double rad=Circle::getRadius();
	return ((2 * M_PI * rad * height)+(2 * M_PI*(rad * rad)));
}

/////////////////////////////////////////////////////////
//This is the definition of the virtual function get Volume
//Returns: Double:The calculated volume of the cylinder
double Cylinder::getVolume(){
	double rad = Circle::getRadius();
	return (M_PI * height * (rad * rad));
}

//////////////////////////////////////////////////////
//This is the overridden version of print for cylinder
//Returns: Nothing
void Cylinder::print(){
	cout << name << " cylinder, radius " << Circle::getRadius()
		<< ", area " << fixed << setprecision(2) << getArea() <<
		", height " << height << ", volume " << getVolume() << endl;
}
