class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<long long> rs(m, 0);
        vector<long long> cs(n, 0);

        long long total=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total+=grid[i][j];
                rs[i]+=grid[i][j];
                cs[j]+=grid[i][j];
            }
        }
        if(total%2!=0)
            return false;
        long long up=0;
        for(int i=0; i<m-1; i++){
            up+=rs[i];
            if(up==total-up)
                return true;
        }
        long long left=0;
        for(int j=0; j<n-1; j++){
            left+=cs[j];
            if(left==total-left)
                return true;
        }
        return false;
    }
};
