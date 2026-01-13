class Solution {
public:
    double separateSquares(vector<vector<int>>& squares){
        double y = 0.0;
        double tarea = 0.0;

        double mn = 1e18, mx = -1e18;

        for(auto& square : squares){
            double len = square[2];
            tarea += len*len;

            mn = min(mn, (double)square[1]);
            mx = max(mx, (double)square[1] + len);
        }

        double target = tarea/2.0;
        double low = mn, high = mx;

        while(low<high){
            if(high-low < 1e-5)
                break;
            
            double mid = (low+high)/2.0;
            double areabelow = 0.0;

            for(auto& square : squares){
                double y0 = square[1];
                double len = square[2];

                if(mid <= y0)
                    continue;
                else if(mid >= y0 + len)
                    areabelow += len * len;
                else 
                    areabelow += (mid - y0) * len;
            }
            if(areabelow < target)
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};
