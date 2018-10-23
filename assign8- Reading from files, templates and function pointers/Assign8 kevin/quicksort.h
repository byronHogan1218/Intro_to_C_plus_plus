/***********************************************************************
   PROGRAM:    CSCI 241 Assignment 8 - quicksort.h
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Wednesday, 11/29/2017 by 11:59 pm

   FUNCTION:   header file for quicksorting, with functions for implementing
               a recursive quicksort

************************************************************************/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

//********************************************************************
// vector function prototypes
//********************************************************************

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));


//********************************************************************
// quicksort function definition
//********************************************************************

// quickSort - initial call
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&)) {
  quickSort(set, 0, set.size() - 1, compare);
}

// quickSort - recursive function that calls itself until fully sorted
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) {
  int pivotPoint;

  if (start < end) {
    pivotPoint = partition(set, start, end, compare);     // Get the pivot point
    quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
    quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
  }  
}

// partition - main function that does most of the actual sorting
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) {
  int pivotIndex, mid;
  T pivotValue, temp;
   
  mid = (start + end) / 2;

  temp = set[mid]; //swapping mid and temp values
  set[mid] = set[start];
  set[start] = temp;
  
  pivotIndex = start;
  pivotValue = set[start];
 
  for (int scan = start + 1; scan <= end; scan++) {
    if (compare(set[scan], pivotValue)) {
      pivotIndex++;
      temp = set[pivotIndex]; //swapping pivotIndex and scan values
      set[pivotIndex] = set[scan];
      set[scan] = temp;
    }
  }

  temp = set[start]; //swapping start and pivotIndex values
  set[start] = set[pivotIndex];
  set[pivotIndex] = temp;

  return pivotIndex;
}

#endif
