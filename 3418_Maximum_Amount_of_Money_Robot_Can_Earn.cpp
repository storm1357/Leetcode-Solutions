class Solution {
public:
    int m, n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu){
        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && neu > 0){
                return 0;
            }
            return coins[i][j];
        }

        if(i >= m || j >= n){
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN){
            return t[i][j][neu];
        }

        int down = solve(coins, i+1, j, neu);
        int right = solve(coins, i, j+1, neu);

        int best = max(down, right);

        int take = (best == INT_MIN) ? INT_MIN : coins[i][j] + best;

        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0){
            int skipdown = solve(coins, i+1, j, neu-1);
            int skipright = solve(coins, i, j+1, neu-1);
            skip = max(skipdown, skipright);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        for(int i=0; i<501; i++){
            for(int j=0; j<501; j++){
                for(int k=0; k<3; k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};
