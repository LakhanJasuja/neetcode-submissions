class Solution {
public:
    int numSquares(int n) {
        vector <int> sq;
        int i = 1;

        while (i * i <= n) {
            sq.push_back(i * i);
            i++;
        }

        int m = sq.size();
       // cout <<  m << "\n"; 
        vector <vector <int>> dp(m + 1, vector <int> (n + 1, INT_MAX));

        for (int i = 0 ; i <= m; i++) {
            dp[i][0] = 0;
        } 

        for (int i = 1; i <= m ; i++ ){
            for (int j = 1; j <= n; j++) {
                if (j < sq[i-1]) {
                  //  cout << j - sq[i-1] << "\n";
                    dp[i][j] = dp[i-1][j];
                } else {
                    //cout << j - sq[i-1] << "\n";
                    if (dp[i][j-sq[i-1]] != INT_MAX)
                        dp[i][j] = min(dp[i-1][j], dp[i][j - sq[i-1]] + 1);
                    else 
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n]; 
    }
};