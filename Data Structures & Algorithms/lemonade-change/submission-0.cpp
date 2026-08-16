class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f1 = 0; // five
        int f2 = 0; //tens

        for (int x : bills) {
            if (x == 5) f1++;
            else if (x == 10) {
                if (f1 < 1) return false;
                f1--;
                f2++;
            } else if (x ==20) {
                if (f2 >= 1) {
                    f2--;
                    if (f1 < 1) return false;
                    else f1--;
                } else if (f1 >= 3) {
                    f1 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
        
    }
};