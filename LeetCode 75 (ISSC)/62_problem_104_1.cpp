// 104. Maximum Depth of Binary Tree
// Binary Tree
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        return max(lDepth, rDepth) + 1;
    }
};

int main() {
    // Construct a sample binary tree:
    //         3
    //        / \
    //       9  20
    //          /  \
    //         15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int depth = sol.maxDepth(root);

    // Output the maximum depth of the binary tree
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    // Free allocated memory (Important in real-world usage)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
