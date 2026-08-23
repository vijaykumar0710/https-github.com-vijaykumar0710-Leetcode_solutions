class Solution {
public:
int sum=0;
void fn(TreeNode* root,int &h,int d){
    if(root->left) fn(root->left,h,d+1);
    if(root->right) fn(root->right,h,d+1);
    if(!root->left && !root->right){
        if(h==d) sum+=root->val;
    }
}
int dfs(TreeNode* root){
if(!root) return 0;
int left=dfs(root->left);
int right=dfs(root->right);
return 1+max(left,right);
}
    int deepestLeavesSum(TreeNode* root) {
        int height=dfs(root);
        fn(root,height,1);
        return sum;
    }
};