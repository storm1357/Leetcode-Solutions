class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> ml(n);
        vector<int> mr(n);

        ml[0]=nums[0];
        mr[n-1]=nums[n-1];
        for(int i=1; i<n; i++){
            ml[i]=max(nums[i], ml[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            mr[i]=min(nums[i], mr[i+1]);
        }
        vector<int> ans(n);
        ans[n-1]=ml[n-1];
        for(int i=n-2; i>=0; i--){
            if(ml[i]<=mr[i+1]){
                ans[i]=ml[i];
            }else{
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};
