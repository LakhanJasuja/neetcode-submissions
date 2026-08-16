class Solution {
public:
    bool isValid(vector <int>&hash ,int k) {
        int cnt = 0;
        vector <int> arr;
        for (int i = 0 ; i < 26; i++) {
            if (hash[i] > 0) {
                arr.push_back(hash[i]);
            }
        }
        sort(arr.begin(), arr.end());
        for (int i = 0 ; i< arr.size() - 1; i++) {
            cnt += arr[i];
        }
        return cnt <= k;
    }
    int characterReplacement(string s, int k) {
        vector <int> hash(26, 0);
        int j = 0;
        int i = 0;
        int ans = 1;

        for (i = 0; i < s.size(); i++) {
            hash[s[i]-'A']++;

            while(!isValid(hash, k)) {
                hash[s[j] - 'A']--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        ans = max(ans, i - j);
        return ans; 
    }
};
