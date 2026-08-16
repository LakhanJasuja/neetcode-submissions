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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        Interval b  = intervals[0];

        for (int i = 1 ;i < n; i++) {
            if (b.end > intervals[i].start) {
                return false;
            } else {
                b = intervals[i];
            }
        }

        return true;
        
    }
};
