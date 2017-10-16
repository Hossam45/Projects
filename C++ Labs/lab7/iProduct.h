
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<iterator>
#include<vector>


using namespace std;

namespace w7{

     class iProduct {
       public:
         virtual double getCharge() const = 0;
         virtual void display(std::ostream&) const = 0;
     };
                                             
class Product : public iProduct{
                double pnum;
                double price;
                string ps;
        public:
        double getCharge()const {return price;}
       
        Product(double a, double b)
        {
                pnum = a;
                price = b;
        }
	void display(std::ostream& os) const
	{
		os << endl<<"pnum: " << pnum << " price: " << price;
	}
};
class TaxableProduct : public Product{

                
                char tax;
        public:
                double getCharge() const {return Product::getCharge();}
               
                TaxableProduct(double pnum2, double pr2, char ta) : Product(pnum2, pr2)
                {
                        
			tax = ta;
                }

		void display(std::ostream& os) const
		{
			Product::display(os);
			os << " TAX: " << tax;
		}
};

 iProduct* readProduct(std::ifstream& in)
        {	
		static int tc;
                //int count = 6;
		string line;
                string* realine = nullptr;
                iProduct* temp = nullptr;
                double numb = 0.0;
                double pr = 0.0;
		double numb2 = 0.0;
		double pr2 = 0.0;
		double pr3;
                char tax;
		int len;
				size_t count2 = 0;
			static int cc;
				getline(in,line);
				
				for (size_t j = 0; j < line.size(); j++) {
				   if (line[j] == ' ') {
					  count2++;
                                        }
			   }
			  		 
                                        if (count2 == 1) {
						
						for(int i = 0; i<line.size(); i++){
						if(line.at(i) == ' '){
						string n = line.substr(0,i);
						numb = atof(n.c_str());
					string p1 = line.substr(i+1, line.size()-1);
						pr = atof(p1.c_str());
						}
						}
						  temp = new Product(numb, pr);	
					       return temp;
						
					}
					else {
						char tt;
						int pos2 = line.find(' ');
						
					for(int i = 0; i < line.size(); i++){
						string n2 = line.substr(0,pos2);
						
						numb2 = atof(n2.c_str());
					
	
						string p2 = line.substr(6,5);
						pr2 = atof(p2.c_str());
					string t =line.substr(12, line.size()-1);
                                		tax = t[0];
						if(tax == 'H'){
							pr2 += pr2 * 0.13;
						}else{
							pr2 += pr2 * 0.15;
							
						}
					
					}
						temp = new TaxableProduct(numb2, pr2, tax);   
						return temp;
					
					}
			
			
	}

		std::ostream& operator<<(std::ostream& os, const iProduct& p){
			p.display(os);
			return os;
		}

}

