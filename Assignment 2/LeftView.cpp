#include <iostream>
#include <vector>
#include <queue>

//Space Complexity: O(1)
//Time Complexity: O(n)
//Time Spent: 14 minutes
//Technique used: Breadth First Search Traversal
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) { // first node in this level
                    result.push_back(node->val);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return result;
    }
};

int main() {
    // Test case 1: full binary tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);
    Solution sol;
    vector<int> result1 = sol.leftView(root1);
    cout << "Left view of tree 1: ";
    for (int x : result1) {
        cout << x << " ";
    }
    cout << endl; // Output: 1 2 4

    // Test case 2: single node tree
    TreeNode* root2 = new TreeNode(1);
    vector<int> result2 = sol.leftView(root2);
    cout << "Left view of tree 2: ";
    for (int x : result2) {
        cout << x << " ";
    }
    cout << endl; // Output: 1

    // Test case 3: empty tree
    TreeNode* root3 = nullptr;
    vector<int> result3 = sol.leftView(root3);
    cout << "Left view of tree 3: ";
    for (int x : result3) {
        cout << x << " ";
    }
    cout << endl; // Output:

    return 0;
}
