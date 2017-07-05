#include <iostream>
using namespace std;

int print(int n) {
    cout << "func print: " << n << endl;
    return n;
}

static int x = print(8);

void func_test() {
    static int y = print(1);
}

class class_print {
public:
    class_print() {
        cout << "class_print" << endl;
    }
    int x = rand();
};

class class_test {
public:
    static class_print cp;
    int z;
};

class_print class_test::cp;

int main() {
    func_test();
    func_test();
    func_test();
    func_test();

    class_print p1;
    
    class_test c1;
    class_test c2;
    class_test c3;
    class_test c4;
    cout << class_test::cp.x;
    /*
    */
    return 0;
}
