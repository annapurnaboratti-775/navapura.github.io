#include <iostream>
using namespace std;

struct Node {
    int id; // household/facility id
    string name;
    int usage; // water usage
    Node* left;
    Node* right;

    Node(int i, string n, int u) : id(i), name(n), usage(u), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id, string name, int usage) {
        if (!node) return new Node(id, name, usage);
        if (id < node->id) node->left = insert(node->left, id, name, usage);
        else if (id > node->id) node->right = insert(node->right, id, name, usage);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Usage: " << node->usage << endl;
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int id, string name, int usage) {
        root = insert(root, id, name, usage);
    }

    void printBST() {
        cout << "Household/Facility Data (Inorder Traversal):\n";
        inorder(root);
    }
};

int main() {
    BST bst;
    bst.insert(3, "Household3", 50);
    bst.insert(1, "Household1", 30);
    bst.insert(4, "Facility4", 70);
    bst.insert(2, "Household2", 40);

    bst.printBST();

    return 0;
}

