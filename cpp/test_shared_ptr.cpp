#include <iostream>
#include <memory>
using namespace std;

int abc_n = 0;

class abc {
public:
    abc() {
        n = abc_n++;
        cout << "construct of abc " << n << endl;
        p = new int();
    }
    ~abc() {
        cout << "disctruct of abc " << n << endl;
        delete p;
    }
    int n;
    int data;
    int *p;
};

// I don't understand the output of this function!
void test1() {
    cout << "========================test1=====================\n";
    shared_ptr<abc> p_abc(new abc());
    abc *p2 = new abc();
    p2->data = 2;
    shared_ptr<abc> p_abc5(p2);
    shared_ptr<abc> p_abc6(p2);
    cout << "p_abc6: " << p_abc6->data << endl;
    p_abc5->data = 5;
    cout << "p_abc6: " << p_abc6->data << endl;
}

// this will cause core dump
void test2() {
    cout << "========================test2=====================\n";
    int n = 3;
    shared_ptr<int> pi(&n);
}

void test3() {
    cout << "========================test3=====================\n";
    shared_ptr<int> p_int(new int());
    shared_ptr<int> p_int2(new int());
    *p_int = 3;
    p_int2 = p_int;
    *p_int2 = 2;
    shared_ptr<const int> p_const_int = p_int;
    // *p_const_int = 4;
    p_const_int = p_int2;
    const shared_ptr<int> const_p_int = p_int;
    // const_p_int = p_int2;
    *const_p_int = 5;
}

// this will cause core dump;
void test4() {
    cout << "========================test4=====================\n";
    abc *p2 = new abc[1];
    shared_ptr<abc> p_abc5(p2);
    shared_ptr<abc> p_abc6(p2);
}

int main() {
    test1();
    // test2();
    test3();
    test4();
    cout << "end\n";
}
