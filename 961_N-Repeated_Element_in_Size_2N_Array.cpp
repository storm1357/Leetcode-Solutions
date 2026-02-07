class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int count = nums.size()/2;

        unordered_map<int, int> mp;

        for (int& num:nums){
            mp[num]++;
        }

        for (auto num:mp){
            if(mp[num.first]==count){
                return num.first;
            }
        }
        return -1;
    }
};
