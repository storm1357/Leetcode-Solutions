class Solution {
public:
    vector <vector<int>> dp;

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(s1, s2, 0, 0);
    }

    int solve(string &s1, string &s2, int i, int j){
        if(i >= s1.size()){
            int sum = 0;
            for(int k = j; k < s2.size(); k++){
                sum += s2[k];
            }
            return sum;
        }
        if(j >= s2.size()){
            int sum = 0;
            for(int k = i; k < s1.size(); k++){
                sum += s1[k];
            }
            return sum;
        }

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i+1, j+1);
        
        int dels1 = s1[i] + solve(s1, s2, i+1, j);
        int dels2 = s2[j] + solve(s1, s2, i, j+1);

        return dp[i][j] = min(dels1, dels2);
    }
};
