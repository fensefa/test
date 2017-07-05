template<typename DataType>
struct RbTreeNode {
    enum NodeColor {
        BLACK = 0,
        RED
    };
    DataType data;
    RbTreeNode* left;
    RbTreeNode* right;
    RbTreeNode() {
        left = nullptr;
        right = nullptr;
    }
    RbTreeNode(DataType data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template<typename DataType, typename Compare = std::less<DataType>>
class RbTree {
public:
    RbTree() {
    }
    ~RbTree() {
        clear();
    }
    typedef RbTreeNode<DataType> NodeType;
    class Iterator {
    public:
        Iterator() {
            _cur_node = nullptr;
        }
        DataType& operator*() {
            return _cur_node->data;
        }
        DataType* operator->() {
            return &_cur_node->data;
        }
        Iterator operator++() {
            if (_cur_node->right) {
                _cur_node = _cur_node->right;
                while (_cur_node->left) {
                    _cur_node = _cur_node->left;
                }
            }
            return *this;
        }
        Iterator operator++(int) {
            Iterator res = *this;
            ++*this;
            return res;
        }
        bool operator==(const Iterator& other) {
            return (_cur_node == other._cur_node);
        }
        bool operator!=(const Iterator& other) {
            return !(*this == other);
        }
        friend class RbTree;
    private:
        NodeType* _cur_node;
    };
    // TODO 维护红黑树颜色要求
    void insert(DataType data) {
        if (_root.right == nullptr) {
            _root.right = new NodeType(data);
            return;
        }
        NodeType* ptr = _root.right;
        while (true) {
            if (Compare()(data, ptr->data)) {
                if (ptr->left != nullptr) {
                    ptr = ptr->left;
                    continue;
                }
                else {
                    ptr->left = new NodeType(data);
                    return;
                }
            }
            else if (Compare()(ptr->data, data)) {
                if (ptr->right != nullptr) {
                    ptr = ptr->right;
                    continue;
                }
                else {
                    ptr->right = new NodeType(data);
                    return;
                }
            }
            else {
                ptr->data = data;
                return;
            }
        }
    }
    // TODO
    void erase(Iterator& it) {
        ;
    }
    void clear() {
        _destroy_tree(_root.right);
        _root.right = nullptr;
    }
    Iterator find(DataType data) {
        NodeType* ptr = _root.right;
        while (ptr != nullptr) {
            if (Compare()(data, ptr->data)) {
                ptr = ptr->left;
            }
            else if (Compare()(ptr->data, data)) {
                ptr = ptr->right;
            }
            else {
                break;
            }
        }
        Iterator res;
        res._cur_node = ptr;
        return res;
    }
    Iterator begin() {
        NodeType* ptr = _root.right;
        while (ptr && ptr->left) {
            ptr = ptr->left;
        }
        Iterator res;
        res._cur_node = ptr;
        return res;
    }
    Iterator end() {
        Iterator res;
        return res;
    }
private:
    void _destroy_tree(NodeType* root) {
        if (root) {
            _destroy_tree(root->left);
            _destroy_tree(root->right);
            delete root;
        }
    }
    NodeType _root;
};
