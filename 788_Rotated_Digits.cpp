class Solution {
public:
    bool is(int num){
        int curr=num;
        bool isv=false;
        while(num>0){
            int rem=num%10;
            if(rem==3||rem==4||rem==7)
                return false;
            if(rem==2||rem==5||rem==6||rem==9)
                isv=true;
            num=num/10;
        }
        return isv;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=2; i<=n; i++){
            if(is(i))
                count++;
        }
        return count;
    }
};
