class Solution {
public:
    bool recur(string& s, int i, string curr, vector<string>& wordDict, map <pair<int, int>, bool>& mp) {
        if (i == s.size()) {
            // if (curr.size() == 0) return false;
            // cout << curr << " " << binary_search(wordDict.begin(), wordDict.end(), curr) << "\n";
            // return binary_search(wordDict.begin(), wordDict.end(), curr);
            return curr.size() == 0;
        }

        if (mp.find({i, curr.size()}) != mp.end()) {
            return mp[{i, curr.size()}];
        }

        curr += s[i];
        bool a1 = false;
        if (binary_search(wordDict.begin(), wordDict.end(), curr)) {
            // cout << "1 "  << curr << " " << binary_search(wordDict.begin(), wordDict.end(), curr) << "\n";
            a1 = recur(s, i+1, "", wordDict, mp);
        }

        bool a2 = recur(s, i+1, curr, wordDict, mp);
        mp[make_pair(i, curr.size())] = a1 || a2;
        return a1 || a2;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        map <pair<int, int>, bool> mp;
        string str = "";
        return recur(s, 0, str, wordDict, mp);
    }
};
