/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 6 - Queue.h
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Thursday, 11/9/2017 by 11:59 pm

   FUNCTION:   This program implements a Queue using templates and 
               error throwing.
               
********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

//********************************************************************
//
//Queue Template Class Definition
// 
//*******************************************************************

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template<class T>
class Queue {
  friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);
  private:
    size_t qSize,
        qCapacity,
        qFront,
        qBack;
    T* qArray;

  public:
    Queue();
    Queue(const Queue<T>&);
    ~Queue();

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    void push(const T&);
    void pop();
    void reserve(size_t n);

    const T& front() const;
    const T& back() const;

    Queue<T>& operator=(const Queue<T>&);

    void clear();
};

//********************************************************************
//
//Queue Template Class Method Definitions
//
// There are too many methods and are mostly pretty small to each have
// a box description. Many are self explanatory and i will spread
// line comments throughout.
//*******************************************************************

template <class T>
Queue<T>::Queue() {
  qSize = 0;
  qCapacity = 0;
  qFront = 0;
  qBack = qCapacity - 1;
  qArray = nullptr;
}

template <class T>
Queue<T>::Queue(const Queue<T>& other) {
   qCapacity = other.qCapacity;
   qSize = other.qSize;
   qArray = new T[qCapacity]; //making new dynamic Array

   for (size_t i = 0; i < qCapacity; ++i) //filling new Array
      qArray[i] = other.qArray[i]; 

   qFront = other.qFront;
   qBack = other.qBack;
}

template <class T>
Queue<T>::~Queue() {
  delete [] qArray;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& rhs) {
  size_t current, i;
      
  for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i) {
    // Print queue element at subscript i
    out << rhs.qArray[current] << ' ';
    
    // Increment i, wrapping around to front of queue array if necessary     
    current = (current + 1) % rhs.qCapacity;
  }

  return out;
}

template <class T>
size_t Queue<T>::size() const {
  return qSize;
}

template <class T>
size_t Queue<T>::capacity() const {
  return qCapacity;
}

template <class T>
bool Queue<T>::empty() const {
  if (qSize == 0)
    return true;
  else
    return false;
}

template <class T>
void Queue<T>::push(const T& val) {
  // If queue is full, allocate additional storage
  if (qSize == qCapacity) {
    if (qCapacity == 0)
      reserve(1);
    else
      reserve(qCapacity * 2); 
  }

  qBack = (qBack + 1) % qCapacity;
  qArray[qBack] = val;
  ++qSize;
}

template <class T>
void Queue<T>::pop() {
  if (empty())
    throw std::underflow_error("queue underflow on pop()");

  qFront = (qFront + 1) % qCapacity; //moves queue up one
  --qSize;
}

template <class T>
void Queue<T>::reserve(size_t n) {
  if (n < qSize || n == qCapacity) //checks if needs space
    return;

  T* tempArray = new T[n]; //makes new dynamic array

  int current = qFront;
  for (size_t i = 0; i < qSize; i++) { //fills new array
    tempArray[i] = qArray[current];
    current = (current + 1) % qCapacity;
  }

  qCapacity = n;
  qFront = 0;
  qBack = qSize - 1;
  delete[] qArray;    //removes old array
  qArray = tempArray; //points to new array
}

template <class T>
const T& Queue<T>::front() const {
  if (empty())
    throw std::underflow_error("queue underflow on front()");

  return qArray[qFront];
}

template <class T>
const T& Queue<T>::back() const {
  if (empty())
    throw std::underflow_error("queue underflow on back()");

  return qArray[qBack];
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
   if (&other == this) //checking self assignment
     return *this;

   qCapacity = other.qCapacity;
   qSize = other.qSize;
   qArray = new T[qCapacity]; //makes new array

   for (size_t i = 0; i < qCapacity; ++i) //fills new array
      qArray[i] = other.qArray[i];

   qFront = other.qFront;
   qBack = other.qBack;

   return *this;
}

template <class T>
void Queue<T>::clear() {
  qSize = 0; //resets valeus
  qFront = 0;
  qBack = qCapacity - 1;
}

#endif

