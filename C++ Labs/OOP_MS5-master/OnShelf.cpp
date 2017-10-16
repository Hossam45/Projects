// MURAT ORTAK 125312157 11-12-2016
#include "OnShelf.h"
#include<iostream>
#include<fstream>
#include<ostream>
#include<istream>
#include<iomanip>
#include<cstring>
using namespace std;
namespace ict {
	OnShelf::OnShelf(char filetag) : Good("NULL","NULL", 0, 0, true ){
		recTag_ = filetag;
	}

	std::fstream& OnShelf::store(std::fstream& file, bool addNewLine) const {
		
			file << recTag_ << "," << getsku() << "," << getname() << "," << getprice() << "," << gettaxed() << "," << getquantity() << "," << getqtyNeeded();
			if (addNewLine) {
				file << endl;
			}
		
		return file;
	}

	std::fstream& OnShelf::load(std::fstream& file) {

		char s[100];
		char n[100];
		
		double d;
		bool tax = true;
		int qn;
		int qty;
		
			file.getline(s,100, ',');
			setsku(s);
			file.getline(n, 100, ',');
			setname(n);
			
			file >> d;
			file.ignore();
			setprice(d);	
			
			
			file >> tax;
			file.ignore();
			settaxed(tax);
			
			
			file >> qn;	
			file.ignore();
			setquantity(qn);
			

			file >> qty;
			file.ignore();
			setqtyNeeded(qty);
			
		return file;

	}
	std::ostream& OnShelf::display(std::ostream& os, bool linear) const {
		if (!err_.isClear()) {
			os << err_.message();
			
		}
		else {
			if (linear) {
				os << left;
				os << getsku() << "|";
				os << left;
				os << setfill(' ');
				os << setw(20);
				os << getname() << "|";
				os << right;
				os << setw(7); 
				os << fixed << setprecision(2) << getcost() << "|";
				if (gettaxed()) {
					os << setw(2) << "t" << setw(2) << "|";
				}
				else {
					os << setfill(' ') << setw(4) << "|";
				}
				os << right;
				os << setw(4);
				os << getquantity() << "|";
				os << right;
				os << setw(4);
				os << getqtyNeeded() << "|";

			}
			else {
				if (gettaxed()) {
					os << "Sku: " << getsku() << endl << "Name: " << getname() << endl << "Price: " << getprice() << endl << "Price after tax: " << getcost() << endl << "Quantity On hand: " << getquantity() << endl << "Quantity Needed: " << getqtyNeeded();
				}
				else {
					os << "Sku: " << getsku() << endl << "Name: " << getname() << endl << "Price: " << getprice() << endl << "Price after tax: " << "N/A" << endl << "Quantity On hand: " << getquantity() << endl << "Quantity Needed: " << getqtyNeeded();
				}
			}

		}
		return os;
	}
	std::istream& OnShelf::conInput(std::istream& istr) {
		char s[100];
		char n[100];
		
		int b = strlen(n);
		char t;
		double d;
		int qn;
		int qty;

		err_.clear();
		cout << "Sku: ";
				istr >> s;			
				setsku(s);
				cout << "Name: ";
				istr >> n;
				setname(n);
				cout << "Price: ";
				istr>> d;
				if (istr.fail()) {
					err_.message("Price failed");
					return istr;
				}
				else {
					setprice(d);
					
				}
				cout << "Taxed? (y/n): ";
				istr>> t;
				
				if (t == 'Y' || t == 'y') {
					settaxed(true);
					
				}
				else if (t == 'N' || t == 'n') {
					settaxed(false);
					
				}
				else {
					err_.message("Only (Y)es or (N)o are acceptable");
					istr.setstate(ios::failbit);
					return istr;

				}
				
				cout << "Quantity On Hand: ";
				istr>> qn;
				if (istr.fail()) {
					err_.message("no quantity");
					return istr;
				}
				else {
					setquantity(qn);
					
				}
				
				cout << "Quantity Needed: ";
				istr >> qty;
				if (istr.fail()) {
					err_.message("fail needed");
					return istr;
				}
				else {
					setqtyNeeded(qty);
					
				}
				
		return istr;
	}

}