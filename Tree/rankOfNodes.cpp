class Solution {
    
    vector<int> dfs(TreeNode* root, unordered_map<int, int>& map) {
        
        if(!root) return {0, 0}; //[left subtree node count, total node count]
        
        vector<int> left_side = dfs(root->left, map);
        vector<int> right_side = dfs(root->right, map);
        
        map[root->val] = left_side[1] + 1;
        
        return {left_side[1] + 1, left_side[1] + right_side[1] + 1};
    }
    
public:
    TreeNode* rank(TreeNode* root) {
        unordered_map<int, int> map;
        
        dfs(root, map);
        
        for(auto it : map)
            cout<<it.first<<"  "<<it.second<<endl;
        return root;
    }
    
};
