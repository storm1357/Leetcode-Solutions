class Solution {
public:
    int binaryGap(int n) {
        int curr=0;
        int pre=-1;
        int res=0;
        while(n>0){
            if((n&1)>0){
                res=(pre!=-1)?max(res, curr-pre):res;
                pre=curr;
            }
            curr++;
            n>>=1;
        }
        return res;
    }
};
