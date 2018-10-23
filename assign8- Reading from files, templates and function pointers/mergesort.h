/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   11-29-17

   FUNCTION:   This is the header and has the definitions for sorting
               lists
*********************************************************************/
#ifndef MERGESORT_H
#define MERGESORT_H
#include<iomanip>
#include<stdexcept>
#include<iostream>
#include<vector>
using std::cout;
using std::vector;
using std::endl;

////////////////////////////////////////
//Forward declarations of functions
template<class T>
void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));
template<class T>
void mergeSort(vector<T>&,int,int,bool (*compare)(const T&, const T&));
template<class T>
void merge(vector<T>&,int,int,int,bool (*compare) (const T&, const T&));

////////////////////////////////////////////
//Definition of the mergesort function,calls the merge sort that actually handles the sorting
template<class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	mergeSort(set,0,set.size()-1,compare);
}

/////////////////////////////////////////////////////////////
//Defintion of the merge sort function, the actual sortng happens here
template<class T>
void mergeSort(vector<T>& set,int low,int high,bool (*compare)(const T&, const T&)){
int mid;

if (low<high){
	mid=(low+high)/2;

	//Divides the set to sort each part
	mergeSort(set,low,mid,compare);
	mergeSort(set,mid+1,high,compare);

	//Combines the set back together
	merge(set,low,mid,high,compare);
}
}
template<class T>
void merge(vector<T>& set,int low,int mid,int high,bool (*compare) (const T&, const T&)){
vector<T> temp(high-low+1);

int i= low; //start of the left subvector
int j= mid+1; // start of the right subvector
int k=0;  //start of the merged vector

//loops until it is not at the end of of either of the subvectors
while (i<= mid && j <=high){
	if (compare(set[j],set[i])){
		temp[k]=set[j];
		++j;
		++k;
	}
	else{
		temp[k]=set[i];
		++i;
		++k;
	}
}//end of while
//Copies over the remaining left side elements
while (i<= mid){
	temp[k]=set[i];
	++i;
	++k;
}
//Copies over the right side elements
while (j <= high){
	temp[k]=set[j];
	++j;
	++k;
}
// copies the sorted data back into the original vector
for(i=0,j=low; j<=high; i++, j++)
	set[j]=temp[i];
}



#endif
