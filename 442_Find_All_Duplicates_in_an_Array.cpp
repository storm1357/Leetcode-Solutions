class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> tem (nums.size()+1, 0);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            tem[nums[i]]+=1;
            if(tem[nums[i]]>1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
