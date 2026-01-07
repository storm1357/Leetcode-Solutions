class Solution {
public:
    long long maxi = 0;
    const int MOD = 1000000007;

    long long totalSum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long dfs(TreeNode* root, long long sum){
        if(root == NULL) return 0;
        
        long long left = dfs(root->left, sum);
        long long right = dfs(root->right, sum);
        
        long long curr = left + right + root->val;

        maxi = max(maxi, (sum-curr)*curr);
        
        return curr;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;

        long long sum = totalSum(root);
        dfs(root, sum);
        return (int)(maxi%MOD);
    }
};
