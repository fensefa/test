#include <iostream>
using namespace std;

class A {
public:
    A() {
        a = 0;
        cout << "A()\n";
    }
    A(const A& other) {
        a = other.a;
        cout << "A(const A&)\n";
    }
    ~A() {
        cout << "~A()\n";
    }
    void fun() {
        ++a;
        cout << a << endl;
    }
    void fun2() {
        a += 8;
    }
private:
    int a;
};
int main() {
    A a;
    a.fun();
    A b = std::move(a);
    b.fun2();
    b.fun();
    a.fun();
    string str1 = "str1";
    cout << str1 << endl;
    string str2 = std::move(str1);
    cout << str2 << endl;
    cout << str2.size() << endl;
    cout << str1 << endl;
    cout << str1.size() << endl;
    return 0;
}
