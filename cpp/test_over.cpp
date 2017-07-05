#include <iostream>

using namespace std;

class A {
public:
    void fun1() {
        cout << "A::fun1()\n";
    }
    virtual void fun2() {
        cout << "A::fun2()\n";
    }
    virtual void fun3() {
        cout << "A::fun3()\n";
    }
    void fun4() {
        cout << "A::fun4()\n";
    }
    virtual void fun5() {
        cout << "A::fun5()\n";
    }
    void fun6() {
        cout << "A::fun6()\n";
    }
    void fun7() {
        cout << "A::fun7()\n";
    }
    virtual void fun8() {
        cout << "A::fun8()\n";
    }
};

class B : public A {
public:
    virtual void fun3() {
        cout << "B::fun3()\n";
    }
    virtual void fun4() {
        cout << "B::fun4()\n";
    }
    virtual void fun5(int n) {
        cout << "B::fun5(int)\n";
    }
    virtual void fun6(int n) {
        cout << "B::fun6(int)\n";
    }
    virtual void fun7() {
        cout << "B::fun7()\n";
    }
    virtual void fun7(int n) {
        cout << "B::fun7(int)\n";
    }
    virtual void fun8() {
        cout << "B::fun8()\n";
    }
    virtual void fun8(int n) {
        cout << "B::fun8(int)\n";
    }
};

int main() {
    A *p1 = new A();
    A *p2 = new B();
    B *p3 = new B();

    p1->fun1();
    p2->fun1();
    p3->fun1();

    p1->fun2();
    p2->fun2();
    p3->fun2();

    p1->fun3();
    p2->fun3();
    p3->fun3();

    p1->fun4();
    p2->fun4();
    p3->fun4();

    p1->fun5();
    p2->fun5();
    // p3->fun5();

    p1->fun6();
    p2->fun6();
    // p3->fun6();

    p1->fun7();
    p2->fun7();
    p3->fun7();

    p1->fun8();
    p2->fun8();
    p3->fun8();

    // p2->fun7(1);
    // p2->fun8(1);
    p3->fun7(1);
    p3->fun8(1);

    return 0;
}
