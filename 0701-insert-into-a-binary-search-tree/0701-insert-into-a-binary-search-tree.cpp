class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        else if(root->val>val){  //go left
            if(root->left==NULL){
                root->left=new TreeNode(val);
            }
            else insertIntoBST(root->left,val);
        }
        else{  //go right
            if(root->right==NULL){
                root->right=new TreeNode(val);
        }
        else  insertIntoBST(root->right,val);
        }
        return root;
    }
};