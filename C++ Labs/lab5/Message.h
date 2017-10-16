//#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

#include<iostream>
#include<fstream>
#include<string>

namespace w5{

class Message {
	std::string name, reply, tweet;

public:
Message()
{
}
Message(std::ifstream& in, char c) /*- constructor retrieves a record 
from 
the in file object, parses the record (as described above) and stores 
its components in the Message object.  c is the character that delimits 
each record*/
{
	std::string line;
	getline(in, line, c);
	std::cout << "line->" << line << "<--" << std::endl;
	auto cr = line.find( '\r' );
	
	size_t index = 0;
	
	while( index < line.size()){
		if(line[index] == ' ') break;
		name += line[index];
		index++;
	}
	std::cout << "name = '" << name << "'" << std::endl;
	std::cout << "line[index] = '" << line[index] << "'" << std::endl;
	index++; //skip the ' '
	
	if(index < line.size() && line[index] == '@' ){ // we have a @ reply field
		index++; // skip the '@'
	
	while(index < line.size()){
		if(line[index] == ' ') break;
		reply += line[index];
		index++;
	}
	//std::cout << "reply = '" << reply << "'" << std::endl;
	index++;
	}
	while(index < line.size()){
		tweet += line[index];
		index++;
	}	
	//std::cout << "tweet = '" << tweet << std::endl;
}
bool empty() const //- returns true if the object is in a safe empty 
//state
{
	return tweet.empty();
}
void display(std::ostream& os) const //- displays the Message objects 
//within the container
{
	os << "Message" << std::endl << "User  :" << name << std::endl; 
	if(!reply.empty()){
	os <<  "Reply :" << reply << std::endl;
	}
	os<< "Tweet :" << tweet << std::endl;
}

};

}	//namespace w5

#endif
