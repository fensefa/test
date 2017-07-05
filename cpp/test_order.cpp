#include <iostream>
using namespace std;

class order {
    order() {
        cout << "construct of order\n";
    }
    ~order() {
        cout << "destruct of order\n";
    }
}

order o;

int main() {
    cout << "hello, world\n";
}
