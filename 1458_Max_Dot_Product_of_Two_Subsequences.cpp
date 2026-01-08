class Solution {
public:
    vector<vector<int>> dp;

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        dp.assign(n, vector<int>(m, INT_MIN));
        return solve(0, 0, nums1, nums2);
    }

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size())
            return INT_MIN;

        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int product = nums1[i]*nums2[j];

        int include = product;

        int next = solve(i+1, j+1, nums1, nums2);

        if(next > 0)
            include += next;

        int exclude1 = solve(i+1, j, nums1, nums2);
        int exclude2 = solve(i, j+1, nums1, nums2);

        return dp[i][j] = max(include, max(exclude1, exclude2));
    }
};
