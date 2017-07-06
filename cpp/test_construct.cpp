#include <cstdio>
class A {
public:
    A() {
        printf("A()\n");
    }
    A(const A& b) {
        printf("A(const A&)\n");
    }
    A& operator= (const A& b) {
        printf("A& operator=(const A&)\n");
        return *this;
    }
};

int main() {
    A a1;
    A a2 = a1;
    a2 = a1;
    return 0;
}
