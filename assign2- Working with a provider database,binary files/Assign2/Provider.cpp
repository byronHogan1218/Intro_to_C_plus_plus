//*****************************************************************
// FILE:      Provider.cpp
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Wednesday, 9/27/2017 by 11:59 pm
// 
// PURPOSE:   Source code file for Provider class and contains 
//            class and method implementations.
//*****************************************************************

#include <iostream>
#include <cstring>
#include "Provider.h"

using std::cout;
using std::endl;

/*********************************************************
Provider

Use: this is the constructor for class Provider but the 
information was all initialized at declaration so this is
very small. Needed for when compiler calls this method

Params: none

Returns: nothing
*********************************************************/
Provider::Provider() {}

/*********************************************************
set_values

Use: takes in 9 strings and sets all the data values of a
Provider to those cstrings.

Params: 9 char arrays representing different information
for a Provider: name, address, etc.

Returns: nothing
*********************************************************/
void Provider::set_values(char *newNum, char *newSpec, 
           char *newName, char *newAddress1,
           char *newAddress2, char *newCity, 
           char *newState, char *newZip, 
           char *newPhoneNum) {
  
  strcpy(pNumber, newNum);
  strcpy(specialty, newSpec);
  strcpy(name, newName);
  strcpy(address1, newAddress1);
  strcpy(address2, newAddress2);
  strcpy(city, newCity);
  strcpy(state, newState);
  strcpy(zip, newZip);
  strcpy(phoneNum, newPhoneNum);
}

/*********************************************************
print

Use: Outputs the data for a Provider in a formatted template
using cout

Params: none

Retruns: nothing 
*********************************************************/
void Provider::print() const {
  cout << "#" << pNumber << endl << name << endl << specialty <<
  endl << address1 << endl << address2 << endl << city << ", " << 
  state << ' ' << zip << endl << phoneNum << endl << endl;
}

/**********************************************************
getProviderNumber

Use: returns the provider number data member

Params: none

Returns: the provider nubmer as a char pointer
***********************************************************/
const char* Provider::getProviderNumber() const{
  return pNumber;
}

/***********************************************************
getSpecialty

Use: returns the specialty data member

Params: none

Returns: the specialty as a char pointer
************************************************************/
const char* Provider::getSpecialty() const {
  return specialty;
}

/**********************************************************
getName

Use: returns the provider name data member

Params: none

Returns: the provider name as a char pointer
***********************************************************/
const char* Provider::getName() const {
  return name;
}
