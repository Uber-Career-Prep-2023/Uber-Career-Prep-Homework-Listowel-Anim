#include <iostream>
using namespace std;

//Time Complexity: O(h)
//Space Complexity: O(1)
//Time Spent: 16 minutes
//Technique Used: Depth First Search Traversal (In Order)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int floor(TreeNode* root, int target) {
        int result = INT_MIN;
        while (root != nullptr) {
            if (root->val == target) {
                return target;
            } else if (root->val > target) {
                root = root->left;
            } else {
                result = root->val;
                root = root->right;
            }
        }
        return result;
    }
};

int main() {
    // Test case 1: target exists in the tree
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(12);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(6);
    root1->right->left = new TreeNode(10);
    root1->right->right = new TreeNode(14);
    Solution sol;
    int result1 = sol.floor(root1, 5);
    cout << "Floor of 5 in tree 1: " << result1 << endl; // Output: 4

    // Test case 2: target is less than all nodes in the tree
    TreeNode* root2 = new TreeNode(8);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(12);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(6);
    root2->right->left = new TreeNode(10);
    root2->right->right = new TreeNode(14);
    int result2 = sol.floor(root2, 1);
    cout << "Floor of 1 in tree 2: " << result2 << endl; // Output: INT_MIN

    // Test case 3: target is greater than all nodes in the tree
    TreeNode* root3 = new TreeNode(8);
    root3->left = new TreeNode(4);
    root3->right = new TreeNode(12);
    root3->left->left = new TreeNode(2);
    root3->left->right = new TreeNode(6);
    root3->right->left = new TreeNode(10);
    root3->right->right = new TreeNode(14);
    int result3 = sol.floor(root3, 20);
    cout << "Floor of 20 in tree 3: " << result3 << endl; // Output: 14

}
