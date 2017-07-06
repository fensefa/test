#include <iostream>
#include <unistd.h>
using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
    int num;
};

int fun() {
    static A a;
    cout << "fun()" << endl;
}

int main() {
    A a;
    cout << "addr: " << &a << endl;
    int pid = fork();
    cout << "addr: " << &a << endl;
    a.num = pid;
    for(int i=0;i<1000+pid;++i) ++a.num;
    cout << "Hello, world" << endl;
    cout << pid << endl;
    cout << a.num << endl;
    fun();
    fun();
    fun();
    return 0;
}
