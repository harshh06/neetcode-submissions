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
    static bool comp(Interval& a, Interval& b) {
        return a.start<b.start;
    }

public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>>pq;
        for(Interval& interval: intervals){
            if(pq.size() && pq.top()<=interval.start) pq.pop();
            pq.push(interval.end);
        }
        return pq.size();
    }
};
