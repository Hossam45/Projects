#ifndef STATION_H
#define STATION_H
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
namespace w2{
enum PassType {PASS_STUDENT, PASS_ADULT, PASS_COUNT };

class Station {
        string stationName;
        unsigned int passes[PASS_COUNT];            
public:
        Station();
	Station(fstream&);
	void set(const string&, unsigned int, unsigned int);
	void update(PassType pt, int change);
	unsigned inStock(PassType pt) const;
	const string& getname() const;
	void processUpdate();
	void report();
};

#endif
