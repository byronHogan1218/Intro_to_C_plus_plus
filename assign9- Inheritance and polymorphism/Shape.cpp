/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the definitions for the Shape class

*********************************************************************/


#include<iostream>
#include"Shape.h"
#include<string>

using std::string;
using std::cout;

///////////////////////////////////////////
//This is the cinstructor for the shape class
Shape::Shape( const string& newName){
	name=newName;
}

/////////////////////////////////////////////
//This is the destructor for the shape class
Shape::~Shape(){
}


////////////////////////////////////////////////////
//This is the print function
//Returns: Nothing
void Shape::print(){
	cout << name;
}

