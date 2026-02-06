class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int low=0;
        int high=letters.size()-1;
        if(letters[high]<=target)return ans;
        while(low<=high){
            int mid=(low+high)/2;
            char ch=letters[mid];
            if(ch>target){
                ans=ch;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};
