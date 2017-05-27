// MURAT ORTAK 125312157 11-12-2016
#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__
#include "OnShelf.h"
#include "Date.h"
#include "Error.h"
namespace ict {
   class CustomMade : public OnShelf {
   private:
	   Date delivery_;
   public:
	   CustomMade();
	   const Date& delivery() const;
      void delivery(const Date &value);
	  virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const;
	  virtual std::fstream& load(std::fstream& file);
	  virtual std::ostream& display(std::ostream& os, bool linear)const;
	  virtual std::istream& conInput(std::istream& istr);
   };
}


#endif
