//111. Minimum Depth of Binary Tree
//Binary Tree

#include <iostream>
#include <queue>

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
    // Function to find the minimum depth of the binary tree
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0; // If the tree is empty, return 0
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1}); // Initialize the queue with the root node and depth 1

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            // If the node is a leaf, return the depth
            if (!node->left && !node->right) {
                return depth;
            }

            // Push left child if it exists
            if (node->left) {
                q.push({node->left, depth + 1});
            }
            // Push right child if it exists
            if (node->right) {
                q.push({node->right, depth + 1});
            }
        }
        return 0;
    }
};

int main() {
    // Example 1: Creating a binary tree [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    // Example 2: Creating a binary tree [2,null,3,null,4,null,5,null,6]
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->right = new TreeNode(5);
    root2->right->right->right->right = new TreeNode(6);

    // Creating a Solution object
    Solution sol;
    
    // Finding and printing the minimum depth of the example trees
    cout << "Minimum depth of Tree 1: " << sol.minDepth(root1) << endl; // Expected output: 2
    cout << "Minimum depth of Tree 2: " << sol.minDepth(root2) << endl; // Expected output: 5

    // Freeing allocated memory
    delete root1->left;
    delete root1->right->left;
    delete root1->right->right;
    delete root1->right;
    delete root1;

    delete root2->right->right->right->right;
    delete root2->right->right->right;
    delete root2->right->right;
    delete root2->right;
    delete root2;

    return 0;
}
