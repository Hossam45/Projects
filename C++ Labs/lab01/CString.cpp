#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"CString.h"
using namespace std;
using namespace w1;
        CString::CString(char* s)
        {
                if (s == nullptr) {
                        str[0] = '\0';
                        return;
                }
                strncpy(str, s, MAX);
                str[MAX] = '\0';

        //cout << "CString(" << s << ") stored -> " << str << "<-\n";
        }

        void CString::display(ostream& os)
        {
                os << str;
        }


ostream& operator<<(ostream& os, CString& cs) 
{
        static int count = 0;
        os << count << ": ";
        count++;
        cs.display(os);
        return os;
}

