#include<iostream>
#include<cstring>
#include<string>
#include"process.h"
using namespace std;

void process::process1(char* s)
{
        //cout << "process(" << s << ")\n";
        w1::CString cs(s);
        cs.display(cout);
	//cout << "\n";
}
