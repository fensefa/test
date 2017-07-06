#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_func(int a, int b) {
    return a % 2 == 0;
}

struct cmp_class {
    cmp_class() {
        cout << "cmp_class()\n";
    }
    bool operator()(int a, int b) {
        ++c;
        cout << "c = " << c << endl;
        return a % 2 == 0;
    }
    int c = 0;
};

int main() {
    vector<int> v1 = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0
    };
    vector<int> v2 = v1;
    vector<int> v3 = v1;
    sort(v1.begin(), v1.end(), cmp_func);
    sort(v2.begin(), v2.end(), cmp_class());
    cmp_class abc;
    sort(v3.begin(), v3.end(), abc);
    cout << cmp_class()(1, 2) << endl;
    cout << abc(2, 1) << endl;
    return 0;
}
