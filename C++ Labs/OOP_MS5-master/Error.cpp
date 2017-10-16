// MURAT ORTAK 125312157 11-12-2016
#include "Error.h"
#include <cstring>
#include <iostream>
#include<ostream>
using namespace std;

namespace ict{
	Error::Error(){
		message_ = NULL;
	}

	Error::Error(const char* Error){
		message_ = NULL;
		message(Error);
	}

	

	Error& Error::operator=(const char* errorMessage){
		clear();
		message(errorMessage);
		return *this;
	}

	Error:: ~Error(){
		delete [] message_;
	}

	void Error::clear(){
		delete [] message_;
		message_ = NULL;
	}

	bool Error::isClear() const{
		return message_ == NULL;
		
	}

	void Error::message(const char* value){
		clear();
		int v = strlen(value);
		message_ = new char [v+1];
		strcpy(message_, value);
	}

	

	std::ostream& operator<<(std::ostream& out, const Error& E){
		
		if(!E.isClear()){
			 out << E.message();
			 
		}
		return out;
	}
}
