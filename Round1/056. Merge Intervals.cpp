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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
    	if(intervals.size() == 0) {
    		return ret;
    	}
        auto comp = [](Interval & a, Interval & b) {
        	return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), comp);

        Interval current = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
        	if(current.end >= intervals[i].start) {
        		current.end = max(current.end, intervals[i].end);
        	} else {
        		ret.emplace_back(current);
        		current = intervals[i];
        	}
        }
        ret.emplace_back(current);
        return ret;
    }
};