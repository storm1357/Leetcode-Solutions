class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }
            area = max(area, solve(heights));
        }
        return area;
    }
    int solve(vector<int>& heights){
        int n = heights.size();
        int area = 0;
        stack<int> stk;
        for(int i=0; i<=n; i++){
            int current;
            if(i == n)
                current = 0;
            else
                current = heights[i];
            while (!stk.empty() && current < heights[stk.top()]) {
                int height = heights[stk.top()];
                stk.pop();

                int left = stk.empty() ? -1 : stk.top();
                int width = i - left - 1;

                area = max(area, height * width);
            }
            stk.push(i);
        }
        return area;
    }
};
