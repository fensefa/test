#include <iostream>

#include "1.h"

using namespace std;

A A::_instance;

A::A() {
    cout << "A::A()\n";
}

A& A::get_instance() {
    cout << "A::get_instance()\n";
    return A::_instance;
    // static A instance;
    // return instance;
}

void A::fun() {
    cout << "A::fun()\n";
    get_instance().test_map[1];
}
