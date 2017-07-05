#include <map>

using namespace std;

class A {
private:
    A();
    static A _instance;
    map<int, int> test_map;
public:
    static A& get_instance();
    static void fun();
};

