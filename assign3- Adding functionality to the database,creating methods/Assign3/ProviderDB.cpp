//*****************************************************************
// FILE:      ProviderDB.cpp
// AUTHOR:    Kevin Kang
// LOGON ID:  z1837081
// DUE DATE:  Tuesday, 10/10/2017 by 11:59 pm
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
using std::ws;

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

bool specialtyMore(const Provider& p1, const Provider& p2) {
  if (strcmp(p2.getSpecialty(), p1.getSpecialty()) < 0)
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
}

/*******************************************************  
sortBySpecialty
 
Use: sorts the provider database by their specialty
 
Params: none
 
Returns: none
*******************************************************/
void ProviderDB::sortBySpecialty() {
  sort(specialtyMore);
}

/*******************************************************
sortByName

Use: sorts the provider databse by their names

Params: none

Returns: none
*******************************************************/
void ProviderDB::sortByName() {
  sort(nameLess);
}

/*********************************************************
processTransactions, processSpecialty, processNumber

Use: takes in a pointer to a file name for transactions
processes information based on what the file specifies,
like searching for providers with certain specialties
and looking for providers with a given number

Params: Trans -- tranFileName: name of transaction file
        Spec  -- specialty: specialty to search for
        number-- number of Provider to look for

Reruns: nothing 
*********************************************************/
void ProviderDB::processTransactions(char* tranFileName) {
  ifstream inFile;
  inFile.open( tranFileName );
  char buffer[1024];

  inFile >> buffer; 

  //while loop that reads through file for transactions
  while (inFile.good()) {
    if (strcmp(buffer, "all") == 0) {
      sortByName();
      print();
    }

    else if (strcmp(buffer, "specialty") == 0) {
      inFile >> ws; //remove white space
      inFile.getline(buffer, 1024);
 
      processSpecialty(buffer);
    }
    
    else if (strcmp(buffer, "number") == 0) {
      inFile >> buffer;
      
      processNumber(buffer);
    }
    inFile >> buffer;
  }    
}

void ProviderDB::processSpecialty(char* specialty) {
  int count = 0;

  sortBySpecialty();

  //loops through providers looking and printing those with given spec
  for (int i = 0; i < numProviders; i++) {
    if (strcmp(specialty, providers[i].getSpecialty()) == 0) {
      providers[i].print();
      count++;
    }
  }
  
  cout << "Number of Providers with Specialty " << specialty
       << ": " << count << endl;
}

void ProviderDB::processNumber(char* number) {
  sortByProviderNumber();

  int searchResult = searchForProviderNumber(number);

  if (searchResult == -1)
    cout << "Error, provider number " << number << " was not found" << endl;
  else {
    providers[searchResult].print(); //prints provider with pNumber given
    cout << "Provider found with number: " << number << " at position "
         << searchResult << endl;
  }
}

/*********************************************************
searchForProviderNumber

Use: a variation of the binary search for a sorted list
looks for a provider number in an array of Providers

Params: pNum - the number we are searching for

Returns: an integer for the position in the array of the
provider with the provider number given.
*********************************************************/
int ProviderDB::searchForProviderNumber(char* pNum){
  int low = 0;
  int high = numProviders - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) /2;

    if (strcmp(pNum, providers[mid].getProviderNumber()) == 0)
      return mid;
    
    if (strcmp(pNum, providers[mid].getProviderNumber()) < 0)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return -1;
}
