class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int>z(n , 0 );
        vector<int>o(n , 0) ; 
        if(s =="01")return 2 ;
        for(int i = 0 ; i<n-1 ; i++){
            if(i== 0 && s[i] == '0'){
                z[0] = 1 ;
            }
            else if(s[i] =='0'){
                z[i] = z[i-1]+1;
            }
            else if(i != 0 && s[i] != '0'){
                z[i] = z[i-1];
            }
        }
        for(int i = n-1 ; i>0 ; i--){
            if(i== n-1 && s[i] == '1'){
                o[n-1] = 1 ;
            }
            else if(s[i] =='1'){
                o[i] = o[i+1]+1;
            }
            else if(i != n-1 && s[i] != '1'){
                o[i] = o[i+1];
            }
        }
        int sum = 0 ;
        for(int i = 0 ; i<n ; i++){
            sum = max(sum , z[i]+o[i]);
        }
        return sum;
    }
};
