class Solution {
public:
int res=0;
pair<int,int>solve(TreeNode* root){
    if(!root) return {0,0};
    auto left=solve(root->left);
    auto right=solve(root->right);
    int sum=root->val+left.first+right.first;
    int cnt=1+left.second+right.second;
    if(sum/cnt==root->val) res++;
    return {sum,cnt};
}
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};