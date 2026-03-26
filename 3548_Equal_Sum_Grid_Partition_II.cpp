class Solution {
public:
    typedef long long ll;
    ll total=0;
    bool checkhcuts(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        unordered_set<ll> st;
        ll top=0;
        for(int i=0; i<=m-2; i++){
            for(int j=0; j<n ;j++){
                st.insert(grid[i][j]);
                top+=grid[i][j];
            }
            ll bottom=total-top;
            ll diff=top -bottom;
            if(diff==0) return true;
            if(diff==(ll)grid[0][0]) return true;
            if(diff==(ll)grid[0][n-1]) return true;
            if(diff==(ll)grid[i][0]) return true;

            if(i>0 && n>1 && st.count(diff)){
                return true;
            }
        }
        return false;

    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total+=grid[i][j];
            }
        }
        if(checkhcuts(grid)){
            return true;
        }
        reverse(begin(grid), end(grid));
        if(checkhcuts(grid)){
            return true;
        }
        reverse(begin(grid), end(grid));
        vector<vector<int>> tgrid(n, vector<int>(m));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                tgrid[j][i]=grid[i][j];
            }
        }
        if(checkhcuts(tgrid)){
            return true;
        }
        reverse(begin(tgrid), end(tgrid));
        if(checkhcuts(tgrid)){
            return true;
        }
        return false;
    }
};
