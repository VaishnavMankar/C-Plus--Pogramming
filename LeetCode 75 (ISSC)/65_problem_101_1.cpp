//101. Symmertic Tree
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
    // Helper function to check if two trees are mirror images of each other
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true; // Both nodes are null, meaning they are symmetric
        }
        if (!t1 || !t2 || t1->val != t2->val) {
            return false; // If only one is null or values don't match, not symmetric
        }
        
        // Recursively check if left subtree of t1 is a mirror of right subtree of t2, and vice versa
        bool left = isMirror(t1->left, t2->right);
        bool right = isMirror(t1->right,t2->left);

        return left && right;
    }

    // Function to check if a tree is symmetric
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};

// Function to create a sample symmetric tree
TreeNode* createSymmetricTree() {
    return new TreeNode(1, 
            new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
            new TreeNode(2, new TreeNode(4), new TreeNode(3))
    );
}

// Function to create a sample asymmetric tree
TreeNode* createAsymmetricTree() {
    return new TreeNode(1, 
            new TreeNode(2, nullptr, new TreeNode(3)), 
            new TreeNode(2, nullptr, new TreeNode(3))
    );
}

int main() {
    // Create test cases
    TreeNode* symmetricTree = createSymmetricTree();
    TreeNode* asymmetricTree = createAsymmetricTree();

    Solution solution;

    // Check if trees are symmetric
    cout << "Is symmetricTree symmetric? " << (solution.isSymmetric(symmetricTree) ? "Yes" : "No") << endl;
    cout << "Is asymmetricTree symmetric? " << (solution.isSymmetric(asymmetricTree) ? "Yes" : "No") << endl;

    // Cleanup dynamically allocated memory
    delete symmetricTree->left->left;
    delete symmetricTree->left->right;
    delete symmetricTree->right->left;
    delete symmetricTree->right->right;
    delete symmetricTree->left;
    delete symmetricTree->right;
    delete symmetricTree;

    delete asymmetricTree->left->right;
    delete asymmetricTree->right->right;
    delete asymmetricTree->left;
    delete asymmetricTree->right;
    delete asymmetricTree;

    return 0;
}
