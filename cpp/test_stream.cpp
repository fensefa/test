#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename Type>
inline ostream& operator<<(ostream& output, const vector<Type>& data_vec) {
    for (const auto& data : data_vec) {
        output << data << endl;
    }
    return output;
}

template<typename KeyType, typename ValueType>
inline ostream& operator<<(ostream& output, const map<KeyType, ValueType>& data_map) {
    for (const auto& data : data_map) {
        output << data.first << " : " << data.second << endl;
    }
    return output;
}

int main() {
    vector<int> vi = {
        1, 3, 8, 9, 23, 7
    };
    map<int, int> mi = {
        {1, 3},
        {4, 3},
        {7, 3},
    };
    cout << vi << endl;
    cout << mi << endl;
    return 0;
}
