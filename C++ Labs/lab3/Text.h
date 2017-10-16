
//#pragma once
#ifndef TEXT_H
#define TEXT_H

#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
namespace w3 {

class Text {

	size_t count;	//number of lines in the file
	std::string* lineTable;
public:
	size_t size() {return count;}
	
	void dump()
	{
		size_t number = count;
		if(number > 10) number = 10;
		for(size_t i = 0; i < number; i++){
			// i+1 to count from 1, not 0
			std::cout << "	line " << i+1 << " --> " << lineTable[i] << "<--" << std::endl;
		}
	}
	
	~Text()
	{
		std::cout << "dtor this/lineTable=" << (void*)this << "/" << (void*) lineTable << std::endl;
		delete [] lineTable;
	}
	
	Text() : count(0), lineTable(nullptr)
	{
	}
	
	Text(char* f) : count(0)
	{
	/*	 std::cout << "copy =op: this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTalbe=" << (void*)&rhs << "/" << (void*)rhs.lineTable << std::endl;*/
		std::fstream in(f, std::ios::in);
		if(in.is_open()){
			std::string line;
			while(getline(in, line)){
				count++;
			}		
			std::cout << "file '" << f << "' has " << count << " lines" << std::endl;
		lineTable = new std::string[count];
		for(size_t i = 0; i < count; i++){
			getline(in, lineTable[i]);
			auto cr = lineTable[i].find( '\r');
			if(cr != std::string::npos){
				lineTable[i].erase( cr );
			}
		}	
			in.close();
		//	dump();
		}else{
			std::cerr << "Cannot open the file" << f << std::endl;
			exit(3);
		}
	}
	
	Text& operator=(const Text& rhs)
	{
		/*std::cout << "copy =op: this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTalbe=" << (void*)&rhs << "/" << (void*)rhs.lineTable << std::endl;*/
		if(this != &rhs){
			delete[] lineTable;
			lineTable = nullptr;
			count = 0;

			count = rhs.count;
			// deep copy
			lineTable = new std::string[count];
			for(size_t i = 0; i < count; i++){
				lineTable[i] = rhs.lineTable[i];
			}
			return *this;
		}
	}

	Text&& operator=(Text&& rhs)
	{
		 /*std::cout << "copy =op: this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTalbe=" << (void*)&rhs << "/" << (void*)rhs.lineTable << std::endl;*/
		if( this!= &rhs){
			delete[] lineTable;

			//move pointer+count (steal brains)
			lineTable = rhs.lineTable;
			count = rhs.count;
			
			//turn rhs into a zombie
			rhs.lineTable = nullptr;
			rhs.count = 0;
			//count = 0;
		}
			return std::move(*this);
		
	}

	Text(const Text& rhs) : count(0), lineTable(nullptr)
	{
		/* std::cout << "copy =op: this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTalbe=" << (void*)&rhs << "/" << (void*)rhs.lineTable << std::endl;*/
		*this = rhs;
	}

	Text(Text&& rhs) : count(0), lineTable(nullptr)
	{
		 /*std::cout << "copy =op: this/lineTable=" << (void*)this << "/" << (void*)lineTable << " rhs/rhs.lineTalbe=" << (void*)&rhs << "/" << (void*)rhs.lineTable << std::endl;*/
		*this = std::move(rhs);
	}

};	// class Text

}	//namespace 3

#endif
