/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 4 - Complex.cpp
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Thursday, 10/19/2017 by 11:59 pm

   FUNCTION:   Source Code for the Complex class
               
*********************************************************************/
#include "Complex.h"

using std::ostream;
using std::istream;

Complex::Complex(double inReal, double inImag) {
  real = inReal;
  imag = inImag;
}

/******************************************************************
These methods are all pretty self explanatory and 1 - 2 lines anyways,
so I'll just be using this block to talk about them all. Get and Set
methods are used to manipulate a Complex object's data members. 
Overloaded operators are so we can use C++ operators to work on 
Complex objects.
******************************************************************/
void Complex::setComplex(double newReal, double newImag) {
  real = newReal;
  imag = newImag;
}

void Complex::getComplex(double &realPtr, double &imagPtr) const{
  realPtr = real;
  imagPtr = imag;
}

void Complex::setRealPart(double setReal) {
  real = setReal;
}

double Complex::getRealPart() const {
  return real;
}

void Complex::setImaginaryPart(double setImag) {
  imag = setImag;
}

double Complex::getImaginaryPart() const {
  return imag;
}

Complex Complex::operator+(const Complex &add) const {
  Complex newNum(this->real + add.real, this->imag + add.imag);
  return newNum;
}

Complex Complex::operator*(const Complex &mult) const {
  Complex newNum(this->real * mult.real - this->imag * mult.imag,
                 this->real * mult.imag + this->imag * mult.real);
  return newNum;
}

bool Complex::operator==(const Complex &match) const {
  if ((this->real == match.real) && (this->imag == match.imag)) 
    return true;
  else
    return false;
}

ostream & operator << (ostream& out, const Complex &num) {
  out << '(' << num.real << ", " << num.imag << ")";
  return out;
}

istream & operator >> (istream& in, Complex& num) {
  char ch;
  in >> ch;
  in >> num.real;
  in >> ch;
  in >> num.imag;
  in >> ch;
  return in;
}   
