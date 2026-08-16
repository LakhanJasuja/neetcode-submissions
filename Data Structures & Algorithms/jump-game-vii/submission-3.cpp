class Solution {
public:
    bool reach(string& s, int minJump, int maxJump, int curr) {
        int n = s.size();
        bool ans = false;
        for (int i = curr + minJump; i <= curr + maxJump; i++) {
            if (i >= n) break;
            if (i == n-1) return true;
            if (s[i] == '0') {
                bool r = reach(s, minJump, maxJump, i);
                if (r == true) return true;
            } 
            s[i] = '2';
        }
        return false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.size() - 1] == '1' || s[0] == '1') return false;
        return reach(s, minJump, maxJump, 0);
        //bool ans = false;
        // int l = 0; 
        // int r = 0;
        // int start = 0;


        // for (int i = 0; i < n; i++) {
        //     if (s[i] == '2') continue;


        //     for (int j = i + minJump; j <= i + maxJump; j++) {
        //         if (j >= n - 1) return true;
                

        //     }
        // }

        // while (r < n - 1) {
        //     bool a = false;

        //     for (int i = start + minJump; i <= start + maxJump; i++) {
        //         if (i >= n-1) return true;

        //     }
        // }
        
    }
};