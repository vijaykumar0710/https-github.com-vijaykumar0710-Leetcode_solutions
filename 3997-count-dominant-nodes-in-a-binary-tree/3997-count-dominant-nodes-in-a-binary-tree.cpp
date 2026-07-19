class Solution {
public:
int dfs(TreeNode* root,int &res){
   if(!root) return 0;
   int left=dfs(root->left,res);
   int right=dfs(root->right,res);
   if(root->val>=left&&root->val>=right) res++;
   return max({root->val,left,right});
}
    int countDominantNodes(TreeNode* root) {
        int res=0;
        dfs(root,res);
        return res;
    }
};