class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int cnt = 0;

        ans.push_back(intervals[0]);

        for (int i = 1 ;i < n; i++) {
            if (ans.back()[1] > intervals[i][0]) {
                ans.back()[1] = min(ans.back()[1], intervals[i][1]);
                cnt++;
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return cnt;

        
    }
};
