#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

void func(int a, int b, int c) {
    cout << a * 100 + b * 10 + c << endl;
}

int main() {
    auto fun1 = bind(func, _1, _2, _2);
    fun1(5,8);
}
