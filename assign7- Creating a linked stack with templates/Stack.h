
/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 7
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   11-16-17

   FUNCTION:   This is the header and has the definitions for the template class
               Linked Stack
*********************************************************************/

#ifndef STACK_H
#define	STACK_H
#include<stdexcept>
#include<iostream>
#include <assert.h>
using std::ostream;
using std::cout;
using std::endl;

//Forward declaration of the Stack template Class
template <class T>
class Stack;

//Forward declaration of the Node struct
template <class T>
struct Node;

 // Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

//Node class is declared here
template <class T>
struct Node{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next= nullptr);
};

////////////////////////////////////////////////////
//This is the defualt constructor for the node struct
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext){
   data = newData;
   next = newNext;
}

////////////////////////////////////////////////////
//The stack class declaration  follows
template <class T>
class Stack{
// friend declaration for the template function
friend ostream& operator<< <>(ostream&, const Stack<T>&);

private:
	Node<T>* stkTop; //this is the head pointer,it points to the first node in the list
	int stkSize;
	void copyList(const Stack<T>&);
public:
	~Stack();
	Stack();
	Stack(const Stack<T>&);
	size_t size() const;
	bool empty() const;
	void clear();
	void push(const T&);
	void pop();
	Stack<T>& operator=(const Stack<T>&);
	const T& top() const;
};
////////////////////////////////////////////////////
////////////////////////////////////////////////////
//Mehtod Definitions for the Stack Class follow 
////////////////////////////////////////////////////
///////////////////////////////////////////////////

//////////////////////////////////////////////////
//This is the method definition for the top method
template<class T>
const T& Stack<T>::top()const{
	return stkTop->data;
}

//////////////////////////////////////////////////
//This is the destructor
template <class T>
Stack<T>::~Stack(){
clear();//calls the clear method to delete the stack
}

//////////////////////////////////////////////////
//This is the method to overload the = operator
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
	if (this != &other){//checks for self assignment
		clear();//deletes the old list
		copyList(other);//copies the passed data to the list
		stkSize = other.stkSize;
	}

	return *this;
}

//////////////////////////////////////////////////
//This is the method definition of the clear method
template <class T>
void Stack<T>::clear(){
while(!empty()){//Calls the pop method to delete a node until the stack is empty
	pop();
}
}
//////////////////////////////////////////////////
//This is the method  definition of the pop method
template <class T>
void Stack<T>::pop(){
Node<T>* delNode = stkTop;//sets delete node to the fisrt entry in the stack
stkTop = stkTop->next;//sets the top node to the next in the list
delete delNode;
stkSize--;
}
//////////////////////////////////////////////////
//This is the copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& other){
   stkTop = nullptr;
   copyList(other);
   stkSize = other.stkSize;
}
//////////////////////////////////////////////////
//This is the method definition for the push method
template<class T>
void Stack<T>::push(const T& newItem){
	Node<T>* newNode = new Node<T>(newItem, stkTop);
	stkTop = newNode;
	stkSize++;
}
//////////////////////////////////////////////////
//This is method definition for the size method
template<class T>
size_t Stack<T>::size()const {
	return stkSize;
}

////////////////////////////////////////////////
//This is the method definition for the empty method
template <class T>
bool Stack<T>::empty()const{
	return stkSize==0;
}
///////////////////////////////////////////////////
//This is the default Constructor
template<class T>
Stack<T>::Stack(){
stkTop=nullptr;
stkSize =0;
}

/////////////////////////////////////////////////////
//This is a friend function that overloads the << operator
template<class T>
ostream& operator<< (ostream& lhs, const Stack<T>& rhs){
Node<T>* ptr;

for (ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
   lhs << ptr->data << ' ';

return lhs;
}
///////////////////////////////////////////////////////
//This is the method definition for the private method copyList
template <class T>
void Stack<T>::copyList(const Stack<T>& other){

Node<T>* ptr, * newNode, * last = nullptr;

for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next){//loops through the stack, copies the data to a new stack
	newNode = new Node<T>(ptr->data);
	if (last == nullptr)
		stkTop = newNode;
	else
		last->next = newNode;
	last = newNode;
}//end of for loop
}
#endif
