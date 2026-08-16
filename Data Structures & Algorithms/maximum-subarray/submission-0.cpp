class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int maxm = INT_MIN;
        for (int x : nums) {
            sum += x;

            maxm = max(maxm, x);
            if (sum > ans) {
                ans = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxm < 0 ? maxm : ans;

    }
};
