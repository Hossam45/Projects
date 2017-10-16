// MURAT ORTAK 125312157 11-12-2016

#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__
#include<iostream>
#include<ostream>
#include "Good.h"
#include "Error.h"
#include"wpgeneral.h"
namespace ict {
	// comment
   class OnShelf :public Good{
   private:
	   char recTag_;
   protected:
	   Error err_;
	   
   public:
	   // comment
	   OnShelf(char recTag_ = 'O');
	   virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const;
	   virtual std::fstream& load(std::fstream& file);
	   virtual std::ostream& display(std::ostream& os, bool linear)const;
	   virtual std::istream& conInput(std::istream& istr);
   };
}
#endif