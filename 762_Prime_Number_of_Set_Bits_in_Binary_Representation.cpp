class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> pr={2, 3, 5, 7, 11, 13, 17, 19};
        int res=0;
        for(int i=left; i<=right; i++){
            int setb=__builtin_popcount(i);
            if(pr.count(setb))
                res+=1;
        }
        return res;
    }
};
