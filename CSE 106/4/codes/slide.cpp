#include <iostream>

template <typename Type>
class Binary_search_node {
public:
    Type node_value;
    Binary_search_node *left_tree;
    Binary_search_node *right_tree;

    Binary_search_node(Type const &value) : node_value(value), left_tree(nullptr), right_tree(nullptr) {}

    bool empty() const {
        return this == nullptr;
    }

    Type value() const {
        return node_value;
    }

    Binary_search_node* left() const {
        return left_tree;
    }

    Binary_search_node* right() const {
        return right_tree;
    }

    bool is_leaf() const {
        return left_tree == nullptr && right_tree == nullptr;
    }

    Type front() const {
        Binary_search_node *current = right_tree;
        while (current->left_tree != nullptr) {
            current = current->left_tree;
        }
        return current->node_value;
    }

    bool erase(Type const &obj, Binary_search_node *&ptr_to_this) {
        if (empty()) {
            return false;
        } else if (obj == value()) {
            if (is_leaf()) {
                ptr_to_this = nullptr;
                delete this;
            } else if (!left()->empty() && !right()->empty()) {
                node_value = right()->front();
                right()->erase(value(), right_tree);
            } else {
                ptr_to_this = (!left()->empty()) ? left() : right();
                delete this;
            }
            return true;
        } else if (obj < value()) {
            return left()->erase(obj, left_tree);
        } else {
            return right()->erase(obj, right_tree);
        }
    }

    void insert(Type const &obj) {
        if (obj < node_value) {
            if (left_tree == nullptr) {
                left_tree = new Binary_search_node(obj);
            } else {
                left_tree->insert(obj);
            }
        } else {
            if (right_tree == nullptr) {
                right_tree = new Binary_search_node(obj);
            } else {
                right_tree->insert(obj);
            }
        }
    }

    void in_order_traversal() const {
        if (left_tree != nullptr) {
            left_tree->in_order_traversal();
        }
        std::cout << node_value << " ";
        if (right_tree != nullptr) {
            right_tree->in_order_traversal();
        }
    }
};

int main() {
    Binary_search_node<int> *root = new Binary_search_node<int>(10);
    root->insert(5);
    root->insert(15);
    root->insert(3);
    root->insert(7);
    root->insert(12);
    root->insert(18);

    std::cout << "In-order traversal before deletion: ";
    root->in_order_traversal();
    std::cout << std::endl;

    int value_to_erase = 5;
    root->erase(value_to_erase, root);

    std::cout << "In-order traversal after deletion: ";
    root->in_order_traversal();
    std::cout << std::endl;

    delete root;
    return 0;
}
