class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int count = 0;
        int mini = INT_MAX;

        for(auto &row : matrix){
            for(int val : row){
                if(val < 0) count++;
                sum += abs(val);
                mini = min(mini, abs(val));
            }
        }
        if(count % 2 == 1){
            sum -= 2LL * mini;
        }
        return sum;
    }
};
