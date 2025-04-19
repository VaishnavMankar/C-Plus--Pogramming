//102. Binary Tree Level Order Traversl
//Binary tree using BSF

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int removal = q.size();
            vector<int> row;
            for (int i = 0; i < removal; i++) {
                TreeNode* n = q.front();
                q.pop();
                row.push_back(n->val);

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    // Creating an example binary tree:
    //        3
    //       / \
    //      9  20
    //        /  \
    //       15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Creating an instance of Solution class
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Printing the level order traversal
    cout << "Level order traversal:\n";
    for (const auto& level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    // Cleaning up the dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
