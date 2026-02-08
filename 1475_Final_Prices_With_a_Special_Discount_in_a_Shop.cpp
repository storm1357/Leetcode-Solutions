class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> result(prices.size(), 0);

        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                result[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            result[st.top()] = prices[st.top()];
            st.pop();
        }

        return result;
    }
};
