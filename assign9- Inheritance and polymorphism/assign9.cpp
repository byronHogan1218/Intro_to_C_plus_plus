/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This maintains geometric shapes 

*********************************************************************/

#include<iostream>
#include"Cone.h"
#include"Circle.h"
#include"Shape.h"
#include"Cylinder.h"
using std::cout;
using std::endl;

int main(){
Shape *shapeAr[5];
//Fills the array with shape objects
shapeAr[0]=new Circle("green", 10);
shapeAr[1]=new Circle("orange", 5);
shapeAr[2]=new Cylinder("blue", 8,6);
shapeAr[3]=new Cylinder("red", 3, 7);
shapeAr[4]=new Cone("yellow", 4, 6);
shapeAr[5]=new Cone("purple", 9, 7);

cout << "Printing all shapes.." << endl << endl;
for (int i=0; i < 6; ++i){
	shapeAr[i]->print();
}

cout << endl << "Printing only cylinders..." << endl << endl;
for (int i=0; i < 6; ++i){
        Cylinder *cylinderPtr = dynamic_cast<Cylinder *> (shapeAr[i]);
	if (cylinderPtr !=0 )
		shapeAr[i]->print();
}

//Deletes the objects in the array
for (int i=0; i < 6; ++i){
        delete shapeAr[i];
}





return 0;
}

