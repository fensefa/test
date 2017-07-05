#include <iostream>

using namespace std;

struct data {
    uint64_t key;
    float value;
};

int main() {
    cout << sizeof(data) << endl;
}
