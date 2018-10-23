/*
Programmer: Byron Hogan
Zid: z1825194
Date due: 10-19-2017
Purpose:  To define the class methods
*/
#include"Stack.h"
#include<string.h>
#include<assert.h>
#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
/////////////////
//defualt constructor 
Stack::Stack(){
	stackSize=0;
	stackCap=0;
	stackPtr=NULL;
}
//////////////////////////////////
//Copy constructor
Stack::Stack(const Stack& other) {
int* temp;
stackCap=other.stackCap;
stackSize=other.stackSize;
temp= new int[other.stackCap];
assert(temp!=0);
for (unsigned int i=0;i<stackSize;++i)
	temp[i]=other.stackPtr[i];
stackPtr=temp;//assigns the new values in temp to the dynamic array
 stackSize=other.stackSize;
 stackCap=other.stackCap;
}
///////////////////////////////
//Method to overload the = operator
Stack& Stack::operator=(const Stack& other){
 if(this == &other)
	return *this; // handles self assignment
int* temp;
stackCap=other.stackCap;
temp= new int[stackCap];
assert(temp!=0);
for (unsigned int i=0;i<other.stackSize;++i)//fills temp with the values of the right hand side
        temp[i]=other.stackPtr[i];
delete stackPtr;//frees any memory in the array location
stackPtr=temp;//assigns the new values of temp to the  dynamic array
stackSize=other.stackSize;
stackCap=other.stackCap;

   return *this;
}
//////////////////////////
//method to add slots to the array
void Stack::reserve(size_t n){
 if (n <= stackCap)//determines if more slots are actually neeeded
	return;
stackCap=n;
int* temp;
if (stackCap==0)//cant hold anything with no capacity
	temp=NULL;
else{//the following block of code creates fills the temp and reassigns it to the dynamic array
	temp= new int[stackCap];
	assert(temp!=0);
	for (unsigned int i=0;i <stackSize;++i){
		temp[i]=stackPtr[i];
	}
	delete stackPtr;//frees the memory being held
	stackPtr=temp;//assigns the dynamic array its new values
}
}
///////////////////////////////////
//method to add one value to the array
void Stack::push(int val){
if (stackSize==stackCap){//makes sure that there is a slt to put the value in
	if(stackCap==0)//increases the capacity from 0 to 1
		reserve(1);
	else
		reserve(2*stackCap);//doubles the capacity
}
stackPtr[stackSize]=val;//assigns the value to the top slot
stackSize++;
}
////////////////////////////////
//method to overload the << operator
ostream& operator<<(ostream& lhs,  const Stack& rhs){
for(unsigned int i=0;i<rhs.stackSize;++i){//loops through and prints out each element of the array
	lhs<< rhs.stackPtr[i]<< " ";
}
return lhs;
}
//////////////////////
//This method returns the size
size_t Stack::size() const{
 return this->stackSize;
}
/////////////////////////////
//This method returns the capacity
size_t Stack::capacity() const{
 return stackCap;
}
//////////////////////////
//This method returns is the array is empty
bool Stack::empty() const{
 return stackSize==0;
}
/////////////////////
//This method returns the top most slot of the array
int Stack::top()const {
 return stackPtr[stackSize-1];
}
//////////////////////////////
//This method removes a slot from the array
void Stack::pop(){
--stackSize;
}
/////////////////////////////
//This method clears the array
//Note:It does not delete it
void Stack::clear(){
stackSize=0;
}
////////////////////////////
//This is the default deconstructor
Stack::~Stack(){
delete stackPtr;
}
//////////////////////////////
//This is the read version of the subscribt operator
int Stack::operator[](size_t n)const{
return stackPtr[n];
}
//////////////////////////////////
//This is the write version of the subscribt operator
int& Stack::operator[](size_t n){
return stackPtr[n];
}
////////////////////////////////
//This is the method on overloading the == operator
bool Stack::operator==(const Stack& rhs)const{
if (stackSize!=rhs.stackSize)//determines if they are the same size
	return false;
for (unsigned int i=0; i<stackSize;++i){//determines if they hold the same elements
	if(stackPtr[i]!=rhs.stackPtr[i]){
		return false;
	}
}
return true;
}
