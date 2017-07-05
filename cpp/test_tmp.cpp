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
    return a;
}
int fun(int a, int b = 0) {
    return a + b;
}
int main() {
    while(1) {
        usleep(1000);
    }
    fun(1, 2);
}
