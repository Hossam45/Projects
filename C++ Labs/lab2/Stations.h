#ifndef STATIONS_H
#define STATIONS_H

#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include"Station.h"

using namespace std;
/**namespace w2{
enum PassType {PASS_STUDENT, PASS_ADULT, PASS_COUNT };

class Station {
	string stationName;
	unsigned passed[PASS_COUNT];
public:
	Station()//a default constructor that initizalizes the instance 
variable through an initializations list
	{
	}
	Station(fstream& is) // a constrictor that reads a fstream file, 
storing 
the station data in this class
	{
		string line;
		getline(is, line);
		cout << "line'" << line"'\n";

		 size_t index = 0;
                        while(index < line.size()){
                                if(line[index] != ';'){
                                        name += line[index];
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "name= " << name <<"\n";
                        if(index == line.size()){
                                cerr << "end-of-line encountered, no ';' on line ->' << line " <-\n";
				exit(4);
                        }
			if(line[index] != ';'){
				cerr << "Station name not followed by a ';'\n";
				exit(5);
                        }

			index++; //skip ';' 
				
			int student = 0;	
			 size_t index = 0;
                        while(index < line.size()){
                                if(isdigit(line[index])){   // ,might be just line[index] != ';'
                                        student = 10 * student
                                        +(line[index] - '0');
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "student = " << student <<
                                "\n";
                        if(line[index] != " "){
                                cerr << "Station student count not followed by a
                                ';'\n';
                                cerr << "followed by a '" << line[index]
                                << "'\n";
                                exit(6);
                        }

			int adult = 0;
			 size_t index = 0;
                        while(index < line.size()){
                                if(isdigit(line[index])){   // ,might be just line[index] != ';'
                                        adult = 10 * adult
                                        +(line[index] - '0');
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "adult= " << stationCount <<
                                "\n";
                        if(index != line.size() - 1){
				cout << "index" << index <<", size=" << line.size() << "\n";
                                cerr << "Station adult count not followed by unknown character\n"
                                exit(7);
                        }

			set(name, student, adult);

	}
	void set(const string& name, unsigned student, unsigned adult)
	{
		stationName          = name;
		passes[PASS_STUDENT] = student;
		passes[PASS_ADULT  ] = adult;
	}
	void update(PassType pt, int change)
	{
		passes[pt] += change;
	}
	unsigned inStock(PassType pt) const
	{
		return passes[pt];
	}
	const string& getname() const
	{
		return stationName;
	}
	void processUpdate()
	{
		cout << stationName << "\n";
		cout << "Student Passes sold; ";
		int student;
		cin >> student;
		cout << "Adult Passes Sold: ";
		int adult;
		cin >> adult;
		
		update(PASS_STUDENT, student);
		update(PASS_ADULT, adult);
	}

	void report()
	{
		cout << "name, student, adult" << endl
			<< stationName << ","
			<< passes[PASS_STUDENT] << ","
			<< passes[PASS_ADULT  ]
			<< "\n";	
	}
	
			
	
};**/

class Stations {
	int stationCount;
	Station* stationTable;
public:
	Stations(char* f);
	void update();
	void restock();
	void report();
	/**Stations(char* f)
	{
		cout << "Stations(" << f << ")\n"  << endl;
		fstream is(f, ios::in);
		if(is.is_open()){
			string line;
			getline(is,line);
			cout << "line='" << line << "'\n";
			
			stationCount = 0;
			size_t index = 0;
			while(index < line.size()){
				if(isdigit(line[index])){   // ,might be just line[index] != ';'
					stationCount = 10 * stationCount 
					+(line[index] - '0');
					index++;
				}else{
					break;
				}
			}

			cout << "stationCount= " << stationCount << 
				"\n";			
			if(line[index] != ";"){
				cerr << "Station count not followed by a 
				';'\n';
				cerr << "followed by a '" << line[index] 
				<< "'\n";
				exit(2);
			}
			stationTable = new Station [ stationCount ];
			for(int s = 0; s < stationCount; s++){
				stationTable[s] = Station(is);
			}
			is.close();
		}else {
			cerr << "cannot open file '" << f << "'\n";
		}  
	}
	void update()
	{
		cout << "Passes Sold: \n";
		for(int s = 0; s < stationCount; s++){
			stationTable[s].processUpdate();
		}
	}
	void restock()
	{
	}
	void report()
	{
		for(int s = 0; s < stationCount; s++){
			stationTable[s].report();
		}
	}**/
};	// class Stations

#endif
