//112. Path Sum
//Binary Tree

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with a value and left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to check if there exists a root-to-leaf path with a given sum
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false; // If the root is null, there is no path
        }
        if (!root->left && !root->right) {
            return (targetSum == root->val); // If it's a leaf node, check if sum matches
        }
        
        // Check if either left or right subtree has a valid path sum
        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};

// Function to create a sample tree
TreeNode* createExampleTree() {
    return new TreeNode(5, 
            new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
            new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1)))
    );
}

int main() {
    // Create test cases
    TreeNode* exampleTree = createExampleTree();
    int targetSum1 = 22; // Example where path exists
    int targetSum2 = 27; // Example where path does not exist

    Solution solution;

    // Check if paths exist
    cout << "Does a path with sum " << targetSum1 << " exist? " << (solution.hasPathSum(exampleTree, targetSum1) ? "Yes" : "No") << endl;
    cout << "Does a path with sum " << targetSum2 << " exist? " << (solution.hasPathSum(exampleTree, targetSum2) ? "Yes" : "No") << endl;

    // Cleanup dynamically allocated memory
    delete exampleTree->left->left->left;
    delete exampleTree->left->left->right;
    delete exampleTree->left->left;
    delete exampleTree->left;
    delete exampleTree->right->left;
    delete exampleTree->right->right->right;
    delete exampleTree->right->right;
    delete exampleTree->right;
    delete exampleTree;

    return 0;
}
