
/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 6
   PROGRAMMER: Byron Hogan
   LOGON ID:   z1825194
   DUE DATE:   11-9-17

   FUNCTION:   This is the header and has the definitions for the template class
               Queue
*********************************************************************/

#ifndef QUEUE_H
#define	QUEUE_H
#include<stdexcept>
#include<iostream>
#include <assert.h>
using std::ostream;
using std::cout;
using std::endl;

//Forward declaration of the Queue template Class
template <class T>
class Queue;

 // Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>
class Queue{
// friend declaration for the template function
friend ostream& operator<< <>(ostream&, const Queue<T>&);

private:
	T *qArray;
	unsigned int qCap;
	unsigned int qSize;
	int qFront;
	int qBack;
public:
	Queue();
	~Queue();
	Queue(const Queue &);
	size_t size() const;
	size_t capacity();
	bool empty() const;
	void clear();
	void reserve(size_t);
	void push(const T&);
	void pop();
	const T& front() const;
	const T& back() const;
	Queue<T>& operator=(const Queue&);
};


//////////////////////////////////////////////////////////
//Method Definitions Below this point

/////////////////////////////////////
//This method overloads the "=" operator
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other){
 if(this == &other)
        return *this; // handles self assignment
   {
   qCap = other.qCap;
   qSize = other.qSize;
   delete qArray;
   qArray = new int[qCap];

   for (size_t i = 0; i < qCap; ++i)
      qArray[i] = other.qArray[i];

   qFront = other.qFront;
   qBack = other.qBack;
   }

   return *this;
}

//////////////////////////////////////
//This method returns the front of the queue
template <class T>
const T& Queue<T>::front() const{
        if (empty())
                throw std::underflow_error("queue underflow on front()");
        else{
                return qArray[qFront];
        }
}

/////////////////////////////////////
//This method returns the back of the queue
template< class T>
const T& Queue<T>::back() const{
        if (empty()){
                throw std::underflow_error("queue underflow on back()");
	}
        else{
                return qArray[qBack];
        }
}

/////////////////////////////////////////////
//This is the copy constructor
template<class T>
Queue<T>::Queue(const Queue& other)
   {
   qCap = other.qCap;
   qSize = other.qSize;
   qArray = new int[qCap];

   for (size_t i = 0; i < qCap; ++i)
      qArray[i] = other.qArray[i];

   qFront = other.qFront;
   qBack = other.qBack;
   }

//////////////////////////////////////////////
//This method  is used to remove a value from the array
template<class T>
void Queue<T>::pop(){
	if (qSize==0){
		throw std::underflow_error("queue underflow on pop()");
	}
	else{
		qFront = (qFront + 1) % qCap;
		qSize--;
	}

}

///////////////////////////////////////////////////
//This method is used to insert a value into the array
template <class T>
void Queue<T>::push(const T & value){
if (qSize==qCap){
	if (qCap==0)
		reserve(1);
else
	reserve(2*qCap);
}
qBack = (qBack + 1) % qCap;
qArray[qBack]=value;
++qSize;
}

///////////////////////////////////////////////////
//This method is used to increase the array
template <class T>
void Queue<T>::reserve(size_t n){
if (n <= qCap|| n== qCap)//determines if more slots are actually neeeded
        return;
qCap=n;
T *temp;
int current=qFront;
if (qCap==0)//cant hold anything with no capacity
        temp=NULL;
else{//the following block of code creates fills the temp and reassigns it to temp
        temp= new T[n];
        assert(temp!=0);
        for (unsigned int i=0;i <qSize;++i){
                temp[i]=qArray[current];
		current= (current +1)% qCap;
        }
	qFront=0;
	qBack=qSize-1;
        delete[] qArray;//frees the memory being held
        qArray=temp;//assigns the dynamic array its new values
}
}

///////////////////////////
//This method clears the array
template <class T>
void Queue<T>::clear(){
qSize=0;
qFront=0;
qBack= qCap-1;
}

////////////////////////////////////////
//Default Constructor
template <class T>
Queue<T>::Queue()
{
qSize=0;
qCap=0;
qArray=NULL;
qFront=0;
qBack=qCap-1;
}

///////////////////////////////////////////
//This method returns the sixe of the queue
template <class T>
size_t Queue<T>::size() const{
	return qSize;
}

//////////////////////////////
//this methodnreturns the cpacity of the queue
template <class T>
size_t Queue<T>::capacity(){
	return qCap;
}

/////////////////////////////////////
//THis method returns if the queue is empty or not
template <class T>
bool Queue<T>::empty() const{
	return qSize==0;
}


///////////////////////////////
//Friend function to overload the << operator
template <class T>
ostream& operator<< (ostream& lhs, const Queue<T>& rhs ){
size_t current, i;

for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
   {
   // Print queue element at subscript i
   lhs << rhs.qArray[current] << ' ';

   // Increment i, wrapping around to front of queue array if necessary
   current = (current + 1) % rhs.qCap;
   }
return lhs;
}

////////////////////////////////////////////////
//This is the method for the deconstructor
template <class T>
Queue<T>::~Queue(){
delete[] qArray;
}
#endif


