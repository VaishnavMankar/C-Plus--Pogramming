//103. Binary tree Zigzag Level order Traversal
//Tree
//Queue

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : (size - 1 - i);
            row[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(row);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal: \n";
    for (const auto& level : result) {
        cout << "[ ";
        for (int num : level) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    // Clean up memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
