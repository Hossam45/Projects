#ifndef _CSTRING_H_
#define _CSTRING_H_

using namespace std;
namespace w1{
	const int MAX = 3;
class CString {
        char str[MAX + 1];      //+1 for the /0
public:
        CString(char* s);

        void display(ostream& os);
};

ostream& operator<<(ostream& os, CString& cs);
}

#endif
