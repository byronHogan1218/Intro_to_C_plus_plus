/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   12-5-17

   FUNCTION:   This is the header for the Cone class

*********************************************************************/



#ifndef CONE_H
#define CONE_H

#include"Shape.h"
#include"Circle.h"
#include<string>
using std::string;


class Cone : public Circle{
private:
        int height;
public:
        Cone(const string&,const int&, const int &);
        double getArea();
        virtual double getVolume();
        void print();
};

#endif




