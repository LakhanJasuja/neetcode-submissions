/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool cmp(Interval a, Interval b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int maxm = 0;
        for (Interval interval : intervals) {
            maxm = max(maxm, interval.end);
        }
        if (n == 0 || maxm == 0) return 0;
        vector <int> arr(maxm + 2, 0);
        for (int i = 0 ; i < n; i++) {
            arr[intervals[i].start]++;
            arr[intervals[i].end]--;
        }
        int ans = 1;

        for (int i = 1; i <= maxm; i++) {
            arr[i] += arr[i-1];
            if (arr[i] > ans) ans = arr[i];
        }
        return ans;
        // vector <Interval> arr;
        // int cnt = 1;
        // arr.push_back(intervals[0]);

        // for (int i = 1 ;i < n; i++) {
        //     if (arr.back().end > intervals[i].start) {
        //         arr.back().end = max(arr.back().end, intervals[i].end);
        //     } else {
        //         arr.push_back(intervals[i]);
        //     }
        // }

        // return intervals.size() - arr.size();
        
    }
};
