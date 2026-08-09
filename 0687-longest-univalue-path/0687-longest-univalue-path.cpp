class Solution {
public:
    int res = 0;
    int f(TreeNode* root) {
        if (!root)
            return 0;
        int left = f(root->left);
        int right = f(root->right);
        int ans = 1;
        if (root->left && (root->val == root->left->val))
            ans = max(ans, 1 + left);

        if (root->right && (root->val == root->right->val))
            ans = max(ans, 1 + right);

        if(root->left && root->right && root->val==root->left->val && root->val==root->right->val){
            res=max(res,1+left+right);
        }
        res = max(res, ans);
        return ans;
    }
    int longestUnivaluePath(TreeNode* root) {
        f(root);
        return max(0,res-1);
    }
};