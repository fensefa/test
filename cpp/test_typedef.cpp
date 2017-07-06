#include <iostream>
using namespace std;

int fun1() {
    return 1;
}

int fun2() {
    return 2;
}

typedef int (*abc)();

typedef int INT;

int func(int n) {
    cout << "func()" << n << endl;
    return n;
}

template<typename T>
void func_test(int n) {
    static int a = func(n);
}

int main() {
    abc xx;
    xx = fun1;
    cout << xx() << endl;
    xx = fun2;
    cout << xx() << endl;
    func_test<int>(1);
    func_test<INT>(2);
    func_test<double>(3);
    func_test<unsigned int>(4);
    func_test<int32_t>(5);
    func_test<uint32_t>(6);
    func_test<int64_t>(7);
    func_test<uint64_t>(8);
}
