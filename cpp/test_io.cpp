#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int test(int (fun)(int, int)) {
    return fun(1,2);
}

int func(int a, int b) {
    return a + b;
}


int main() {
    uint64_t a;
    float b;
    vector<uint64_t> c;
    ifstream in("xxx", ios::in | ios::binary);
    int count = 0;
    while (in.read((char*)&a, 8) && in.read((char*)&b, 4)) {
        // cout << a << endl;
        c.push_back(a);
        if (++count % 10000 == 0) cout << count << endl;
    }
    sort(c.begin(), c.end());
    ofstream out("2");
    for (auto it = c.begin(); it != c.end(); ++it) {
        out << *it << endl;
    }
}
