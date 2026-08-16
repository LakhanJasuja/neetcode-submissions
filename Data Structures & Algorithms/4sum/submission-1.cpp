class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector <vector <int>> ans;

        while (i < n - 3) {
            int j = i + 1;
            while (j < n - 2) {
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    if ((long)(nums[i]) + (long)nums[j] + (long)nums[k] + (long)nums[l] == target) {
                        vector <int> arr({nums[i], nums[j], nums[k], nums[l]});
                        ans.push_back(arr);
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    } else if (nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                    } else {
                        k++;
                    }
                }

                while (j < n - 2 && nums[j] == nums[j+1]) j++;
                j++;
            }
            while (i < n - 3 && nums[i] == nums[i+1]) i++;
            i++;
        }

        return ans;
        
    }
};