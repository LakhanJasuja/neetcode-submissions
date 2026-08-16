class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int m3 = 0;
        int m4 = 0;
        int sum = 0;
        int sum2 = 0;
        int maxm = INT_MIN;
        int totSum = 0;
        
        for (int i =0 ; i < n; i++) {
            int x = nums[i];
            totSum += x;
            sum += x;
            sum2 += x;

            maxm = max(maxm, x);
            if (sum > m3) {
                m3 = sum;
            } 

            if (sum2 < m4) {
                m4 = sum2;
            }

            if (sum2 > 0) {
                sum2 = 0;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        if (maxm < 0) return maxm;

        return max(m3, totSum - m4);

        // int i = 0;
        // int pre = 0;
        // int sum1 = 0;
        // int m1 = 0;
        // while (i < n) {
        //     sum1 += nums[i];
        //     if (sum1 > m1) {
        //         m1 = sum1;
        //         pre = i;
        //     }
        //     i++;
        // }

        // int j = n - 1;
        // int m2 = 0;
        // int sum2 = 0;
        // while (j > pre) {
        //     sum2 += nums[j];
        //     if (sum2 > m2) {
        //         m2 = sum2;
        //     }
        //     j--;
        // }

        // cout << m1 << " " << m2 << " " << m3 << "\n";

        // return max(m3, m1 + m2);
        
    }
};