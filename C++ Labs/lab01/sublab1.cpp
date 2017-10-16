#include<iostream>
#include<cstring>
#include"CString.h"
#include"process.h"
using namespace std;
using namespace w1;
int main(int argc, char* argv[])
{
	/**cout << "argc=" << argc << "\n";

	for (int arg = 1; arg < argc; arg++) {
		cout << "argv[" << arg << "] = -->" << argv[arg] <<"<--\n";
	}**/

	cout << "Command Line : ";
	for (int arg = 0; arg < argc; arg++)
		cout << " " << argv[arg];	// clients want this way;
		//cout << " '" << argv [arg] <<"'";
	cout << "\n";

	if (argc == 1) {
		cerr << "Insufficient number of arguments (min1)\n";
		return 1;
	}
	cout << "Maximum number of characters stored: " << w1::MAX << "\n";
	
	for (int arg = 0; arg < argc; arg++)
		process(argv[arg]);

	return 0;	//everything is okay
}


