class Solution {
public:
    bool isAlphaNumeric(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'); 
    }
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += 32;
        return ch;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            while (i < j && !isAlphaNumeric(s[i])) {
              //  cout << s[i] << " " << !isAlphaNumeric(s[i]) << "\n";
                i++;
            }
            while (i < j && !isAlphaNumeric(s[j])) j--;

           // cout << i << " " << j << "\n";
            char ch1 = toLower(s[i]);
            char ch2 = toLower(s[j]);

            cout << ch1 << " " << ch2 << "\n";

            if (ch1 != ch2) return false;

            i++;
            j--;
        }

        return true;
        
    }
};
