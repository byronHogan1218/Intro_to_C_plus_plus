/*
Programmer: Byron Hogan
Zid: z1825194
Date due: 10-19-2017
Purpose:  To declare the class methods
*/
#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using std::istream;
using std::ostream;
class Complex{
	friend ostream& operator<<(ostream&,const Complex&);
	friend istream& operator>>( istream&, Complex&);
	private:
		double real;
		double imag;

	public:
		Complex();
		Complex(double,double);
		void setComplex(double,double);
		void getComplex(double&,double&)const;
		void setReal(double);
		void setImaginary(double);
		double getReal() const;
		double getImaginary() const;
		Complex operator*(const Complex&)const;
		Complex operator+(const Complex&)const;
		bool operator==(const Complex&)const;


};
#endif

