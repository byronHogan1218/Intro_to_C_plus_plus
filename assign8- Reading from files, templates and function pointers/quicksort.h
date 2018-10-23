/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   11-29-17

   FUNCTION:   This is the header and has the definitions for sorting
               lists
*********************************************************************/
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iomanip>
#include<stdexcept>
#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::endl;

//////////////////////////////////////////////////////////////////
//Forward declarations
template<class T>
void quickSort(vector<T>&, bool (*compare)(const T&, const T&));
template<class T>
int partition(vector<T>&, int ,int,bool (*compare)(const T&,const T&));
template<class T>
void quickSort(vector<T>&, int,int,bool (*compare)(const T&,const T&));




///////////////////////////////////////////////////
//Definition of the quickSort function
template<class T>
void quickSort(vector<T>& set , bool (*compare)(const T&, const T&)){
        quickSort(set,0,set.size()-1, compare);
}

///////////////////////////////////////////////////
//Definition of the quickSort function,where the actually sorting happenes
template<class T>
void quickSort(vector<T>& set ,int start,int end, bool (*compare)(const T&, const T&)){
int pivotPoint;
if (start <end){//Starts the recursive sort
        pivotPoint= partition(set,start,end,compare);
        quickSort(set, start, pivotPoint -1,compare);
        quickSort(set, pivotPoint +1,end,compare);
}
}
////////////////////////////////////////////////////////////////////
//definition of the partition function
template<class T>
int partition(vector<T>& set, int start ,int end,bool (*compare)(const T&,const T&)){
int pivotIndex,mid;
T pivotValue;
T temp;
mid= (start+end)/2;
//swaps the mid and first positions
temp= set[mid];
set[mid]=set[start];
set[start]=temp;

pivotIndex =start;
pivotValue = set[start];

for (int scan=start+1; scan <=end;scan++){
        if (compare(set[scan],pivotValue)){
                pivotIndex++;
		//Swaps the next available position with the value if its smaller than the pivot
                temp=set[scan];
                set[scan]=set[pivotIndex];
                set[pivotIndex]=temp;
        }
}
//swaps the positions of the first and the last value found to be smaller than the pivot
temp= set[start];
set[start]= set[pivotIndex];
set[pivotIndex]=temp;
return pivotIndex;
}



#endif
