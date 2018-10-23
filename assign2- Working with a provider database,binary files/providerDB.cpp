   //*****************************************************************
   // FILE:      ProviderDB.cpp
   // AUTHOR:    Byron Hogan
   // LOGON ID:  z1825194
   // DUE DATE:  9-26-17
   //
   // PURPOSE:   Definition for the Provider class database, which represents
   //            information about a health care provider.
   //*****************************************************************


#include"provider.h"
#include<iostream>
#include"providerDB.h"
#include<cassert>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;
//defualt constructor
providerDB::providerDB(){
//intialized to 0
}
/////////////////////////////////////////////
// Constructor that builds the DB from a file
providerDB::providerDB(const char* providerDBFile){
	ifstream inFile;
	inFile.open(providerDBFile,ios::binary);
	assert(inFile);
	inFile.read((char*)this, sizeof(providerDB));
	inFile.close();
}
///////////////////////////////////////////////////////
//call the printFile function in  the provider class to print the information
void providerDB:: print()const{
	cout<<"Health Care Provider List"<< endl;
	for (int i=0;i <size;++i){//loops through the file printing everything
		providerArray[i].printFile();
	}
}

///////////////////////////////////////////////////////////////
// sort by the provider number
void providerDB:: sortByProviderNumber(){
int i, j;
   provider bucket;
   for (i = 1; i < size; i++)//begins the insertion sort
      {
      bucket = providerArray[i];

      for (j = i; (j > 0) && (strcmp(providerArray[j-1].getProviderNum(), bucket.getProviderNum())>0); j--){
         providerArray[j] = providerArray[j-1];
	}
      providerArray[j] = bucket;
      }
   
}
///////////////////////////////////////////////////////
// Sorts by the specialty
void providerDB:: sortBySpecialty(){
int i, j;
   provider bucket;

   for (i = 1; i < size; i++)//Begins the insertion sort
      {
      bucket = providerArray[i];

      for (j = i; (j > 0) && (strcmp(providerArray[j-1].getSpecialty(), bucket.getSpecialty())<0);j--){
         providerArray[j] = providerArray[j-1];
	}
      providerArray[j] = bucket;
      }
   
}
////////////////////////////////////////////////////////////
//This method sorts the data by the name
void providerDB:: sortByName(){
int i, j;
   provider bucket;

   for (i = 1; i < size; i++)//Begins the insertion sort
      {
      bucket = providerArray[i];

      for (j = i; (j > 0) && (strcmp(providerArray[j-1].getName(), bucket.getName())>0);j--){
         providerArray[j] = providerArray[j-1];
	}
      providerArray[j] = bucket;
      }
  
}

