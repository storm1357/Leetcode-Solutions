class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;

        int l = height(root->left);
        int r = height(root->right);

        if(l==r)
            return root;
        
        if(l>r)
            return subtreeWithAllDeepest(root->left);
        else
            
            return subtreeWithAllDeepest(root->right);
    }
    int height(TreeNode* root){
        if(root==NULL) return NULL;

        int l = height(root->left);
        int r = height(root->right);

        return max(l, r) + 1;
    }
};
