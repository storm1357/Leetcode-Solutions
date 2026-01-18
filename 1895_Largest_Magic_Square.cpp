class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& row, vector<vector<int>>& col, int siz){
        int target=row[r][c+siz]-row[r][c];
        for(int i=r; i<r+siz; i++){
            if(row[i][c+siz]-row[i][c]!=target)
                return false;
        }
        for(int j=c; j<c+siz; j++){
            if(col[r+siz][j]-col[r][j]!=target)
                return false;
        }
        int d1=0;
        int d2=0;
        for(int i=0; i<siz; i++){
            d1+=grid[r+i][c+i];
            d2+=grid[r+i][c+siz-1-i];
        }
        if(d1!=target || d2!=target)
            return false;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> row(n, vector<int>(m+1, 0));
        vector<vector<int>> col(n+1, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i][j+1]=row[i][j]+grid[i][j];
                col[i+1][j]=col[i][j]+grid[i][j];
            }
        }
        int maxs=min(m, n);
        while(maxs>=2){
            for(int i=0; i+maxs<=n; i++){
                for(int j=0; j+maxs<= m; j++){
                    if(check(grid, i, j, row, col, maxs))
                        return maxs;
                }
            }
            maxs--;
        }
        return 1;
    }
};
