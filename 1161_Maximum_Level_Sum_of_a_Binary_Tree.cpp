class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root  == NULL) return 0;

        int maxSum = INT_MIN;
        int level = 1;
        int ans = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int count = q.size();
            int sum = 0;

            for (int i=0; i<count; i++){
                TreeNode* node=q.front();
                q.pop();

                sum += node->val;

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            if(sum>maxSum){
                maxSum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
