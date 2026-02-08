class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        int lefth=height(root->left);
        int righth=height(root->right);
        return max(lefth, righth)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int lefth=height(root->left);
        int righth=height(root->right);
        if(abs(lefth-righth)>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
