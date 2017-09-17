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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> ret;
        if(intervals.size() == 0) {
        	ret.push_back(newInterval);
        	return ret;
        }
        bool added = false;
        for(int i = 0; i < intervals.size(); i++) {
        	if(intervals[i].start > newInterval.end) {
        		if( !added ){
	        		ret.push_back(newInterval);
	        		added = true;
        		}
        		ret.push_back(intervals[i]);
        	} else if( intervals[i].end < newInterval.start) {
        		ret.push_back(intervals[i]);
        	} else {
        		if(intervals[i].start < newInterval.start) {
        			newInterval.start = intervals[i].start;
        		}
        		if(intervals[i].end > newInterval.end) {
        			newInterval.end = intervals[i].end;
        		}
        	}
        }
        if(!added) {
        	ret.push_back(newInterval);
        }

        return ret;
    }
};


// [[1,5],[6,8]]
// [5,6]