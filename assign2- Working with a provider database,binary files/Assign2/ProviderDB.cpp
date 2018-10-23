//*****************************************************************
// FILE:      ProviderDB.cpp
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Wednesday, 9/27/2017 by 11:59 pm
// 
// PURPOSE:   Source code file for Provider class and contains 
//            class and method implementations.
//*****************************************************************
#include <iostream>
#include <fstream>
#include <cstring>
#include "ProviderDB.h"

using std::cout;
using std::endl;
using std::ifstream;

/*********************************************************
ProviderDB

Use: this is the constructor for class ProviderDB but the 
information was all initialized at declaration so this is
very small.

Params: none

Returns: nothing
*********************************************************/
ProviderDB::ProviderDB() {
  numProviders = 0;
}

/*********************************************************
ProviderDB

Use: alternate constructor that takes in a char array for
an existing database file

Params: a char array for an existing database file

Returns: nothing
*********************************************************/
ProviderDB::ProviderDB(char* databaseFileName) {
  ifstream inFile;
  inFile.open( databaseFileName );

  if (!inFile.good())
    cout << "Error: file did not open correctly" << endl << endl;
  else
    inFile.read((char*) this, sizeof(ProviderDB));

  inFile.close();
}

/*********************************************************
print

Use: Outputs the providers in providerDB in a formatted 
template using cout

Params: none

Retruns: nothing 
*********************************************************/
void ProviderDB::print() const {
  cout << "Health Care Provider Listing" << endl << endl;
  for (int i = 0; i < numProviders; i++) { 
    providers[i].print();
  }
}

/********************************************************
pNumLess, specialtyLess, nameLess

Use: simple comparison functions for sorting methods

Params: 2 const Provider Objects

Returns: true or false if one value is larger or smaller
provider number, specialty, or name respectively
********************************************************/

bool pNumLess(const Provider& p1, const Provider& p2) {
  if (strcmp(p1.getProviderNumber(), p2.getProviderNumber()) < 0)
    return true;
  else
    return false;
}

bool specialtyLess(const Provider& p1, const Provider& p2) {
  if (strcmp(p1.getSpecialty(), p2.getSpecialty()) < 0)
    return true;
  else
    return false;
}

bool nameLess(const Provider& p1, const Provider& p2) {
  if (strcmp(p1.getName(), p2.getName()) < 0)
    return true;
  else
    return false;
}

/********************************************************
sort

Use: sorts the provider database depending on the function
passed in

Params: a function pointer with parameters of 2 Providers,
Returns: none
********************************************************/

void ProviderDB::sort(bool (*compare)(const Provider&, const Provider&)) {
  int i, j, min;
  Provider temp;

  for (i = 0; i < (numProviders -1); i++) {
    min = i;

    for (j = i+1; j < numProviders; j++) {
      if (compare(providers[j], providers[min]))
        min = j;
    }
   
    temp = providers[min];
    providers[min] = providers[i];
    providers[i] = temp;
  }
}

/********************************************************
sortByProviderNumber

Use: sorts the provider database by their provider number

Params: none

Returns: none
********************************************************/
void ProviderDB::sortByProviderNumber() {
  sort(pNumLess);
  /* //old sort algorithm
  int i, j;
  Provider tempProvider;

  for (i = 1; i < numProviders; i++) {
    tempProvider = providers[i];
  
    for (j = i; (j > 0) && (strcmp(providers[j-1].getProviderNumber(),
        tempProvider.getProviderNumber()) > 0); j--) {
      providers[j] = providers[j-1];
    }
    
    providers[j] = tempProvider;
  } */
}

/*******************************************************  
sortBySpecialty
 
Use: sorts the provider database by their specialty
 
Params: none
 
Returns: none
*******************************************************/
void ProviderDB::sortBySpecialty() {
  sort(specialtyLess);
  /* //old sort algorithm
  int i, j;
  Provider tempProvider;

  for (i = 1; i < numProviders; i++) {
    tempProvider = providers[i];
  
    for (j = i; (j > 0) && (strcmp(providers[j-1].getSpecialty(),
        tempProvider.getSpecialty()) > 0); j--) {
      providers[j] = providers[j-1];
    }
    
    providers[j] = tempProvider;
  }*/
}

/*******************************************************
sortByName

Use: sorts the provider databse by their names

Params: none

Returns: none
*******************************************************/
void ProviderDB::sortByName() {
  sort(nameLess);
  /* //old sort algorithm
  int i, j;
  Provider tempProvider;

  for (i = 1; i < numProviders; i++) {
    tempProvider = providers[i];
  
    for (j = i; (j > 0) && (strcmp(providers[j-1].getName(),
        tempProvider.getName()) > 0); j--) {
      providers[j] = providers[j-1];
    }
    
    providers[j] = tempProvider;
  }*/
}

