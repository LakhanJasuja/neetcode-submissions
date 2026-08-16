class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        int k = 0;
        vector<vector<int>> ans;

        while (i < n-2) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
              //  cout << "L0 " << i << " " << j << " " << k << "\n";

                if (nums[i] + nums[j] + nums[k] == 0) {
                   // cout << "L1 " << i << " " << j << " " << k << "\n";
                    vector <int> arr({nums[i], nums[j], nums[k]});
                    ans.push_back(arr);
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }

            while (i < n - 2 && nums[i] == nums[i+1]) i++;
            i++;
           // cout << "L2 " << i << " " << j << " " << k << "\n";

        }
        return ans;   
    }
};
