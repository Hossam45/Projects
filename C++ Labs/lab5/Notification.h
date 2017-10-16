#pragma once

#include<iostream>
#include<fstring>
#include<string>
#include"Message.h"

namespace w5{
const int MAX_SIZE = 10;
class Notifications{
	Message *messageTable;
	int 	messageCount;

	public:	
Notifications() // default constructor - empty
: messageTable(nullptr), messageCount(0)
{

}
Notifications(const Notifications&) // copy constructor
: messageTable(nullptr), messageCount(0)
{
	std::cout << "Notifications: cop cons" << std::endl;
	messageCount = rhs.messageCount;
	if(rhs.messageTable != 0){
		for(int i = 0; i < messageCount; i++){
		messageTable[i] = rhs.messageTable[i];
		}
	}
}
Notifications& operator=(const Notifications&) //- copy assignment 
//operator
: messageTable(nullptr), messageCount(0)
{
	std::cout<<"Notifications: cop ass op" << std::endl;
	if(this != &rhs){
		delete [] messageTable;
		if(rhs.messageTable){
			messageTable = new Message [MAX_SIZE];
			for(int i =0; i < messageCount; i++){
				messageTable[i] = rhs.messageTable[i];
			}
		}
	}
	return *this;
}
Notifications(Notifications&&) //- move constructor
: messageTable(rhs.messageTable), messageCount(rhs.messageCount) // steal brains
{
	std::cout << "Notifications: move cons" << std::endl;
	/*delete [] messageTable;
	messageTable = rhs.messageTable;
	messageCount = rhs.messageCount;*/ // unnecessary
	rhs.messageTable = nullptr; // make rhs a zombie
	rhs.messageCount = 0;
}
Notifications&& operator=(Notifications&&) //- move assignment operator
{
	std::cout << "Notifications: move ass op" << std::endl;
	if(this != &rhs ){
	delete [] messageTable;	//delete our 'brains' (if we have any)
	//steal 'brains'
	messageTable = rhs.messageTable;
	messageCount = rhs.messageCount;
	//make rhs a 'zombie'
	rhs.messageTable = nullptr;
	rhs.messageCount = 0;
	}
	return std::move(*this);
}
~Notifications() //- destructor
{
	std::cout << "Notifications: Destructor" << std::endl;
	delete [] messageTable;
}

void operator+=(const Message& msg) //- adds msg to the set
{
	std::cout << "Notifications: += operator" << std::endl;
	if(messageTable == nullptr)
		messageTable = new Message[MAX_SIZE];
	if(messageCount < MAX_SIZE){
		messageTable[messageCount] = msg;
		messageCount++;
	}
}
void display(std::ostream& os) const //- inserts the Message objects to 
//the os output stream
{
	for(int i = 0; i < messageCount; i++){
		messageTable[i].display(os);
	}
}

};
}
