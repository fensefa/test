#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unistd.h>
using namespace std;
class A {
public:
    virtual int fun() = 0;
    ;
};

class B : public A {
public:
    virtual int fun() {
        return 0;
    }
};

int fun(int a) {
    cout << "fun(int)\n";
    return a;
}
int fun(int a, int b = 0) {
    cout << "fun(int, int)\n";
    return a + b;
}
class AA {
public:
    int x = fun(3, 5);
} a;

struct C {
    virtual void reset() {
        ;
    }
    C() {
        cout << "C()\n";
    }
    void operator()() {
        cout << "operator()()\n";
    }
};

class D {
    virtual void reset() {}
};
class D1 : public D {
    virtual void reset() {}
};
class D2 : public D {
    virtual void reset() {}
};

int main() {
    C()();
    C()();
    cout << sizeof(C);
    D d;
    D1 d11, d12;
    D2 d21, d22;
    cout << *(uint64_t*)(&d) << endl;
    cout << *(uint64_t*)(&d11) << endl;
    cout << *(uint64_t*)(&d12) << endl;
    cout << *(uint64_t*)(&d21) << endl;
    cout << *(uint64_t*)(&d22) << endl;
    for (int i = -22; i < 22; ++i) {
        cout << i << ',' << i / 10 << '\t';
    }
}
