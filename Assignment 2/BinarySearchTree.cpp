#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* insertRecursive(Node* current, int val) {
        if (current == NULL) {
            Node* newNode = new Node;
            newNode->data = val;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        } else if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        } else if (val > current->data) {
            current->right = insertRecursive(current->right, val);
        }
        return current;
    }
    
    Node* deleteRecursive(Node* current, int val) {
        if (current == NULL) {
            return NULL;
        } else if (val < current->data) {
            current->left = deleteRecursive(current->left, val);
        } else if (val > current->data) {
            current->right = deleteRecursive(current->right, val);
        } else {
            if (current->left == NULL && current->right == NULL) {
                delete current;
                return NULL;
            } else if (current->left == NULL) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                return temp;
            } else {
                Node* minNode = findMin(current->right);
                current->data = minNode->data;
                current->right = deleteRecursive(current->right, minNode->data);
            }
        }
        return current;
    }
    
    Node* findMin(Node* current) {
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }
    
public:
    BinarySearchTree() {
        root = NULL;
    }
    
    int min() {
        if (root == NULL) {
            cout << "Error: Tree is empty" << endl;
            return -1;
        }
        Node* current = root;
        while (current->left != NULL) {
            current = current->left;
        }
        return current->data;
    }
    
    int max() {
        if (root == NULL) {
            cout << "Error: Tree is empty" << endl;
            return -1;
        }
        Node* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->data;
    }
    
    bool contains(int val) {
        Node* current = root;
        while (current != NULL) {
            if (val < current->data) {
                current = current->left;
            } else if (val > current->data) {
                current = current->right;
            } else {
                return true;
            }
        }
        return false;
    }
    
    void insert(int val) {
        root = insertRecursive(root, val);
    }
    
    int remove(int val) {
        root = deleteRecursive(root, val);
        return val;
    }
};

int main() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    cout << "Min: " << tree.min() << endl;
    cout << "Max: " << tree.max() << endl;
    cout << "Contains 5: " << tree.contains(5) << endl;
    cout << "Contains 9: " << tree.contains(9) << endl;
    tree.remove(5);
    cout << "Contains 5: " << tree.contains(5) << endl;
    return 0;
}

