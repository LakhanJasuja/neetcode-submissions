class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();

        vector <vector <int>> dp(n+1, vector <int> (amount + 1, INT_MAX));

        for (int i = 0 ; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                   // cout << i << " " << j  <<  " " << j - coins[i-1] << " " << dp[i][j-coins[i-1]] << " " << dp[i-1][j] << "\n";
                    if (dp[i][j-coins[i-1]] != INT_MAX) {
                        dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        // cout << dp[1][0] << "\n";

        // for (int i=0; i <= n ; i++) {
        //     for (int j =0 ; j <= amount; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return dp[n][amount] == INT_MAX || dp[n][amount] < 0 ? -1 : dp[n][amount];
    }
};
