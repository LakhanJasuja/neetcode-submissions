class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last; // O(1)
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch2 = s[n-i-1];

            if(last.find(ch2) == last.end()) {
                last[ch2] = n- i - 1;
            }
        }

        int l = 0;
        int r = last[s[0]];
        vector <int> ans;


        while(l < n && r < n) {
            for (int i = l; i<=r;i++) {
                char ch = s[i];
                if (last[ch] > r) {
                    r = last[ch];
                }
            }

            ans.push_back(r - l + 1);
            l = r + 1;
            r = last[s[l]];
        }
        return ans;
        
    }
};
