/********i************************************************************
   PROGRAM:    CSCI 241 Assignment 7 - Stack.h
   PROGRAMMER: Kevin Kang
   LOGON ID:   z1837081
   SECTION:    4
   TA: Abdul   Subhan Moin Syed
   DUE DATE:   Thursday, 11/16/2017 by 11:59 pm

   FUNCTION:   This program implements the stack ADT using a singly-linked list
               and templates.
*********************************************************************/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

//********************************************************************
//Node template struct definition
//********************************************************************
template <class T>
struct Node {
  T data;
  Node<T>* next;
 
  Node(const T& = T(), Node<T>* next = nullptr);
};

//********************************************************************
// Node template struct constructor definition
//********************************************************************
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext) {
  data = newData;
  next = newNext;
}

//********************************************************************
// Stack template class definition
//********************************************************************
template <class T>
class Stack;

template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

template <class T>
class Stack {
  friend std::ostream& operator<< <>(std::ostream&, const Stack<T>&);

  private:
    Node<T>* stkTop;
    size_t stkSize;
    void copyList(const Stack<T>&);
   
  public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();

    size_t size() const;
    bool empty() const;

    void push(const T&); 
    void clear();

    Stack<T>& operator=(const Stack<T>&);
    
    T& top() const;
    void pop();
};

//********************************************************************
// Stack template class method definitions
//********************************************************************

// Stack() - the constructor, initializes a Stack Object
template <class T>
Stack<T>::Stack() {
  stkSize = 0;
  stkTop = nullptr;
}

// Stack(const Stack<T>&) - copy constructor, copies another stack object
template <class T>
Stack<T>::Stack(const Stack<T>& other) {
  stkTop = nullptr;
  copyList(other);
  stkSize = other.stkSize;
}

// ~Stack() - destructor, deletes dynamic data
template <class T>
Stack<T>::~Stack() {
  clear();
}

// size() - returns stack size
template <class T>
size_t Stack<T>::size() const {
  return stkSize;
}

// empty() - returns true if stack is empty, true if not
template <class T>
bool Stack<T>::empty() const {
  if (stkSize == 0)
    return true;
  else
    return false;
}

// operator<< - output overloaded so we can use << to output the data in a Stack
template <class T>
std::ostream & operator<<(std::ostream &out, const Stack<T> &stack) {
  Node<T> *ptr;

  //loop moves from the top of stack through link nodes to the next and eventual end
  for (ptr = stack.stkTop; ptr != nullptr; ptr = ptr->next)
    out << ptr->data << ' ';

  return out;
}

// push - takes in a constant template value and adds it to the top of the stack
template <class T>
void Stack<T>::push(const T& val) {
  Node<T>* newNode = new Node<T>(val, stkTop);
  stkTop = newNode;
  stkSize++;
}

// copyList - private function that takes in Stack Object and dynamically copies the linked list
template <class T>
void Stack<T>::copyList(const Stack<T>& other) {
  Node<T> *ptr, *newNode, *last = nullptr;
  
  //loops through other Stack and copies each node to a new linked list
  for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next) {
    newNode = new Node<T>(ptr->data);
  
    if (last == nullptr)
      stkTop = newNode;
    else
      last->next = newNode;
 
    last = newNode;
  }
}

// clear() - deletes all the elements in a Stack
template <class T>
void Stack<T>::clear() {
  Node<T> *temp;
 
  while (stkTop != nullptr) {
    temp = stkTop->next;
    delete stkTop;
    stkTop = temp;
  }
}

// operator= - assignment operator overload, copies data from one Stack to another
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
  if (this != &other) {
    clear();
    copyList(other);
    stkSize = other.stkSize;
  }
 
  return *this;
}

// top() - returns a reference to the top of the stack
template <class T>
T& Stack<T>::top() const {
  if (stkSize == 0)
    throw std::underflow_error("Stack underflow on call to top()");

  return stkTop->data;
}

// pop() - pops or removes the top member of the stack
template <class T>
void Stack<T>::pop() {
  if (stkSize == 0)   
    throw std::underflow_error("Stack underflow on call to pop()");

  Node<T>* delNode = stkTop;
  stkTop = stkTop->next;       
  delete delNode;
  stkSize--;
}

#endif
