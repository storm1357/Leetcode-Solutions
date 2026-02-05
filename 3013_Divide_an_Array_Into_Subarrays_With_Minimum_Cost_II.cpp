class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        auto cmp = [&](int a, int b) {
            if (nums[a] == nums[b]) return a < b;
            return nums[a] < nums[b];
        };

        set<int, decltype(cmp)> sel(cmp), rem(cmp);

        k--;  // nums[0] is always included

        long long curSum = 0;
        long long ans = LLONG_MAX;

        int last = min(dist + 1, n - 1);

        // initial window
        for (int i = 1; i <= last; i++) {
            rem.insert(i);
        }

        // move k smallest to sel
        while ((int)sel.size() < k && !rem.empty()) {
            int x = *rem.begin();
            rem.erase(x);
            sel.insert(x);
            curSum += nums[x];
        }

        ans = min(ans, curSum + nums[0]);

        // sliding window
        for (int i = last + 1; i < n; i++) {
            int out = i - dist - 1;

            // remove outgoing
            if (sel.count(out)) {
                sel.erase(out);
                curSum -= nums[out];
            } else {
                rem.erase(out);
            }

            // insert new
            if (!sel.empty() && nums[i] < nums[*prev(sel.end())]) {
                sel.insert(i);
                curSum += nums[i];
            } else {
                rem.insert(i);
            }

            // rebalance
            while ((int)sel.size() > k) {
                int x = *prev(sel.end());
                sel.erase(x);
                rem.insert(x);
                curSum -= nums[x];
            }

            while ((int)sel.size() < k && !rem.empty()) {
                int x = *rem.begin();
                rem.erase(x);
                sel.insert(x);
                curSum += nums[x];
            }

            ans = min(ans, curSum + nums[0]);
        }

        return ans;
    }
};
