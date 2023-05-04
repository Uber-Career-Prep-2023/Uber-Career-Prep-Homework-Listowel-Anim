#include <iostream>
#include <climits>

//Time Complexity: O(n)
//Space Complexity: O(n)
//Time Spent: 18 minutes
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    bool isBSTRecursive(Node* node, int minValue, int maxValue) {
        if (node == nullptr) {
            return true;
        }
        if (node->data < minValue || node->data > maxValue) {
            return false;
        }
        return isBSTRecursive(node->left, minValue, node->data - 1) &&
               isBSTRecursive(node->right, node->data + 1, maxValue);
    }

public:
    BinaryTree() : root(nullptr) {}

    bool isBST() {
        return isBSTRecursive(root, INT_MIN, INT_MAX);
    }

    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->left == nullptr) {
                node->left = new Node(val);
                return;
            }
            if (node->right == nullptr) {
                node->right = new Node(val);
                return;
            }
            q.push(node->left);
            q.push(node->right);
        }
    }
};

int main() {
    BinaryTree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    BinaryTree notBST;
    notBST.root = new Node(5);
    notBST.root->left = new Node(1);
    notBST.root->right = new Node(4);
    notBST.root->right->left = new Node(3);
    notBST.root->right->right = new Node(6);

    cout << "bst is BST? " << bst.isBST() << endl;
    cout << "notBST is BST? " << notBST.isBST() << endl;

    return 0;
}

