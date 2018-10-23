/***********************************************************************
   PROGRAM:    CSCI 241 Assignment 8 - sorts.h
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Wednesday, 11/29/2017 by 11:59 pm

   FUNCTION:   header file for sorting, with functions for comparison
               and for processing and printing using vectors

************************************************************************/
#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

//********************************************************************
// vector function prototypes
//********************************************************************
template <class T>
void buildList(vector<T>& set, const char* fileName);

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine);

template <class T>
bool lessThan(const T& item1, const T& item2);

template <class T>
bool greaterThan(const T& item1, const T& item2);

//********************************************************************
// vector function definition
//********************************************************************
// buildList - takes in an input file and stores info into vector
template <class T>
void buildList(vector<T>& set, const char* fileName) {
  T item;
  ifstream inFile;

  inFile.open(fileName);

  if (!inFile.is_open()) // checks if file was opened correctly
    cout << "Error: file did not open correctly" << endl;
  else {
    inFile >> item;
  }

  while (inFile.good()) { // builds vector from input file data
    set.push_back(item);
    inFile >> item;
  }

  inFile.close();
}

// printList - takes a vector and prints it out with specified formatting
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine) {
  int lineCount = 0;

  for (int i = 0; i < (int) set.size(); i++) {
    if (lineCount == numPerLine) { //conditional for when to put new lines
      cout << endl;
      lineCount = 0;
    }

    cout << std::setw(itemWidth) << set[i]; //print out constrained width data
   
    lineCount++; 
  }
}

// lessThan - comparison function for less than
template <class T>
bool lessThan(const T& item1, const T& item2) {
  if (item1 < item2)
    return true;
  else
    return false;
}

// greaterThan comparison function for more than
template <class T>
bool greaterThan(const T& item1, const T& item2) {
  if (item1 > item2)
    return true;
  else
    return false;
}

#endif
