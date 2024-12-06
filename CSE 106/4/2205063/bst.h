#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

Node *insertNode(Node *node, int val)
{
    if (node == nullptr)
    {
        return new Node(val);
    }
    if (val < node->val)
        node->left = insertNode(node->left, val);
    else
        node->right = insertNode(node->right, val);
    return node;
}

Node *minValNode(Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *node, int val)
{
    if (node == nullptr)
        return node;
    if (val < node->val)
        node->left = deleteNode(node->left, val);
    else if (val > node->val)
        node->right = deleteNode(node->right, val);
    else
    {
        if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        Node *temp = minValNode(node->right);
        node->val = temp->val;
        node->right = deleteNode(node->right, temp->val);
    }
    return node;
}

Node *find(Node *node, int val)
{
    if (node == nullptr || node->val == val)
        return node;
    if (val < node->val)
        return find(node->left, val);
    return find(node->right, val);
}

void inOrder(Node *node)
{
    if (node != nullptr)
    {
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }
}

void preOrder(Node *node)
{
    if (node != nullptr)
    {
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    if (node != nullptr)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }
}

void printTree(Node *root)
{
    if (root != nullptr)
    {
        cout << root->val;
        if (root->left || root->right)
        {
            cout << " (";
            if (root->left)
            {
                printTree(root->left);
            }
            else
            {
                cout << "_";
            }
            cout << ", ";
            if (root->right)
            {
                printTree(root->right);
            }
            else
            {
                cout << "_";
            }
            cout << ")";
        }
    }
}
