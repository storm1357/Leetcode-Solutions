class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans=-1e18;
        long long prev=nums[0];
        int n=nums.size();
        long long a=-1e17;
        long long b=-1e17;
        long long c=-1e17;
        for(int i=1; i<n; i++){
            long long na=-1e17;
            long long nb=-1e17;
            long long nc=-1e17;
            long long curr=nums[i];
            if(curr>prev){
                na=max(a, prev)+curr;
                nc=max(b, c)+curr;
            }else if(curr<prev){
                nb=max(b, a)+curr;
            }
            a=na;
            b=nb;
            c=nc;
            ans=max(ans, c);
            prev=curr;
        }
        return ans;
    }
};
