#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"Stations.h"

using namespace w2;
using namespace std;
   Stations::Stations(char* f)
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
                                        {
						stationCount = 10 * stationCount +(line[index] - '0');
                                		        index++;
					
                                	}else{
                                        	break;
                                	}
                        	
			}
                        cout << "stationCount= " << stationCount << "\n";
                        if(line[index] != ';'){
                                cerr << "Station count not followed by a ';'\n";
                                cerr << "followed by a '" << line[index] << "'\n";
                                exit(2);
                        }
                        stationTable = new Station [ stationCount ];
                        for(int s = 0; s < stationCount; s++){
                                stationTable[s] = Station(is);
				}
                        	is.close();
			}
                	}else {
                        	cerr << "cannot open file '" << f << "'\n";
                	}
		
    }
        void Stations::update()
        {
		//int stationCount = 0;
                cout << "Passes Sold: \n";
                for(int s = 0; s < stationCount; s++){
                        stationTable[s].processUpdate();
                }
        }

        void Stations::restock()
        {
        }

        void Stations::report()
        {
		//int stationCount = 0;
                for(int s = 0; s < stationCount; s++){
                        stationTable[s].report();
                }
        }

