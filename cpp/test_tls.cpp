#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/tss.hpp>   // thread_specific_ptr

using namespace std;
/*
class B {
public:
    B() {
        cout << "B()\n";
    }
};
class A {
public:
    A(int n) {
        cout << "A(int) with n =" << n << "\n";
    }
    ~A() {
        cout << "~A()\n";
    }
private:
    static B b;
};
B A::b;
void fun() {
    static A a(3);
    boost::thread_specific_ptr<int> pi;
    pi.reset(new int(8));
}
boost::thread_specific_ptr<A> tls_a;
boost::shared_ptr<A> sh_a;
void* fun2(void*) {
    // static A a;
    for(int i = 0; i < 1000; ++i) {
        if (tls_a.get() == nullptr) {
            tls_a.reset(new A(1));
        }
    }
    for(int i = 0; i < 1000; ++i) {
        if (sh_a.get() == nullptr) {
            sh_a.reset(new A(2));
        }
    }
    return (void*)0;
}
void* fun3(void* tls) {
    // static A a;
    boost::thread_specific_ptr<A> tls_b = *(boost::thread_specific_ptr<A>*)tls;
    for(int i = 0; i < 1000; ++i) {
        if (tls_b->get() == nullptr) {
            tls_b->reset(new A(3));
        }
    }
    return (void*)0;
}
*/

static __thread int a;
int b = ++a;

void* fun4(void*) {
    ++a;
    cout << a << endl;
    return (void*)0;
}

int main() {
    a = 8;
    ++a;
    pthread_t th[2];
    pthread_create(th, NULL, fun4, NULL);
    pthread_create(th + 1, NULL, fun4, NULL);
    pthread_join(th[0], NULL);
    pthread_join(th[1], NULL);
    return 0;
}
