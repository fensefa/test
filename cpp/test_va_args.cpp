#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <cstring>

using namespace std;

int fun(int n, ...) {
    return n;
}

int fun2(int n, ...) {
    va_list v1,v2;
    va_start(v1,n);
    for(int i = 0; i < 5; ++i) {
        cout << va_arg(v1, int) << endl;

        // this wile case unexpected things
        // cout << va_arg(v2, int) << endl;
        
        cout << "-----\n";
    }
    // This macro should be invoked before the function returns whenever va_start has been invoked from that function.
    va_end(v1);
    va_end(v2);
    return 0;
}

int max(int first, ...) {
    va_list v1;
    va_start(v1, first);
    while(1) {
        int x = va_arg(v1, int);
        cout << x << endl;
        if (0 == x) {
            break;
        }
    }
    va_end(v1);
    return 0;
}

int pprint(char* first, ...) {
    va_list v1;
    va_start(v1, first);
    char *p = first;
    while(1) {
        cout << "-----\n";
        p = va_arg(v1, char*);
        if (NULL == p) {
            cout << "NULL\n";
            break;
        }
        else {
            cout << "not NULL\n";
        }
        if (p != NULL) {
            // cout << strlen(p) << endl;
            cout << p[0] << endl;
        }
    }
    va_end(v1);
    return 0;
}

int main() {
    cout << fun(3) << endl;
    fun2(9,8,7,6,5,4,3,2,1);
    max(2,0,34,2,3,4324,234,234,24,2,4);
    max(2,3,43,4);
    
    // this will cause compile error, I don't understand
    // max(2,43,4);

    // this will core dump
    // pprint("234","2432","hello","world","","daf");

    // this will cause compile warning
    // pprint("234","2432","hello","world","","daf", NULL);
    
    char p1[] = "hello";
    char p2[] = "world";
    char p3[] = "what";
    char p4[] = "are";
    char p5[] = "you";
    pprint(p1, p2, p3, p4, p5, NULL);
    return 0;
}
