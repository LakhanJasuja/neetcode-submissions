class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        int l = 0;
        int r = 0;

        while (r < n-1) {
            int maxReachable = r;
            for (int i = l; i <= r; i++){
                maxReachable = max(maxReachable, i + nums[i]);
            }
            l = r + 1;
            r = maxReachable;
            jump++;
        }
        return jump;
    }
};
