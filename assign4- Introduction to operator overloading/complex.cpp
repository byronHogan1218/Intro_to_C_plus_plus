/*
Programmer: Byron Hogan
Zid: z1825194
Date due: 10-19-2017
Purpose:  To define the class methods
*/
#include"complex.h"
#include<iostream>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
/////////////////
//defualt constructor 
Complex::Complex(){
	this->real=0;
	this->imag=0;
}
/////////////////
////Constructor to set the complex number
Complex::Complex(double real,double imag){
	this->real=real;
	this->imag=imag;
}
///////////////////
////Method to set the complex number
void Complex::setComplex(double real,double imag){
this->real=real;
this->imag=imag;
}
////////////////////
///Method to get the value of the complex number
void Complex::getComplex(double& real,double&imag) const{
real=this->real;
imag=this->imag;
}
//////////////
//Mehtod to set the real portion of the complex number
void Complex::setReal(double real){
this->real=real;
}
////////////////////////////
//Method to set the imaginary portion of the number
void Complex::setImaginary(double imag){
this->imag=imag;
}
//////////////////////////
//Method to return the value in the real portion of the complex number
double Complex::getReal() const{
return this->real;
}
/////////////////////////
//Mehtod to get the imaginary portion of the complex number
double Complex::getImaginary() const{
return this->imag;
}

//////////////////
//Method to overload  the * operator
Complex Complex::operator*(const Complex& rightObj)const{
Complex result;
result.real=(this->real*rightObj.real)-(this->imag*rightObj.imag);
result.imag=(this->real*rightObj.imag)+(this->imag*rightObj.real);
return result;
}

///////////////////////////////
//Mehtod to overload the + operator
Complex Complex::operator+(const Complex& rightObj)const {
Complex result;
result.real=this->real+rightObj.real;
result.imag=this->imag+rightObj.imag;
return result;
}

//////////////////////////////
//Method to overload the == operator
bool Complex::operator==(const Complex& rightObj)const{
return (real == rightObj.real && imag == rightObj.imag);
}
/////////////////////////////
//Friend function to over loadd the >> operator
istream& operator>>(istream& leftObj,Complex &rightObj){
char junk;//variable to read in the useless part of the data being entered
cin>>junk;
leftObj>>rightObj.real;
cin>>junk;
leftObj>>rightObj.imag;
cin>>junk;
return leftObj;
}
/////////////////////////////////
//Friend function to overload the << operator
ostream& operator<<(ostream& leftObj,const Complex &rightObj){
leftObj<<"("<<rightObj.real<<","<<rightObj.imag<<")";//outputs in the format "(a,b)"
return leftObj;
}
