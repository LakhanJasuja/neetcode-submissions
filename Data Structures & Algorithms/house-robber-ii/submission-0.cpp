class Solution {
public:
    int solve(vector <int>& nums) {
        int n = nums.size();
        vector <int> dp(n+1, 0);
        dp[1] = nums[0];
        for (int i = 2 ; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            //cout << dp[i] << " ";
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        vector <int> a1;
        vector <int> a2;
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) a1.push_back(nums[i]);
            else if(i == nums.size()-1) a2.push_back(nums[i]);
            else {
                a1.push_back(nums[i]);
                a2.push_back(nums[i]);
            }
        }
        return max(solve(a1), solve(a2));
        
    }
};
