class Solution {
public:
    int maxSubsetSum(vector <int>&arr, vector <vector <int>>&dp, int i, int sum, int t) {
        if (i == arr.size()) {
            if (sum <= t) {
                return sum;
            } else {
                return INT_MIN;
            }
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }

        int x = maxSubsetSum(arr, dp, i+1, sum + arr[i], t);
        int y = maxSubsetSum(arr, dp, i+1, sum, t);
      //  cout << i << " " << sum << " " << x << " " << y << "\n";
      //  ans = max(ans, max(x, y));
        return dp[i][sum] = max(x, y);
    }
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int sum = 0;
        for (int x : stones) {
            sum += x;
        }
        int n = stones.size();
        vector <vector <int>> dp(n + 1, vector <int> (sum + 1, -1)); 
      //  int ans = INT_MIN;

        int ans = maxSubsetSum(stones, dp, 0, 0, sum / 2);
        return sum - 2 * ans;
    }
};