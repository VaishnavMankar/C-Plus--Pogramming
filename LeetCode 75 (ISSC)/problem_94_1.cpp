//94. Binary Tree Inorder Traversal
// Binary Tree

#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

// Function to create a sample binary tree
TreeNode* createExampleTree() {
    return new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
}

// Function to print the traversal result
void printTraversal(const vector<int>& traversal) {
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating example test tree
    TreeNode* exampleTree = createExampleTree();

    Solution solution;

    // Running inorder traversal
    vector<int> result = solution.inorderTraversal(exampleTree);

    // Printing the result
    cout << "Inorder Traversal: ";
    printTraversal(result);

    // Cleanup dynamically allocated memory
    delete exampleTree->right->left;
    delete exampleTree->right;
    delete exampleTree;

    return 0;
}
