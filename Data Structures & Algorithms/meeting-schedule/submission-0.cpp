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

class Solution {
    static bool customComparison(Interval& a, Interval& b)
    {
        return a.start < b.start; 
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), customComparison);
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i].start<intervals[i-1].end) return false;
        }
        return true;
    }
};
