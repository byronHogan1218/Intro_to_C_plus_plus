//Program:    Assignment 3
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
        providerDBObject.proccessTransactions("transactions.txt");
	return 0;
}
