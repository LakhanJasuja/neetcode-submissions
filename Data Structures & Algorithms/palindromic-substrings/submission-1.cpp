class Solution {
public:
    // bool countPalin(vector <vector <int>> &dp, int i, int j) {

    // }
    int countSubstrings(string s) {
        int n = s.size();
        vector <vector <bool>> dp(n+2, vector <bool> (n+2, false));
        int start = 0;
        int end = 0;

        int len = 0;
        int ans = 0;
        while (len < n) {
            int i = 1;
            int j = i + len;

            while (j <= n) {
              //  cout << i << " " << j << "\n";
                // if (i >= n || j >= )
                if (i == j) dp[i][j] = true;
                else if (i+1 == j) {
                    if (s[i-1] == s[j-1]) dp[i][j] = true;
                    else dp[i][j] = false;
                }
                else {
                    if(s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1];
                    else dp[i][j] = false;
                }
                if (dp[i][j] == true) ans++;
                i++;
                j++;
            }
            len++;
        }

        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= n; j++ ){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return ans;
        
    }
};
