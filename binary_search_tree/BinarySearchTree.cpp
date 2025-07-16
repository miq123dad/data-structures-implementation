#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// BST class
class BST {
private:
    // Create a new node
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Recursive insert
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return createNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        // Duplicates are ignored

        return node;
    }

    // Recursive search
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        else if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Inorder traversal (L, Root, R)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Find minimum value
    int findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node->data;
    }

    // Find maximum value
    int findMax(Node* node) {
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }

    // Recursive delete
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                int minVal = findMin(root->right);
                root->data = minVal;
                root->right = deleteNode(root->right, minVal);
            }
        }
        return root;
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void inorderTraversal() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printMinMax() {
        if (root == nullptr)
            cout << "Tree is empty"<<endl;
        else {
            cout << "Min: " << findMin(root) <<endl;
            cout << "Max: " << findMax(root) <<endl;
        }
    }
};
