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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> table;
        std::vector<int> ret;
        for(int i = 0; i < intervals.size(); i ++) {
        	table[intervals[i].start] = i;
        }

        for(int i = 0; i < intervals.size(); i++) {
        	map<int, int>::iterator it = table.lower_bound(intervals[i].end);
        	if(it != table.end()) {
        		ret.emplace_back(it->second);
        	} else {
        		ret.emplace_back(-1);
        	}
        }
        return ret;

    }
};