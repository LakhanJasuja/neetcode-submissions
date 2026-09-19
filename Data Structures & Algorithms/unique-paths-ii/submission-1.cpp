class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector <vector <int>> dp(n+1, vector <int> (m+1, 0));
        int i = 1;
        while (i <= n && obstacleGrid[i-1][0] != 1) {
          //  cout << i << "\n";
            dp[i][1] = 1;
            i++;
        }

        int j = 1;
        while (j <= m && obstacleGrid[0][j-1] != 1) {
            dp[1][j] = 1;
            j++;
        }

        for (int i = 2; i <= n; i++) {
            for (int j=2; j<=m; j++) {
                if (obstacleGrid[i-1][j-1] == 1) {
                    continue;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
        
    }
};