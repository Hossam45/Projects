#include<iostream>
#include<fstream>
#include<string>
#include"Station.h"

using namespace std;
using namespace w2;

	Station::Station()                //a default constructor that initizalizes the instance variable through an initializations list
        {
        }
        Station::Station(fstream& is)     // a constrictor that reads a fstream file, storing the station data in this class
        {
                string line;
                getline(is, line);
                cout << "line'" << line << "\n";

                 size_t index = 0;
                        while(index < line.size()){
                                if(line[index] != ';'){
                                        stationName += line[index];
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "name= " << stationName <<"\n";
                        if(index == line.size()){
                                cerr << "end-of-line encountered, no ';' on line ->" << line <<" <-\n";
                                exit(4);
                        }
                        if(line[index] != ';'){
                                cerr << "Station name not followed by a ';' \n";
                                exit(5);
                        }

                        index++; //skip ';' 

                        int student = 0;
                         //size_t index = 0;
                        while(index < line.size()){
                                if(isdigit(line[index])){   // might be just line[index] != ';'
                                        student = 10 * student + (line[index] - '0');
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "student = " << student << endl;
                        if(line[index] != ' '){
                                cerr << "Station student count not followed by a ';'" << endl;
                                cerr << "followed by a '" << line[index] << endl;
                                exit(6);
                        }

                        int adult = 0;
                         //size_t index = 0;
                        while(index < line.size()){
                                if(isdigit(line[index])){   // ,might be just line[index] != ';'
                                        adult = 10 * adult + (line[index] - '0');
                                        index++;
                                }else{
                                        break;
                                }
                        }

                        cout << "adult= " << adult << endl;
                        if(index != line.size() - 1){
                                cout << "index" << index <<", size=" << line.size() << endl;
                                cerr << "Station adult count not followed by unknown character" << endl;
                                exit(7);
                        }

                        set(stationName, student, adult);

        }
        void Station::set(const string& name, unsigned int student, unsigned int adult)
        {
                stationName          = name;
                passes[PASS_STUDENT] = student;
                passes[PASS_ADULT  ] = adult;
        }
        void Station::update(PassType pt, int change)
        {
                passes[pt] += change;
        }
        unsigned Station::inStock(PassType pt) const
        {
                return passes[pt];
        }
        const string& Station::getname() const
        {
                return stationName;
        }
        void Station::processUpdate()
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

        void Station::report()
        {
                cout << "name, student, adult" << endl
                        << stationName << ","
                        << passes[PASS_STUDENT] << ","
                        << passes[PASS_ADULT  ]
                        << "\n";
        }



}
