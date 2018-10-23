#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

//********************************************************************
//
// Stack template class definition
//
//********************************************************************

template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>);

template <class T>
class Stack
   {
   friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

   private:

      T* stkArray;
      size_t stkSize,
             stkCapacity;

   public:

      Stack();
      //Stack(const Stack<T>&);
      ~Stack();
      Stack<T>& operator=(const Stack<T>&);

      //bool empty() const;
      //size_t size() const;
      //size_t capacity() const;

      //void push(const T&);
      //void pop();
      //const T& top() const;

      //void reserve(size_t);
   };
 

//********************************************************************
//
// Stack template class method definitions
//
//********************************************************************

template <class T>
Stack<T>::Stack()
   {
   stkCapacity = 0;
   stkSize = 0;
   stkArray = NULL;
   }

template <class T>
Stack<T>::~Stack()
   {
   delete[] stkArray;
   }
/*
template <class T>
void Stack<T>::push(const T& val)
   {
   // If stack is full, allocate additional storage
   if (stkSize == stkCapacity)
      {
      if (stkCapacity == 0)
         reserve(1);
      else
         reserve(stkCapacity * 2);
      }

   stkArray[stkSize] = val;
   ++stkSize;
}

template <class T>
const T& Stack<T>::top() const
   {
   if (empty())
      throw std::underflow_error("Stack underflow on call to top()");

   return stkArray[stkSize - 1];
   }
*/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Stack<T>& rhs)
   {
   for (size_t i = 0; i < rhs.stkSize; ++i)
      lhs << rhs.stkArray[i] << ' ';

   return lhs;
   }

#endif
