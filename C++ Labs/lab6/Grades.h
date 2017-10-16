#ifndef GRADES_H
#define GRADES_H

#include<iostream>
#include<istream>
#include<ostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<iterator>

using namespace std;

namespace w6{

class Grades {
	size_t count;	
	string* linefile;
	string* grades;
	float* marks;
public:
Grades(const Grades& rhs) = delete;
Grades& operator=(const Grades& rhs) = delete;
Grades(Grades&& rhs) = delete;
Grades&& operator=(Grades&& rhs) = delete;


~Grades()
{
	delete [] linefile;
}
Grades(char* file) : count(0)
{

	fstream in(file, std::ios::in);
	if(in.is_open()){
		string line;
	       while(getline(in, line)){ // get the lines in the file until the end of the file.
		   	 count++;	// for every line it adds 1 to the variable. In that way, we can determine the memory size needed to be allocated.    
	       }
	       	in.clear();		// clear falied eof state
		in.seekp(0, std::ios::beg);	// after getting the lines, position is at the end of the file. If it does not positioned at the beginning of the file
						// in the next step where actually storing the lines to memory, it will only store the end of the file which is nothing
						// By using seekp, it goes back to end of the file and becomes ready to get the lines from file.
 		
	       	linefile = new string[count];	//dynamically allocated memory using count.
		grades = new string[count];
		marks = new float[count];
		for(size_t i = 0; i < count; i++){	
			getline(in, linefile[i], ' ');
			getline(in, grades[i]);
			marks[i] = stof(grades[i]);	
			
		}	
		in.close();
	}
	else{
		cerr<<"Cannot Open the File" << endl;
	}		
}
template<typename T>
void displayGrades(std::ostream& os,  T let) const
{
	for(size_t i = 0; i < count;  i++){
		os << linefile[i] << " " << marks[i] << " " << let(marks[i]) << endl;
	}
}


};
}

#endif
