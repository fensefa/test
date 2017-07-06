class A {
public:
    virtual void xx() = 0;
    int a_pub;
protected:
    int a_pro;
private:
    int a_pri;
};

class B : public A {
public:
    void xx() {
        ;
    }
    void fun(B b2) {
        b2.a_pub;
        b2.a_pro;
        // b2.a_pri;
    }
};

class C : public B {
public:
    void fun2(B b2) {
        b2.a_pub;
        b2.a_pro;
        // c2.a_pri;
    }
};

int main() {
    return 0;
}
