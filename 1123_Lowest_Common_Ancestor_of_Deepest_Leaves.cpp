class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return NULL;

        int l = height(root->left);
        int r = height(root->right);

        if(l==r)
            return root;
        
        if(l>r)
            return lcaDeepestLeaves(root->left);
        else
            
            return lcaDeepestLeaves(root->right);
    }
    int height(TreeNode* root){
        if(root==NULL) return NULL;

        int l = height(root->left);
        int r = height(root->right);

        return max(l, r) + 1;
    }
};
