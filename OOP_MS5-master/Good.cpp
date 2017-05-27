// MURAT ORTAK 125312157 11-25-2016
#include <cstring>
#include<string>
#include <iostream>
#include<ostream>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict{



void Good::setsku(const char* sku){
	strncpy(sku_, sku, MAX_SKU_LEN);
}

void Good::setprice(double pr){
	price_ = pr;
}

void Good::setname(char* name){
	name_ = new char[strlen(name)+1];
	strncpy(name_, name, strlen(name)+1);
}

void Good::settaxed(bool tax){
	taxed_ = tax;	
}

void Good::setquantity(int quan){
	quantity_ = quan;
}

void Good::setqtyNeeded(int qn){
	qtyNeeded_ = qn;
}

const char* Good::getsku() const {
	return sku_;
}

double Good::getprice() const{
	return price_;
}

char* Good::getname() const{
	return name_;
}

bool Good::gettaxed() const{
	return taxed_;
}

int Good::getquantity() const{
	return quantity_;
}

int Good::getqtyNeeded() const{
	return qtyNeeded_;
}

double Good::getcost() const {
	if(gettaxed()){
		return price_ * (TAX + 1);
	}else{
		return price_;
	}
}

Good::Good(const char sku[], const char* name, double p, int q, bool taxed){
	name_ = new char[strlen(name)+1];
	strncpy(name_, name, strlen(name)+1);
	strncpy(sku_, sku, MAX_SKU_LEN+1);
	quantity_ = 0;
	price_ = p;
	qtyNeeded_ = 0;
	taxed_ = taxed;
}

Good::~Good(){
	delete[] name_;
}

Good::Good(const Good& cp){
	strncpy(sku_, cp.sku_, MAX_SKU_LEN+1);
	if(cp.name_ != NULL){
		name_ = new char[strlen(cp.name_)+1];
		strncpy(name_, cp.name_, strlen(cp.name_)+1);
				
	}else{
		name_ = NULL;
	}
	quantity_ = cp.quantity_;
	qtyNeeded_ = cp.qtyNeeded_;
	taxed_ = cp.taxed_;
	price_ = cp.price_;
}

Good& Good::operator=(const Good& src){
	if(this != &src){
		strncpy(sku_, src.sku_, MAX_SKU_LEN+1);
		quantity_ = src.quantity_;
		qtyNeeded_ = src.qtyNeeded_;
		price_ = src.price_;
		taxed_ = src.taxed_;
		delete[] name_;
		if(src.name_ != NULL){
			name_ = new char[strlen(src.name_)+1];
			strncpy(name_, src.name_, strlen(src.name_)+1);
		}else{
			name_ = NULL;
		}
	}
	return *this;
}

bool Good::operator==(const char* ptr) {
	bool temp = true;
	
	for (int i = 0; i < MAX_SKU_LEN; ++i) {
		
		if (this->sku_[i] == ptr[i]) {
			return ptr[i];
		}else {
			temp = false;
		}
		
	}
	return temp;
	//return strcmp(sku_, ptr) == 0;
}
int Good::operator+=(int a){
	return this->quantity_ += a;
}


double operator+=(double& d, const Good& g){
	return d = g.getquantity() * g.getcost();
	
}

std::ostream& operator<<(std::ostream& os, const Good& g){
	g.display(os, true);
	return os;
}

std::istream& operator>>(std::istream& is, Good& g) {
	g.conInput(is);
	return is;
}
}
