class Solution {
public:
    int mod = 1e9 + 7;
    
    vector<vector<pair<long long, long long>>> dp;

    pair<long long, long long> f(int i , int j , vector<vector<int>>& arr){
        if(i < 0 || j < 0) return {LLONG_MIN, LLONG_MAX};

        if(i == 0 && j == 0) return {arr[i][j], arr[i][j]};

        if(dp[i][j].first != LLONG_MIN) return dp[i][j];

        auto left = f(i , j-1 , arr);
        auto up = f(i-1 , j , arr);

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        if(left.first != LLONG_MIN){
            long long a = arr[i][j] * left.first;
            long long b = arr[i][j] * left.second;
            mx = max({mx, a, b});
            mn = min({mn, a, b});
        }

        if(up.first != LLONG_MIN){
            long long a = arr[i][j] * up.first;
            long long b = arr[i][j] * up.second;
            mx = max({mx, a, b});
            mn = min({mn, a, b});
        }

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.resize(n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MAX}));

        auto res = f(n-1 , m-1 , grid);

        if(res.first < 0) return -1;

        return res.first % mod;
    }
};
