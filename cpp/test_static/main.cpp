#include <iostream>
#include "1.h"
using namespace std;

int test() {
    cout << "test()\n";
    A::fun();
    return 0;
}
int y = test();

int main() {
    int x = 0x31323334;
    int *p = &x;
    char *ch = (char*)p;
    cout << ch[0] << ch[1] << ch[2] << ch[3];
    cout << "main()\n";
    A::fun();
}
