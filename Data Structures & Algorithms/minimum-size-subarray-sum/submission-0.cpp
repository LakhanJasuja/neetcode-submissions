class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = nums.size() + 1;
        int sum = 0;

        for (i = 0; i<nums.size(); i++) {
            sum += nums[i];
            while(sum >= target) {
                ans = min(ans, i - j + 1);
                sum -= nums[j];
                j++;
            }
        }
        return ans == nums.size() + 1 ? 0 : ans; 
        
    }
};