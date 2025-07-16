#include <iostream>
using namespace std;

// Binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Binary Tree class
class BinaryTree {
public:
    Node* root;

    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Create a new node
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // Insert a value into the tree (recursive)
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return createNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node == nullptr) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Search for a value in the tree
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find minimum value in the tree
    int findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node->data;
    }

    // Find maximum value in the tree
    int findMax(Node* node) {
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }

    // Find height of the tree
    int height(Node* node) {
        if (node == nullptr)
            return -1;

        int leftH = height(node->left);
        int rightH = height(node->right);
        return 1 + max(leftH, rightH);
    }
};

// Main function to test
int main() {
    BinaryTree bt;

    // Insert nodes
    bt.root = bt.insert(bt.root, 10);
    bt.insert(bt.root, 5);
    bt.insert(bt.root, 15);
    bt.insert(bt.root, 2);
    bt.insert(bt.root, 7);

    cout << "Inorder: ";
    bt.inorder(bt.root);  
    cout << endl;

    cout << "Preorder: ";
    bt.preorder(bt.root); 
    cout << endl;

    cout << "Postorder: ";
    bt.postorder(bt.root); 
    cout << endl;

    cout << "Search 7: " << (bt.search(bt.root, 7) ? "Found" : "Not Found") << endl;
    cout << "Minimum value: " << bt.findMin(bt.root) << endl;
    cout << "Maximum value: " << bt.findMax(bt.root) << endl;
    cout << "Height of tree: " << bt.height(bt.root) << endl;

    return 0;
}
