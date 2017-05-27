// MURAT ORTAK 125312157 11-12-2016
#include "CustomMade.h"
#include<istream>
#include<ostream>
#include<iostream>
#include<fstream>


using namespace std;

namespace ict {
	CustomMade::CustomMade() : OnShelf('C') {
		
	}
	const Date& CustomMade::delivery() const
	{
		return delivery_;
	}

	void CustomMade::delivery(const Date& value) {
		delivery_ = value;
	}
	std::fstream& CustomMade::store(std::fstream& file, bool addNewLine) const {
		OnShelf::store(file, false);
		file << ',' << delivery();
		if (addNewLine) {
			file << endl;
		}
		return file;
	}

	std::fstream& CustomMade::load(std::fstream& file) {
		OnShelf::load(file);
		file >> delivery_;
		//file.ignore();
		return file;
	}

	std::ostream& CustomMade::display(std::ostream& os, bool linear)const {
		OnShelf::display(os, linear);
		if (err_.isClear()) {
			if (linear) {
				os << delivery_;
			}
			else {
				os << endl << "Delivery Date: " << delivery();
			}
		}
		return os;
	}

	std::istream& CustomMade::conInput(std::istream& istr) {
		
		OnShelf::conInput(istr);
		Date temp;
		
		if (err_.isClear()) {
			cout << "Delivery Date: ";
			
			istr >> temp;
			if (temp.bad()) {
				if (temp.errCode() == CIN_FAILED) {
					err_.message("Invalid Date Entry");
				}
				else if (temp.errCode() == YEAR_ERROR) {
					err_.message("Invalid Year in Date Entry");
					cout << "YEAR FAULT IN CM: " << temp;
				}
				else if (temp.errCode() == MON_ERROR) {
					err_.message("Invaild Month in Date Entry");
				}
				else if (temp.errCode() == DAY_ERROR) {
					err_.message("Invalid Day in Date Entry");
				}
				istr.setstate(ios::failbit);
			}
			else {
				delivery(temp);
			}
			
		}

		return istr;
	}


}
