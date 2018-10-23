
/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   11-29-17

   FUNCTION:   This is the header and has the definitions for building
               lists
*********************************************************************/
#ifndef SORTS_H
#define	SORTS_H
#include<iomanip>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<fstream>
#include <assert.h>
using std::ostream;
using std::ifstream;
using std::setw;
using std::cout;
using std::vector;
using std::endl;

///////////////////////////////////////////////////
//Forward declarations of the  functions
template<class T>
void buildList (vector<T>& , const char*);
template<class T>
void printList(const vector<T>&, int,int);
template<class T>
bool lessThan(const T&,const T&);
template<class T>
bool greaterThan(const T&,const T&);


/////////////////////////////////////////////////////
//Definition of the lessThan function
template<class T>
bool lessThan(const T& item1 ,const T& item2){
 return item1 < item2;
}
/////////////////////////////////////////////////////
//Definition of the greaterThan function
template<class T>
bool greaterThan(const T& item1 ,const T& item2 ){
 return item1>item2;
}

/////////////////////////////////////////////////
//The following is the code to build a list from a file
template <class T>
void buildList (vector<T>& set, const char* file){
T item;
ifstream fin;

fin.open(file);
assert(fin);

while (fin >> item){
	set.push_back(item);//adds the item read from the file into the vector
}
fin.close();
}

////////////////////////////////////////////////////////
//The following is the code to print the list
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine){
int nlCounter=0;//newline counter
for (int i=0; i< (int) set.size(); i++){
	cout << setw(itemWidth)<<set[i] << ' ';
	++nlCounter;
	if (nlCounter > numPerLine){//will print a new line when the number per line says to
		nlCounter=0;
		cout << endl;
	}
}
cout << endl;
}

#endif

