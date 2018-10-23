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
////////////////////////////////////////////
//This method handles transactions
void providerDB::proccessTransactions(const char * transFile){
	ifstream fin;
	int count =0;
	int subscript;
	string holder;
	fin.open(transFile);
	while(fin >> holder){//loops through until the end of the transactions file
		if (holder == "all"){//code for if the "all" keyword was found
			sortByName();
			print();
		}
		if  (holder =="specialty"){//code for if the "specialty" keyword was found
			fin >> ws;
			getline(fin,holder);
			sortBySpecialty();
			count=0;
			for(int i=0;i<size;++i){//finds and prints out the provider with the specialty specified by the "specialty" keyword
				if (holder == providerArray[i].getSpecialty()){
					providerArray[i].printFile();
					++count;
				}
			}
			 if (count != 0){
                        	 cout<< "There were " << count << " providers with the specialty "<< holder<<endl;
                         }

		}
		if(holder == "number"){//code for if "number" keyword was found
			fin >> holder;
			//copy the string into a c style string to match the passing parameters 
			char *holderC=new char[holder.length()+1];
			strcpy(holderC,holder.c_str());
			sortByProviderNumber();
			subscript=searchForProviderNum(holderC);
			if(subscript == -1){//prints if the file was not found or the provider asscociated with the provider number specified by the "number" keyword
				cout << "The provider number "<< holder << " was not found." << endl<<endl;
			}
			else{
				providerArray[subscript].printFile();
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
//This method seraches through the provider array for a match to the target
int providerDB::searchForProviderNum(char target[]){
	int subscript=-1;
	int low = 0;
	int high = size - 1;
	int mid;
	
	while (low <= high)//begins the binary search
	{
		mid = (low + high) / 2;

		if (strcmp(target,providerArray[mid].getProviderNum())==0)
			subscript= mid;

		if (strcmp(target,providerArray[mid].getProviderNum())<0)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return subscript;
}
