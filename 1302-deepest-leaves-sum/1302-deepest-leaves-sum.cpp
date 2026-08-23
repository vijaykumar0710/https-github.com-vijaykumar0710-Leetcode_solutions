class Solution {
public:
priority_queue<pair<int,int>>pq;
void fn(TreeNode* root,int d){
    if(root->left) fn(root->left,d+1);
    if(root->right) fn(root->right,d+1);
    if(!root->left && !root->right){
        pq.push({d,root->val});
        return;
    }
}
    int deepestLeavesSum(TreeNode* root) {
        fn(root,0);
        int sum=0;
        int x=-1;
        if(!pq.empty()) x=pq.top().first;
        while(!pq.empty() && pq.top().first==x){
            sum+=pq.top().second;
            pq.pop();
        }
        return sum;
    }
};