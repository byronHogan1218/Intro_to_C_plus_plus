/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 4 - Complex.h 
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Thursday, 10/19/2017 by 11:59 pm

   FUNCTION:   Header file for the Complex class
               
*********************************************************************/
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using std::ostream;
using std::istream;

class Complex {
  //overloaded insertion/extraction operators
  friend ostream & operator << (ostream &out, const Complex &num); 
  friend istream & operator >> (istream &in, Complex &num);
  
  private:
    double real;
    double imag;

  public:
    Complex(double = 0, double = 0);
 
    //get and set methods
    void setComplex(double, double);
    void getComplex(double&, double&) const;
    void setRealPart(double);
    double getRealPart() const;
    void setImaginaryPart(double);
    double getImaginaryPart() const;
 
    //overloaded operators
    Complex operator+(const Complex&) const;
    Complex operator*(const Complex&) const;
    bool operator==(const Complex&) const;
};
 
#endif
