// 100. Same Tree
//Binary Tree
//Using BSF
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
    
    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with a value and left and right children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            q1.pop();
            TreeNode* t2 = q2.front();
            q2.pop();

            // If both nodes are null, continue checking
            if (!t1 && !t2)
                continue;

            // If only one is null or values don't match, return false
            if (!t1 || !t2 || (t1->val != t2->val))
                return false;

            // Push left and right children into queues
            q1.push(t1->left);
            q1.push(t1->right);
            q2.push(t2->left);
            q2.push(t2->right);
        }
        
        // If both queues are empty, trees are identical
        return q1.empty() && q2.empty();
    }
};

int main() {
    // Constructing two example binary trees
    TreeNode* tree1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* tree2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    
    // Creating an instance of Solution
    Solution solution;
    
    // Checking if the two trees are identical
    bool result = solution.isSameTree(tree1, tree2);
    
    // Output the result
    cout << "Are the two trees the same? " << (result ? "Yes" : "No") << endl;
    
    // Cleanup dynamically allocated memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
