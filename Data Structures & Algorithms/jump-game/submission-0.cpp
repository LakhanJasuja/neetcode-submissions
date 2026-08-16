class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0;

        for (int i = 0; i < n ; i++){
            if (i > maxReachable) return false;
            maxReachable = max(maxReachable, i + nums[i]);
           // cout << i << " " << maxReachable << "\n";
            if (maxReachable >= n-1) return true;
        }
        return false;
        
    }
};
