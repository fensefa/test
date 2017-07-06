#include <iostream>
using namespace std;
#include <vector>
#include "rb_tree.hpp"
#include "map.hpp"

void test_rb_tree() {
    RbTree<int> int_tree;
    vector<int> p1 = {
        9, 5, 2, 3, 4
    };
    vector<int> p2 = {
        1, 2, 3, 4, 5
    };
    for (auto n : p1) {
        int_tree.insert(n);
    }
    for (auto n : p2) {
        auto it = int_tree.find(n);
        cout << n;
        cout << " : ";
        bool abc = (it == int_tree.end());
        cout << abc;
        cout << endl;
    }
}
void test_map() {
    map<int, int> int_map;
    int_map.insert(2, 3);
    int_map.insert(3, 5);
    int p1[] = {
        1, 2, 3, 4
    };
    for (auto n : p1) {
        auto it = int_map.find(n);
        if (it == int_map.end()) {
            cout << "not found " << n << endl;
        }
        else {
            cout << "found " << n << ' ' << it->second << endl;
        }
    }
    map<string, string> str_map;
    str_map.insert("abc", "hello");
    str_map.insert("w2", "world");
    string p2[] = {
        "abc", "hello", "w2", "world"
    };
    for (auto n : p2) {
        auto it = str_map.find(n);
        if (it == str_map.end()) {
            cout << "not found " << n << endl;
        }
        else {
            cout << "found " << n << ' ' << it->second << endl;
        }
    }
}

int main() {
    test_rb_tree();
    test_map();
    return 0;
}
