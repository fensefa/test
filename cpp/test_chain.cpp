#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChainNode {
public:
    ChainNode() {
        _next_chain = nullptr;
    }
    virtual ~ChainNode() = default;
    void call_next() {
        if (_next_chain != nullptr) {
            _next_chain->work();
        }
    }
    void set_next(ChainNode* next_chain) {
        _next_chain = next_chain;
    }
    ChainNode* get_next() {
        return _next_chain;
    }
    virtual void work() = 0;
private:
    ChainNode* _next_chain;
};

class HelloWorld : public ChainNode {
public:
    void work() {
        cout << "hello, world\n";
        call_next();
    }
};

class Test : public ChainNode {
public:
    void work() {
        call_next();
        cout << "hello, test\n";
    }
};

class ChainFactory {
public:
    static ChainNode* get_chain_node(const string& chain_type) {
        if (chain_type == "HelloWorld") {
            return new HelloWorld();
        }
        if (chain_type == "Test") {
            return new Test();
        }
        return nullptr;
    }
};

class Chain {
public:
    Chain() {
        _head = nullptr;
    }
    ~Chain() {
        clear();
    }
    int set_chain(const vector<string>& chain_list) {
        clear();
        for (auto it = chain_list.rbegin(); it != chain_list.rend(); ++it) {
            ChainNode* tmp_node = ChainFactory::get_chain_node(*it);
            if (tmp_node != nullptr) {
                tmp_node->set_next(_head);
                _head = tmp_node;
            }
            else {
                clear();
                return -1;
            }
        }
        return 0;
    }
    void clear() {
        while(_head != nullptr) {
            ChainNode* tmp_node = _head;
            _head = _head->get_next();
            delete tmp_node;
        }
    }
    void work() {
        if (_head != nullptr) {
            _head->work();
        }
    }
private:
    ChainNode* _head;
};

int main() {
    ChainNode* h1 = new HelloWorld();
    ChainNode* h2 = new HelloWorld();
    ChainNode* t1 = new Test();
    h1->set_next(t1);
    t1->set_next(h2);
    h1->work();

    Chain chain;
    chain.set_chain({"Test","HelloWorld","Test"});
    chain.work();
}
