class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int minm = prices[0];
        int ans = 0;
        for (int i = 1; i< n; i++) {
            ans = max(ans, prices[i] - minm);
            minm = min(minm, prices[i]);
        }
        return ans;
        
    }
};
