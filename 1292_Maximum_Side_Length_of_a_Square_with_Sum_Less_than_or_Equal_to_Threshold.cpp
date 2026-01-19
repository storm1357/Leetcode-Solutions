class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>rows (n, vector<int>(m+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rows[i][j+1]=rows[i][j]+mat[i][j];
            }
        }
        int low=1;
        int high=min(m, n);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            bool found=false;
            for(int i=0; i+mid<=n;i++){
                for(int j=0; j+mid<=m; j++){
                    if(check(mat, mid, threshold, rows, i, j)){
                        found=true;
                        break;
                    }
                }
            }
            if(found){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    bool check(vector<vector<int>>& mat, int size, int threshold, vector<vector<int>>& rows, int row, int col){
        int sum=0;
        for(int i=row; i<row+size; i++){
            sum+=rows[i][col+size]-rows[i][col];
            if(sum>threshold)
                return false;
        }
        return true;
    }
};
