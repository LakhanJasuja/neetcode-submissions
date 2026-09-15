class Solution {
public:
    int tribonacci(int n) {
        int t1 = 0;
        int t2 = 1;
        int t3 = 1;
        int t = t1 + t2 + t3;
        if (n == 0) return t1;
        if (n == 1) return 1;
        if (n == 2) return 1;

        for (int i=1 ; i <= n - 2; i++) {
            t = t1 + t2 + t3;
            t1 = t2;
            t2 = t3; 
            t3 = t;
        }

        return t;
        
    }
};