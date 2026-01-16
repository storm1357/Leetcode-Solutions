class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax = 0, vMax = 0;

        // longest consecutive removed horizontal bars
        for (int i = 0, cnt = 1; i < hBars.size(); i++) {
            if (i > 0 && hBars[i] == hBars[i - 1] + 1)
                cnt++;
            else
                cnt = 1;
            hMax = max(hMax, cnt);
        }

        // longest consecutive removed vertical bars
        for (int i = 0, cnt = 1; i < vBars.size(); i++) {
            if (i > 0 && vBars[i] == vBars[i - 1] + 1)
                cnt++;
            else
                cnt = 1;
            vMax = max(vMax, cnt);
        }

        int side = min(hMax + 1, vMax + 1);
        return side * side;
    }
};
