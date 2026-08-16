class Solution {
public:
    bool isValid(vector <int>&hash1, vector <int>&hash2) {
        for (int i = 0; i < 52; i++) {
            //cout << hash2[i] << " " << hash1[i] << "\n";
            if (hash2[i] > hash1[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        vector <int> hash1(52, 0);
        vector <int> hash2(52, 0);
        for (char ch : t) {
            if (ch >= 'a' && ch <= 'z') {
                hash2[ch - 'a' + 26]++;
            } else {
                hash2[ch - 'A']++;
            }
        }
        

        // for (int i = 0; i < 26; i++) {
        //     cout << hash2[i] << " ";
        // }
        // cout <<"\n";
        
        int start = -1;
        int end = -1;
        int len = n + 1;
        int j = 0;

        for (int i = 0 ; i < n;i++) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') hash1[ch - 'a' + 26]++;
            else hash1[ch - 'A']++;

            while(isValid(hash1, hash2)) {
              //  cout << len << "\n";
                if (len > i - j + 1) {
                   start = j;
                   end = i; 
                   len = i - j + 1;
                //   cout << len << "\n";
                }
                char ch1 = s[j];
                // if (ch1 >= 'a' && ch1 <= 'z') ch1 -= 32;
                // hash1[ch1 - 'A' + 26]--;
                if (ch1 >= 'a' && ch1 <= 'z') hash1[ch1 - 'a' + 26]--;
                else hash1[ch1 - 'A']--;
                j++;
            }
        }

        if (start == -1) return "";

        return s.substr(start, end - start + 1);
        
    }
};
