/*
    Title: Binary Search Tree (BST) Implementation in C++
    Author: Your Name
    Description:
        A simple and efficient implementation of a Binary Search Tree (BST)
        that supports insertion, searching, deletion, and tree traversals.

    Why it's useful:
        - Demonstrates core DSA concepts (recursion, tree traversal, pointers)
        - Beginner-friendly yet production-level structure
        - Ideal for Hacktoberfest contribution (clean, well-documented, readable)
*/

#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BST class with common operations
class BST {
private:
    Node* root;

    // Helper function to insert a value in BST
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node; // unchanged node pointer
    }

    // Helper function to search for a value
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

    // Find the minimum value node (used for deletion)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Inorder traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Preorder traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void displayInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

// Main function to test BST
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "=== Binary Search Tree Demo ===" << endl;
    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();

    cout << "\nSearching 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Deleting 20...\n";
    tree.deleteKey(20);
    tree.displayInorder();

    cout << "Deleting 30...\n";
    tree.deleteKey(30);
    tree.displayInorder();

    cout << "Deleting 50...\n";
    tree.deleteKey(50);
    tree.displayInorder();

    return 0;
}
