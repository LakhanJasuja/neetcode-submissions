class Solution {
public:
    int sumFind(vector<int>& nums, int i, int sum, int curr, vector <vector <int>>& dp) {
        if (curr == sum) return 1;
        if (i == nums.size()) return 0;
        if (dp[i][curr] != -1) return dp[i][curr];
        int x = sumFind(nums, i+1, sum, curr + nums[i], dp);
        int y = sumFind(nums, i+1, sum, curr, dp);

        if (x == 1 || y == 1) {
            return dp[i][curr] = 1;
        } 
        return dp[i][curr] = 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2) return false;
        int n = nums.size();
        vector <vector <int>> dp(n, vector <int> (sum + 1, -1));

        return sumFind(nums, 0, sum /2, 0, dp);
    }
};
