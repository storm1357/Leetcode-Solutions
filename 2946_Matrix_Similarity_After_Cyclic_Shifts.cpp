class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        k=(k%n);
        if(k==0)
            return true;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int curr=j;
                int fin;
                if(i%2==0){
                    fin=(j+k)%n;
                }else{
                    fin=(j-k+n)%n;
                }
                if(mat[i][curr]!=mat[i][fin]){
                    return false;
                }
            }
        }
        return true;
    }
};
