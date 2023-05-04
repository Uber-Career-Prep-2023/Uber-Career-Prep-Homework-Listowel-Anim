//Time complexity: O(n) 
//Space complexity: O(n) 
//Methods used: Breadth first tree traversal (Insert method) and Depth first traversal (Copy Recursive Method)
#include <iostream>
#include <unordered_map>

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

    Node* copyRecursive(Node* node, unordered_map<Node*, Node*>& map) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(node->data);
        map[node] = newNode;
        newNode->left = copyRecursive(node->left, map);
        newNode->right = copyRecursive(node->right, map);
        return newNode;
    }

public:
    BinaryTree() : root(nullptr) {}

    Node* copy() {
        unordered_map<Node*, Node*> map;
        return copyRecursive(root, map);
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
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    Node* copy = tree.copy();

    cout << "Original tree: " << endl;
    cout << tree.root->data << endl;
    cout << tree.root->left->data << " " << tree.root->right->data << endl;
    cout << tree.root->left->left->data << " " << tree.root->left->right->data << " " << tree.root->right->left->data << endl;

    cout << "Copied tree: " << endl;
    cout << copy->data << endl;
    cout << copy->left->data << " " << copy->right->data << endl;
    cout << copy->left->left->data << " " << copy->left->right->data << " " << copy->right->left->data << endl;

    return 0;
}


//Test cases:
//Insert nodes into the original tree, create a deep copy and verify that the copy is identical to the original. 
//Insert nodes into the original tree, create a deep copy and modify one of the nodes in the copy. Verify that the original tree is unchanged.
