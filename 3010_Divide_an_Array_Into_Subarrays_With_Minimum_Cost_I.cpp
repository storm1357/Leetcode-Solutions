class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost=nums[0];
        int min1=INT_MAX;
        int min2=INT_MAX;
        for (int i=1; i<nums.size(); i++){
            int curr=nums[i];
            if(min1>curr){
                min2=min1;
                min1=curr;
            }else if(min2>curr){
                min2=curr;
            }
        }
        cost+=min1;
        cost+=min2;
        return cost;
    }
};
