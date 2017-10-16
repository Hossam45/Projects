
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
#include"iProduct.h"
#include<memory>
using namespace std;
namespace w7{
        class Sale {
                std::vector<iProduct*> pro1;
		iProduct* p;
        public:
                Sale(const char* file)
                {
			string line;
                        ifstream in(file, ios::in);
                        while(!in.eof()){
				p = readProduct(in);	
				pro1.push_back(p);
			}
			pro1.pop_back();
		}

                void display(std::ostream& os) const {
			double tax1= 0.0;
		for(auto p : pro1){
				p->display(os);
				os << " CHARGE IS: " << p->getCharge();	
				tax1 += p->getCharge();
			}
			os << endl << "Total Charged are: " << tax1;
                }
        };
}
