#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<cstring>
#include<functional>

using namespace std;

namespace w8{
using namespace std;
	template<typename T>

	class DataTable

	{
	string f;
	vector<T> x;
	vector<T> y;
	int f1, n;
	public:
	
		DataTable(std::ifstream& in, int fw, int nd)
		{
			int count = 0;	
			string* linefile;
			vector<T> a;
			vector<T> b;
			f1 = fw;
			n = nd;
 		 string line;
                double numb = 0.0;
                double pr = 0.0;
                int len;
                size_t count2 = 0;
		while(!in.eof()){
                	getline(in,line);
                                for (size_t j = 0; j < line.size(); j++) {
                                   if (line[j] == ' ') {
                                          count2++;
                                        }
                           }       
						for(int i = 0; i<line.size(); i++){
                                                if(line.at(i) == ' '){
                                                string n = line.substr(0,i);
                                                numb = atof(n.c_str());
                                        string p1 = line.substr(i+1, line.size()-1);
                                                pr = atof(p1.c_str());
                                                x.push_back(numb);
						y.push_back(pr);
						}
						}
					
		}
	}
		T mean() const
		{
			T result = accumulate(y.begin(), y.end(), (int)0);
			T mean1 = result / y.size();
			cout << "MEAN IS: "<< mean1 << endl;
			return mean1;
		}

		T sigma() const
		{
			vector<T> m;
			T result = accumulate(y.begin(), y.end(), (int)0);
			T mean1 = result / y.size();
			for(auto r : y){
				T a = (r - mean1);
			      	T b = a*a;
			       	m.push_back(b);
			}
			T result1 = accumulate(m.begin(), m.end(), (int)0);
			T mean2 = result1 / (y.size() - 1);
			T realres = sqrt(mean2);
			cout << "SSD: " << realres << endl;
			return realres;
		}

		T median() const
		{
			vector<T> st = y;
			sort(st.begin(), st.end());
			int pos = st.size() / 2;
			cout << "MEDIAN IS: " << st[pos] << endl;
			return st[pos];
		}

		void regression(T& slope, T& y_intercept) const
		{	
			vector<T> firsttop;
			firsttop.resize(x.size());
			T first;
			transform(x.begin(), x.end(), y.begin(), firsttop.begin(),std::multiplies<T>()); 
			first = accumulate(firsttop.begin(), firsttop.end(), 0.0);
			cout << "first " << first << endl;
			T top = (y.size()*first);
			cout << "TOP: " << top << endl;
			T xac = accumulate(x.begin(), x.end(), (T)0.0);
			cout << "XAC: " << xac << endl;
			T yac = accumulate(y.begin(), y.end(), (T)0.0);
			cout << "YAC: " << yac << endl;

			T mp = (xac*yac);
			cout << "MP: " << mp << endl;
			
			T realtop = top - mp;
			cout << "REALTOP: " << realtop << endl;

			vector<T> sqx;
			for(auto r: x){
				
				T m1 = r*r;
				sqx.push_back(m1);
			}
			
			T botx1 = accumulate(sqx.begin(), sqx.end(), (T)0.0);
			T bot2 = (sqx.size()*botx1);
			T sxac = xac*xac;

			T bottom = bot2 - sxac;
			cout << "BOTTOM: " << bottom << endl;
			T result1 = realtop / bottom;
			
			cout << "SLOPE: " << result1	<< endl;
		
			
			T int1 = result1*xac;
			T int2 = yac - int1;
			T intreal = int2 / x.size();

			cout << "INT: " << intreal << endl;
			slope = result1;
			y_intercept = intreal;
		}

		void display(std::ostream& os) const
		{
			

			for(int i = 0; i < x.size(); i++){
				os << x[i] << " " << y[i] << endl;
			}
			
		}
	};
		template<class T>	
		std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt){
			dt.display(os);
			return os;
		}

}
