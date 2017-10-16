// MURAT ORTAK 125312157 11-12-2016
// header files go here
#include<iomanip>
#include<iostream>
#include<cstring>
#include<istream>
#include<ostream>
#include "Date.h"
#include "wpgeneral.h"
using namespace std;

namespace ict {
   // returns a unique value representing the date
   // this value is used to compare two dates
   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }


   // bool validate(), this is an optional private function
   // for validation logic and setting the _readErrorCode.
   // see the read() function description for more details
	bool Date::validate(){
		if(year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
			cout << "RETURN YEAR: " << year_;
			return true;			
		}
		else if(mon_ > 12 || mon_ < 1){
			readErrorCode_ = MON_ERROR;
			return true;	
		}
		else if(day_ > mdays() || day_ < 1){
			readErrorCode_ = DAY_ERROR;
			return true;	
		}
		return false;
	}
	
   // mdays():
   // returns the day of the month.
   // _mon value must be set for this function to work
   // if _mon is invalid, this function returns -1
   // leap years are considered in this logic
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 
};
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 
100 != 0)) || (year_ % 400 == 0));
   }


   // constructors
	Date::Date(){
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}		


   Date::Date(int year, int mon, int day) {
	  
		year_ = year;
		mon_ = mon;
		day_ = day;
	   	readErrorCode_ = NO_ERROR;
   }


   // member functions
   void Date::errCode(int errorCode) {
	   readErrorCode_ = errorCode;
   }

	int Date::errCode() const {
		return readErrorCode_;
	}
	
	bool Date::bad() const {
		return readErrorCode_ != 0;
		
	}


   // operators
	bool Date::operator==(const Date& D) const{
		return this->value() == D.value();
	}	
                                             
    bool Date::operator!=(const Date& D) const{     
      		return this->value() != D.value();
		
    }                                         
                                              
    bool Date::operator<(const Date& D) const{      
      		return this->value() < D.value();
		       
    }                                         
                                             
    bool Date::operator>(const Date& D) const{      
      		return this->value() > D.value();
		      
    }                                                                
                                            
    bool Date::operator<=(const Date& D) const{     
      		return this->value() <= D.value();
		      
    }                                                              
                                              
    bool Date::operator>=(const Date& D) const{     
      		return this->value() >= D.value();
		      
    }                                   



   // IO functions
	std::istream& Date::read(istream& istr) {
		
		istr>>year_;
		istr.ignore();
		istr>>mon_;
		istr.ignore();
		istr>>day_;
		if(istr.fail()){
			readErrorCode_ = CIN_FAILED;	
		}else{
			Date temp(year_, mon_, day_);
			
			if(!validate()){
				*this = temp;
			}
		}
		return istr;
	}

	std::ostream& Date::write(ostream& ostr) const {
		ostr << right << setw(2) << setfill('0') << year_<<"/";
		ostr << right << setw(2) << setfill('0') << mon_ << "/";
		ostr << right << setw(2) << setfill('0') << day_;

		return ostr;
	}


   // non-memeber operator overload
	
	std::ostream& operator<<(ostream& os, const Date& D){
		D.write(os);
		return os;
	}	

	std::istream& operator>>(istream& is, Date& D){
                D.read(is);
                return is;

        }

}

