#include <iostream>
#include <vector>
#include <map>
#include "rb_tree.hpp"
#include "map.hpp"
using namespace std;

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
    abc::map<int, int> int_map;
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
    abc::map<string, string> str_map;
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

void test_maps() {
    abc::map<int, int> map1;
    std::map<int, int> map2;
    int n = 10;
    for (int i = 0; i < n; ++i) {
        map1.insert(i, i + 1);
    }
    map1.print();
    for (auto it = map1.begin(); it != map1.end(); ++it) {
        cout << "key: " << it->first << ", value: " << it->second << endl;
    }
    // return;
    n = 100000000;
    cout << "time: " << time(nullptr) << endl;
    for (int i = 0; i < n; ++i) {
        map1.insert(i, i + 1);
    }
    cout << "time: " << time(nullptr) << endl;
    for (int i = 0; i < n; ++i) {
        map2.emplace(i, i + 1);
    }

    cout << "time: " << time(nullptr) << endl;
    int sum1 = 0;
    for (auto it = map1.begin(); it != map1.end(); ++it) {
        sum1 += it->second;
        sum1 %= 1048923;
    }
    cout << "sum1: " << sum1 << endl;
    cout << "time: " << time(nullptr) << endl;
    int sum2 = 0;
    for (auto it = map2.begin(); it != map2.end(); ++it) {
        sum2 += it->second;
        sum2 %= 1048923;
    }
    cout << "sum2: " << sum2 << endl;
    cout << "time: " << time(nullptr) << endl;
}

int main() {
    test_rb_tree();
    test_map();
    test_maps();
    return 0;
}
