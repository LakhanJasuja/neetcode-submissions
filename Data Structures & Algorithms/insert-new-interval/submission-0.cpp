class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1 ;i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;



        // int n = intervals.size();
        // if (intervals[0][1] > newInterval[1]) {
        //     intervals.push_front(newInterval);
        //     return intervals;
        // } else if (intervals[0][1] == newInterval[1]) {
        //     intervals[0][0] = newInterval[0];
        //     return intervals;
        // }

        // for (int i = 0 ; i < n; i++) {
        //     // overlap

        //     if (intervals[i][0] ) {

        //     } else {
        //         ans.push_back()
        //     }


        //     //else 

        // }
        
        
    }
};
