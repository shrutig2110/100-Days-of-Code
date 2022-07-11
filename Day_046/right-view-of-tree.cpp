class Solution {
    void solve(TreeNode* root, vector<int> &ans, int level)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == ans.size())
        {
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level =0;
        solve(root, ans, level);
        return ans;
    }
};