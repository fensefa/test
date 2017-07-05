#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

typedef int* INT1;
#define INT2 int*

class test_const {
    int a;
    int *p1 = new int[3];
    int p2[2];
    int& fun() const {
        // a = 3;
        p1[1] = 2;
        // p2[1] = 3;

        // return a;
        // return p2[1];
        return p1[1];
    }
    int print() {
        fun() = 4;
        cout << "test_const.p[1]: " << p1[1] << endl;
    }
    int x = print();
};

class test_const2 {
    public:
    int a;
    void fun() const {
    }
    void fun2() {
    }
};

int test1() {
    test_const2 abc1;
    const test_const2 abc = abc1;
    abc.fun();
    // abc.fun2();
}

int main() {
    // vector<const int> vci;
    vector<int> vi;
    const int *p = new int();
    delete p;
    int a = 3;
    // const int b;
    const int c = a;
    cout << "c: " << c << endl;
    pair<const int, const int> pcci;
    map<const int, const int> mcci;
    // unordered_map<const int, int> umcci;
    // unordered_map<const int, const int> umcci;
    unordered_map<int, const int> umcci;
    umcci.emplace(1,2);
    umcci[2];
    // umcci[1] = 2;
    cout << "umcci size: " << umcci.size() << endl;
    int const x = 3;
    const int y = 4;
    cout << "x + y: " << x + y << endl;
    // x = y;
    // y = x;
    int *pi = new int(2);
    int a11 = 0, a12 = 0, a21 = 0, a22 = 0;
    const INT1 pint11 = &a11;
    INT1 const pint12 = &a12;
    const INT2 pint21 = &a21;
    INT2 const pint22 = &a22;
    // pint11 = pi;
    // pint12 = pi;
    pint21 = pi;
    // pint22 = pi;
    *pint11 = 3;
    *pint12 = 3;
    // *pint21 = 3;
    *pint22 = 3;
    int aa = 5;
    const int& bb = aa;
    // bb = 3;

    test_const xx;
}
