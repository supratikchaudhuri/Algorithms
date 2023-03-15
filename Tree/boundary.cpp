class Solution {
    vector<int> ans, right;
    void dfs(TreeNode *node, int state) { // 1 left boundary, 2 right boundary, 0 otherwise
        if (!node) return;
        if (state == 1) ans.push_back(node->val);
        else if (state == 2) right.push_back(node->val);
        else if (!node->left && !node->right) ans.push_back(node->val);
        dfs(node->left, state == 1 ? 1 : (state == 2 && !node->right ? 2 : 0));
        dfs(node->right, state == 2 ? 2 : (state == 1 && !node->left ? 1 : 0));
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.push_back(root->val);
        dfs(root->left, 1);
        dfs(root->right, 2);
        for (int i = right.size() - 1; i >= 0; --i) ans.push_back(right[i]);
        return ans;
    }
};