// MURAT ORTAK 125312157 11-12-2016
#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include<iostream>
#include<ostream>
#include "ReadWritable.h"
#include "wpgeneral.h"

namespace ict{
	class Good : public ReadWritable {
			char sku_[MAX_SKU_LEN+1];
			char* name_;
			double price_;
			bool taxed_;
			int quantity_;
			int qtyNeeded_;
		
		public:
			Good(const char sku[], const char* name, double price, int qn, bool taxed);
			Good(const Good&);	
			Good& operator=(const Good&);
			virtual ~Good();
			void setsku(const char* sku);
			void setprice(double pr);
			void setname(char* name);
			void settaxed(bool tax);
			void setquantity(int quan);
			void setqtyNeeded(int quan);
			const char* getsku() const;
			double getprice() const;
			char* getname() const;
			bool gettaxed() const;
			int getquantity() const;
			int getqtyNeeded() const;
			double getcost() const;
			bool operator==(const char*);
			int operator+=(int);
			 
	};
		double operator+=(double&, const Good&);
		std::ostream& operator<<(std::ostream&, const Good&);
		std::istream& operator>>(std::istream&, Good&);

}


#endif
