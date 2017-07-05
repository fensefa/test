#include<iostream>
using namespace std;

int main() {
    hash<int> int_hash;
    for (int i = -1; i < 10000000; i *= 3) {
        cout << i << "," << int_hash(i) << endl;
    }
    return 0;
}
