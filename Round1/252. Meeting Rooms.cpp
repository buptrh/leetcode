/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
    	auto comp = [](Interval & a, Interval & b) {
    		return a.start < b.start;
    	};
    	sort(intervals.begin(), intervals.end(), comp);
        for(int i = 0; i < (int)intervals.size()-1; i++) {
        	if(intervals[i].end > intervals[i+1].start) {
        		return false;
        	}
        }
        return true;
    }
};