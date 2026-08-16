class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        string word = "";

        while (i < n && j < m) {
            if (word.size()%2 == 0) {
                word += word1[i];
                i++;
            }
            else {
                word += word2[j];
                j++;
            }
        }

        while (i < n) {
            word += word1[i];
            i++;
        }

        while (j < m) {
            word += word2[j];
            j++;
        }

        return word;
    }
};