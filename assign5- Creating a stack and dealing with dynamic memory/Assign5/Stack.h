/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 5 - Stack.h
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Tuesday, 10/31/2017 by 11:59 pm

   FUNCTION:   This program is the header file for Stack.cpp, and 
               contains its method prototypes
               
*********************************************************************/
#ifndef STACK_H
#define STACK_H
#include <iostream>

using std::ostream;

class Stack {
  
  private:
    size_t stkCap;
    size_t stkSize;
    int* stkArr;
  public:
    Stack();
    ~Stack();
    Stack(const Stack&);
    
    Stack& operator=(const Stack&);
    void clear();

    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    int top() const;
        
    void push(int);
    void pop();
    void reserve(size_t);

    int operator[](size_t) const;
    int& operator[](size_t);
    bool operator==(const Stack&) const;

    friend ostream& operator<<(ostream&, const Stack&);
};
#endif
