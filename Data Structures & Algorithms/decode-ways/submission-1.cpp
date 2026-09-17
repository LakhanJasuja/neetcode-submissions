class Solution {
public:
    int cnt = 0;
    bool isValid(string& s) {
        if (s.size() == 1 && s[0] >= '1' && s[0] <= '9') {
            return true;
        } else if (s.size() == 2) {
            if (s[0] == '1') return true;
            else if (s[0] == '2' && (s[1] >= '0' && s[1] <= '6')) return true; 
        }
        return false;
    }
    string charToString(char ch) {
        string str = "";
        str += ch;
        return str;
    }

    int helper(string& s, int i, vector <int> &dp) {
        if (i == s.size()) return 1;
        if (dp[i] != -1) return dp[i];
        int ans = 0;
        if (s[i] != '0') {
            ans += helper(s, i+1, dp);
        }
        if (i + 1 != s.size()) {
            string str = charToString(s[i]) + charToString(s[i+1]);
            if (isValid(str)) {
                ans += helper(s, i+2, dp);
            }
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector <int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};
