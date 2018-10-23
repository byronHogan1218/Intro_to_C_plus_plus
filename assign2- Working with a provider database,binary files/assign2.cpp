//Program:    Assignment 2
//Class:      CSCI 241
//Teacher:    Amy Byrnes
//Programmer: Byron Hogan
//ZID:        Z1825194


#include <iostream>
#include<fstream>

#include"provider.h"
#include"providerDB.h"

int main() {
	providerDB providerDBObject("providerdb");
        providerDBObject.print();
	providerDBObject.sortByProviderNumber();
	providerDBObject.print();
	providerDBObject.sortBySpecialty();
	providerDBObject.print();
	providerDBObject.sortByName();
	providerDBObject.print();
	return 0;
}
