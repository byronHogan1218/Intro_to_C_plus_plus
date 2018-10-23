   //*****************************************************************
   // FILE:      Provider.cpp
   // AUTHOR:    Byron Hogan
   // LOGON ID:  z1825194
   // DUE DATE:  9-26-17
   //
   // PURPOSE:   Definitions for the Provider class, which represents
   //            information about a health care provider.
  //******************************************************************** 

#include"provider.h"
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
//This is the default constructor,all values are intialized to null when created
provider::provider(){
}

////////////////////////////////////////////////
//This will print a provider object's information
void provider::printFile() const{
cout << "#" << providerNum<< endl;
cout << name<< endl;
cout << specialty << endl;
cout << addressP1<< endl;
cout << addressP2<< endl;
cout << city << ", "<< state<< zip<< endl;
cout << phoneNum << endl << endl;

}
///////////////////////////////////////////////////////////////
// Returns the provider number
const char* provider::getProviderNum(){
	return providerNum;
}
//////////////////////////////////////////////////////////////
//Returns the specialty
const char* provider:: getSpecialty(){
	return specialty;
}
//////////////////////////////////////////////////////////////////
//Returns the Name
const char* provider:: getName(){
	return name;
}

