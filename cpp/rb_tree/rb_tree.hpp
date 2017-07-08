template<typename DataType>
class RbTreeNode {
public:
    enum NodeColor {
        BLACK = 0,
        RED
    };
    DataType data;
    NodeColor color;
    RbTreeNode* parent;
    RbTreeNode* left;
    RbTreeNode* right;
    RbTreeNode() {
        left = nullptr;
        right = nullptr;
    }
    RbTreeNode(DataType data) {
        this->data = data;
        color = RED;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

template<typename K, typename V>
inline std::ostream& operator<<(std::ostream& output, std::pair<K,V> p) {
    output << "<" << p.first << ',' << p.second << ">";
    return output;
}
template<typename DataType>
void print_rb_tree(RbTreeNode<DataType>* root, int n = 0) {
    for (int i = 0; i < n; ++i) {
        std::cout << "=";
    }
    if (root == nullptr) {
        std::cout << "nullptr\n";
    }
    else {
        std::cout << root->data << ',' << root->color << std::endl;
        print_rb_tree(root->left, n + 1);
        print_rb_tree(root->right, n + 1);
    }
}

template<typename DataType, typename Compare = std::less<DataType>>
class RbTree {
public:
    RbTree() {
        _root = nullptr;
    }
    ~RbTree() {
        clear();
    }
    void print() {
        print_rb_tree(_root);
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
            else {
                while (_cur_node->parent != nullptr && _cur_node->parent->right == _cur_node) {
                    _cur_node = _cur_node->parent;
                }
                if (_cur_node->parent == nullptr) {
                    _cur_node = nullptr;
                }
                else {
                    _cur_node = _cur_node->parent;
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
    void insert(DataType data) {
        if (_root == nullptr) {
            _root = new NodeType(data);
            _root->color = NodeType::BLACK;
            _root->parent = nullptr;
            return;
        }
        NodeType* ptr = _root;
        while (true) {
            if (Compare()(data, ptr->data)) {
                if (ptr->left != nullptr) {
                    ptr = ptr->left;
                    continue;
                }
                else {
                    ptr->left = new NodeType(data);
                    ptr->left->parent = ptr;
                    ptr = ptr->left;
                    ptr->left = ptr->right = nullptr;
                    adjust(ptr);
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
                    ptr->right->parent = ptr;
                    ptr = ptr->right;
                    ptr->left = ptr->right = nullptr;
                    adjust(ptr);
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
        _destroy_tree(_root);
        _root= nullptr;
    }
    Iterator find(DataType data) {
        NodeType* ptr = _root;
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
        NodeType* ptr = _root;
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
    void adjust(NodeType* node) {
        while(true) {
            if (node == nullptr) {
                return;
            }
            if (node->parent == nullptr) {
                node->color = NodeType::BLACK;
                return;
            }
            if (node->color == NodeType::BLACK) {
                return;
            }
            if (node->parent->color == NodeType::BLACK) {
                return;
            }
            NodeType* uncle = get_uncle(node);
            if (uncle != nullptr && uncle->color == NodeType::RED) {
                uncle->color = NodeType::BLACK;
                node->parent->color = NodeType::BLACK;
                node->parent->parent->color = NodeType::RED;
                node = node->parent->parent;
                continue;
            }
            if (uncle == nullptr || uncle->color == NodeType::BLACK) {
                NodeType* grandpa = node->parent->parent;
                if (uncle == grandpa->right && node == node->parent->right) {
                    left_rotate(node->parent);
                }
                if (uncle == grandpa->left && node == node->parent->left) {
                    right_rotate(node->parent);
                }
                if (grandpa->left == uncle) {
                    node = left_rotate(grandpa);
                }
                else {
                    node = right_rotate(grandpa);
                }
                node->color = NodeType::RED;
                node->left->color = NodeType::BLACK;
                node->right->color = NodeType::BLACK;
                if (grandpa == _root) {
                    _root = node;
                }
                continue;
            }
        }
    }
    NodeType* get_uncle(NodeType* node) {
        if (node == nullptr || node->parent == nullptr || node->parent->parent == nullptr) {
            return nullptr;
        }
        if (node->parent->parent->left == node->parent) {
            return node->parent->parent->right;
        }
        else {
            return node->parent->parent->left;
        }
    }
    NodeType* right_rotate(NodeType* node) {
        NodeType* p_cur = node;
        NodeType* p_left = node->left;
        NodeType* p_parent = node->parent;
        p_cur->left = p_left->right;
        if (p_cur->left) {
            p_cur->left->parent = p_cur;
        }
        p_cur->parent = p_left;
        p_left->right = p_cur;
        p_left->parent = p_parent;
        if (p_parent && p_parent->right == p_cur) {
            p_parent->right = p_left;
        }
        else if (p_parent && p_parent->left == p_cur) {
            p_parent->left = p_left;
        }
        return p_left;
    }
    NodeType* left_rotate(NodeType* node) {
        NodeType* p_cur = node;
        NodeType* p_right = node->right;
        NodeType* p_parent = node->parent;
        p_cur->right = p_right->left;
        if (p_cur->right) {
            p_cur->right->parent = p_cur;
        }
        p_cur->parent = p_right;
        p_right->left = p_cur;
        p_right->parent = p_parent;
        if (p_parent && p_parent->left == p_cur) {
            p_parent->left = p_right;
        }
        else if (p_parent && p_parent->right == p_cur) {
            p_parent->right = p_right;
        }
        return p_right;
    }
    void _destroy_tree(NodeType* root) {
        if (root) {
            _destroy_tree(root->left);
            _destroy_tree(root->right);
            delete root;
        }
    }
    NodeType* _root;
};
