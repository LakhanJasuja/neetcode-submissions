class Solution {
public:
    bool checkPalin(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (s[i] != s[j]) break;
            i++;
            j--;
        }

        if (i >= j) return true;

        return checkPalin(s, i+1, j) || checkPalin(s, i, j-1);

        // int ptr1 = -1;
        // int ptr2 = -1;

        // int cnt = 0;
        // while (i < j) {
        //     if (s[i] != s[j]) {
        //         ptr1 = i;
        //         ptr2 = j;
        //     }
        //     i++;
        //     j--;
        // }
        // if (ptr1 == -1) return true;

        // i = 0;
        // j = n - 1;

        // bool ans1 = true;
        // bool ans2 = true;

        // while (i < j) {
        //     cout << i << " " << j << " " << ptr1 << "\n";
        //     if (i == ptr1) {
        //         i++;
        //         continue;
        //     }
        //     if (s[i] != s[j]) ans1 = false;
        //     i++;
        //     j--;
        // }

        // i = 0;
        // j = n - 1;

        // while (i < j) {
        //     if (j == ptr2) {
        //         j--;
        //         continue;
        //     }
        //     if (s[i] != s[j]) ans2 =  false;
        //     i++;
        //     j--;
        // }

        // return ans1 || ans2;
    }
};