#include <iostream>
using namespace std;

int main() {
    int *p = new int[3];
    cout << "ok0\n";
    auto it = p;
    cout << "ok1\n";
    p = NULL;
    auto it2 = p;
    cout << "ok2\n";
}
