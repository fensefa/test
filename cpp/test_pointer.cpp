#include <iostream>

using namespace std;

int main() {
    // int *& a;
    // int &* b;
    int n = 3;
    int m = 4;
    int *p = &n;
    int *q = &m;
    *p = 3;
    int *& c = p;
    // cout << *p << endl;
    int &d = *p;
    p = &m;
    *p = 5;
    n = 6;
    cout << d << endl;
    // int &e = 3;
    const int &f = 3;
    const int &g = n;
    n = 7;
    cout << g << endl;
    int const * p1 = &m;
    const int * p2 = &m;
    int * const p3 = &m;
    return 0;
}
