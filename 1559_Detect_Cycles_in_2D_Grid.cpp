class Solution {
public:
    int m, n;
    vector<vector<int>> direction={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool cycledetect(int r, int c, int prer, int prec, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(visited[r][c]){
            return true;
        }
        visited[r][c]=true;
        for(auto &dir : direction){
            int newr=r+dir[0];
            int newc=c+dir[1];
            if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]==grid[r][c]){
                if(newr==prer && newc==prec){
                    continue;
                }
                if(cycledetect(newr, newc, r, c, grid, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<bool>>visited (m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && cycledetect(i, j, i, j, grid, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
