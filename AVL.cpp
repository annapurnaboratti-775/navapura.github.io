#include <iostream>
using namespace std;

struct Node {
    int temp;        // temperature value
    int height;
    Node* left;
    Node* right;

    Node(int t) : temp(t), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int temp) {
    if (!node) return new Node(temp);

    if (temp < node->temp)
        node->left = insert(node->left, temp);
    else if (temp > node->temp)
        node->right = insert(node->right, temp);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Rotations
    if (balance > 1 && temp < node->left->temp)
        return rightRotate(node);
    if (balance < -1 && temp > node->right->temp)
        return leftRotate(node);
    if (balance > 1 && temp > node->left->temp) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && temp < node->right->temp) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->temp << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 35);
    root = insert(root, 42);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "AVL Tree (Temperature Data in °C): ";
    inorder(root);
    return 0;
}
