/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 5 - Stack.cpp
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Tuesday, 10/31/2017 by 11:59 pm

   FUNCTION:   This program tests the functionality of the Stack
               class.
********************************************************************/
#include <iostream>
#include "Stack.h"

using std::endl;

/*******************************************************************
There are too many methods and are mostly pretty small to each have
a box description. Many are self explanatory and i will spread
line comments throughout.
*******************************************************************/
Stack::Stack() {
  stkSize = 0; //stack initialized to 0 for all data memebers
  stkCap = 0;
  stkArr = nullptr;
}

Stack::Stack(const Stack& other) {
  stkCap = other.stkCap;
  stkSize = other.stkSize;

  if (stkCap == 0) //checking for 0, dont want to make a 0 size arr
    stkArr = nullptr;
  else
    stkArr = new int[stkCap];

  for (size_t i = 0; i < stkSize; ++i) //loops through and copies
    stkArr[i] = other.stkArr[i]; 
}

Stack::~Stack() {
  delete [] stkArr;
}

ostream & operator<<(ostream& out, const Stack& stack) {
  //loop for adding stack elements to outstream
  for (size_t i = 0; i < stack.stkSize; i++)
    out << stack[i] << " ";

  return out;
}

size_t Stack::size() const {
  return stkSize;
}

size_t Stack::capacity() const {
  return stkCap;
}

bool Stack::empty() const {
  if (stkSize == 0)
    return true;
  return false;
}

int Stack::operator[](size_t n) const {
  return stkArr[n];
}

int& Stack::operator[](size_t n) {
  return stkArr[n];
}

void Stack::push(int val) {
  if (stkSize == stkCap) {//checking if stack is full
    if (stkCap == 0)
      reserve(1);
    else
      reserve(stkCap * 2);//new stack with double the memory
  }

  stkArr[stkSize] = val; //adding value to stack with enough space
  ++stkSize;
}

void Stack::reserve(size_t n) {
  if (n > stkCap) {
    int* tempArray = new int[n]; //new stack pointer

    for (size_t i = 0; i < stkSize; ++i)
      tempArray[i] = stkArr[i]; //copy old stack to new

    stkCap = n;
    delete[] stkArr;
    stkArr = tempArray; //set stack arr ptr to new one
  }
}

int Stack::top() const {
  return stkArr[stkSize - 1];
}

void Stack::pop() {
  --stkSize;
}

Stack& Stack::operator=(const Stack& other) {
  if (&other == this) //checking self assignment
    return *this;
  
  //this portion is basically the same as the copy constructor
  stkCap = other.stkCap;
  stkSize = other.stkSize;

  if (stkCap == 0)
    stkArr = nullptr;
  else
    stkArr = new int[stkCap];

  for (size_t i = 0; i < stkSize; ++i)
    stkArr[i] = other.stkArr[i];  
  
  return *this;
}

void Stack::clear() {
  stkSize = 0;
}

bool Stack::operator==(const Stack& rhs) const {
  if (stkSize != rhs.stkSize)//if size isnt ==, array cant ==
    return false;
  for (size_t i = 0;i < stkSize;i++){
    if (stkArr[i] != rhs.stkArr[i])//looping checking each number
      return false;
  }
  return true;
}
