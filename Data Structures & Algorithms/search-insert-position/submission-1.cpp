class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int low = -1;
        int high = nums.size();

        while (high > low + 1) {
            int mid = low + (high - low)/2;
            if (nums[mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }
};