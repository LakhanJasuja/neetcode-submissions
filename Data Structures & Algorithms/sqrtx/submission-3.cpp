class Solution {
public:
    int mySqrt(int x) {

        long long l = -1;
        long long r = x + 1;

        while (r > l + 1) {
            long long mid = (l + r) / 2;

           // cout << l << " " << r << " " << mid << "\n";

           // cout << mid * mid << " " << x << "\n";
            
            if (mid * mid == x) return mid;
            else if (mid * mid > x) r = mid;
            else l = mid;
        }
        return l;
    }
};