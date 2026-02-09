class Solution {
public:
    void solve(TreeNode* root, vector<int> &nodes){
        if(root==NULL){
            return;
        }
        solve(root->left, nodes);
        nodes.push_back(root->val);
        solve(root->right, nodes);
    }

    TreeNode* makebst(int l, int r, vector<int> &nodes){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(nodes[mid]);
        root->left=makebst(l, mid-1, nodes);
        root->right=makebst(mid+1, r, nodes);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        solve(root, nodes);
        return makebst(0, nodes.size()-1, nodes);
    }
};
