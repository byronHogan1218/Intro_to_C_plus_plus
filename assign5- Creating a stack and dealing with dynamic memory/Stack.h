/*
Programmer: Byron Hogan
Zid: z1825194
Date due: 10-26-2017
Purpose:  To declare the class methods
*/
#ifndef STACK_H
#define STACK_H
#include<iostream>
using std::ostream;
class Stack{
	friend ostream& operator<<(ostream&,  const Stack&);

	private:
		int* stackPtr;
		size_t stackCap;
		size_t stackSize;

	public:
		Stack();
		Stack(const Stack&);
		~Stack();
		size_t  size()const;
		size_t capacity()const;
		bool empty()const;
		void reserve(size_t n);
		void push(int);
		int top()const;
		void pop();
		void clear();
		Stack& operator=(const Stack&);
		int operator[](size_t) const;
		int& operator[](size_t);
		bool operator==(const Stack&)const;


};
#endif

