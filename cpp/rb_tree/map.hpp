template<typename KeyType, typename ValueType>
class map {
private:
    struct Compare {
        bool operator() (const std::pair<KeyType, ValueType>& p1, const std::pair<KeyType, ValueType>& p2) {
            return p1.first < p2.first;
        }
    };
public:
    typedef typename RbTree<std::pair<KeyType, ValueType>, Compare>::Iterator iterator;
    iterator find(const KeyType& key) {
        std::pair<KeyType, ValueType> tmp_pair;
        tmp_pair.first = key;
        return _rb_tree.find(tmp_pair);
    }
    iterator begin() {
        return _rb_tree.begin();
    }
    iterator end() {
        return _rb_tree.end();
    }
    void insert(const KeyType& key, const ValueType& value) {
        std::pair<KeyType, ValueType> tmp_pair = std::make_pair(key, value);
        _rb_tree.insert(tmp_pair);
    }
private:
    static bool compare(const std::pair<KeyType, ValueType>& p1, const std::pair<KeyType, ValueType>& p2) {
        return p1.first < p2.first;
    }
    RbTree<std::pair<KeyType, ValueType>, Compare> _rb_tree;
};
