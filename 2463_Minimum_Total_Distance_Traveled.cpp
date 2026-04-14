class Solution {
const long long inf = 1e15;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        const int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, inf));
        dp[0] = vector<long long>(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                long long d = 0;
                for (int k = 1; k <= i && k <= factory[j - 1][1]; ++k) {
                    d += abs(robot[i - k] - factory[j - 1][0]);
                    if (dp[i - k][j - 1] < inf) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + d);
                    }
                }
                
            }
        }
        return dp[n][m];
    }
};
